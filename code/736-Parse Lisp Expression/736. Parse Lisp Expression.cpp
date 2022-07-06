// You are given a string expression representing a Lisp-like expression to return the integer value of.

// The syntax for these expressions is given as follows.

// An expression is either an integer, let expression, add expression, mult expression, or an assigned variable. Expressions always evaluate to a single integer.
// (An integer could be positive or negative.)
// A let expression takes the form "(let v1 e1 v2 e2 ... vn en expr)", where let is always the string "let", then there are one or more pairs of alternating variables and expressions, meaning that the first variable v1 is assigned the value of the expression e1, the second variable v2 is assigned the value of the expression e2, and so on sequentially; and then the value of this let expression is the value of the expression expr.
// An add expression takes the form "(add e1 e2)" where add is always the string "add", there are always two expressions e1, e2 and the result is the addition of the evaluation of e1 and the evaluation of e2.
// A mult expression takes the form "(mult e1 e2)" where mult is always the string "mult", there are always two expressions e1, e2 and the result is the multiplication of the evaluation of e1 and the evaluation of e2.
// For this question, we will use a smaller subset of variable names. A variable starts with a lowercase letter, then zero or more lowercase letters or digits. Additionally, for your convenience, the names "add", "let", and "mult" are protected and will never be used as variable names.
// Finally, there is the concept of scope. When an expression of a variable name is evaluated, within the context of that evaluation, the innermost scope (in terms of parentheses) is checked first for the value of that variable, and then outer scopes are checked sequentially. It is guaranteed that every expression is legal. Please see the examples for more details on the scope.
 

// Example 1:

// Input: expression = "(let x 2 (mult x (let x 3 y 4 (add x y))))"
// Output: 14
// Explanation: In the expression (add x y), when checking for the value of the variable x,
// we check from the innermost scope to the outermost in the context of the variable we are trying to evaluate.
// Since x = 3 is found first, the value of x is 3.
// Example 2:

// Input: expression = "(let x 3 x 2 x)"
// Output: 2
// Explanation: Assignment in let statements is processed sequentially.
// Example 3:

// Input: expression = "(let x 1 y 2 x (add x y) (add x y))"
// Output: 5
// Explanation: The first (add x y) evaluates as 3, and is assigned to x.
// The second (add x y) evaluates as 3+2 = 5.
 

// Constraints:

// 1 <= expression.length <= 2000
// There are no leading or trailing spaces in expression.
// All tokens are separated by a single space in expression.
// The answer and all intermediate calculations of that answer are guaranteed to fit in a 32-bit integer.
// The expression is guaranteed to be legal and evaluate to an integer.

enum ExprStatus {
    VALUE = 0, // 初始状态
    NONE,      // 表达式类型未知
    LET,       // let 表达式
    LET1,      // let 表达式已经解析了 vi 变量
    LET2,      // let 表达式已经解析了最后一个表达式 expr
    ADD,       // add 表达式
    ADD1,      // add 表达式已经解析了 e1 表达式
    ADD2,      // add 表达式已经解析了 e2 表达式
    MULT,      // mult 表达式
    MULT1,     // mult 表达式已经解析了 e1 表达式
    MULT2,     // mult 表达式已经解析了 e2 表达式
    DONE       // 解析完成
};

struct Expr {
    ExprStatus status;
    string var; // let 的变量 vi
    int value; // VALUE 状态的数值，或者 LET2 状态最后一个表达式的数值
    int e1, e2; // add 或 mult 表达式的两个表达式 e1 和 e2 的数值

    Expr(ExprStatus s) {
        status = s;
    }
};

class Solution {
private:
    unordered_map<string, vector<int>> scope;

public:
    int evaluate(string expression) {
        vector<vector<string>> vars;
        int start = 0, n = expression.size();
        stack<Expr> s;
        Expr cur(VALUE);
        while (start < n) {
            if (expression[start] == ' ') {
                start++; // 去掉空格
                continue;
            }
            if (expression[start] == '(') {
                start++; // 去掉左括号
                s.push(cur);
                cur = Expr(NONE);
                continue;
            }
            string token;
            if (expression[start] == ')') { // 本质上是把表达式转成一个 token
                start++; // 去掉右括号
                if (cur.status == LET2) {
                    token = to_string(cur.value);
                    for (auto var : vars.back()) { // 清除作用域
                        scope[var].pop_back();
                    }
                    vars.pop_back();
                } else if (cur.status == ADD2) {
                    token = to_string(cur.e1 + cur.e2);
                } else {
                    token = to_string(cur.e1 * cur.e2);
                }
                cur = s.top(); // 获取上层状态
                s.pop();
            } else {
                while (start < n && expression[start] != ' ' && expression[start] != ')') {
                    token.push_back(expression[start]);
                    start++;
                }
            }
            switch (cur.status) {
                case VALUE:
                    cur.value = stoi(token);
                    cur.status = DONE;
                    break;
                case NONE:
                    if (token == "let") {
                        cur.status = LET;
                        vars.emplace_back(); // 记录该层作用域的所有变量, 方便后续的清除
                    } else if (token == "add") {
                        cur.status = ADD;
                    } else if (token == "mult") {
                        cur.status = MULT;
                    }
                    break;
                case LET:
                    if (expression[start] == ')') { // let 表达式的最后一个 expr 表达式
                        cur.value = calculateToken(token);
                        cur.status = LET2;
                    } else {
                        cur.var = token;
                        vars.back().push_back(token); // 记录该层作用域的所有变量, 方便后续的清除
                        cur.status = LET1;
                    }
                    break;
                case LET1:
                    scope[cur.var].push_back(calculateToken(token));
                    cur.status = LET;
                    break;
                case ADD:
                    cur.e1 = calculateToken(token);
                    cur.status = ADD1;
                    break;
                case ADD1:
                    cur.e2 = calculateToken(token);
                    cur.status = ADD2;
                    break;
                case MULT:
                    cur.e1 = calculateToken(token);
                    cur.status = MULT1;
                    break;
                case MULT1:
                    cur.e2 = calculateToken(token);
                    cur.status = MULT2;
                    break;
            }
        }
        return cur.value;
    }

    int calculateToken(const string &token) {
        if (islower(token[0])) {
            return scope[token].back();
        } else {
            return stoi(token);
        }
    }
};
