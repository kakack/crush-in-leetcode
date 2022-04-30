/*
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
 

Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj consist of lower case English letters and digits.

*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    char *x;
    char *y;
    double z;
    UT_hash_handle hh;
} Hash;

Hash *hash;

Hash* derive(Hash *p, double *t) {
    *t = 1;
    while (strcmp(p->x, p->y)) {
        *t *= p->z;
        char *s = p->y;
        HASH_FIND(hh, hash, s, strlen(s), p);
    }
    return p;
}

void _add(char *x, char *y, double z) {
    Hash *p1, *p2;
    HASH_FIND(hh, hash, x, strlen(x), p1);
    HASH_FIND(hh, hash, y, strlen(y), p2);
    if (p1 && p2) {
        //x、y已经出现过，若它们无联系，那么将他们合并关系
        double tx, ty;
        p1 = derive(p1, &tx);
        p2 = derive(p2, &ty);
        if (strcmp(p1->x, p2->x)) {
            p1->y = p2->x;
            p1->z = ty*z/tx;
        }
    } else if (p1) {
        double tx;
        p1 = derive(p1, &tx);
        Hash *p = malloc(sizeof(Hash));
        p->x = y; 
        p->y = p1->x;
        p->z = tx/z;
        HASH_ADD_STR(hash, x, p);
    } else if (p2) {
        double ty;
        p2 = derive(p2, &ty);
        Hash *p = malloc(sizeof(Hash));
        p->x = x;
        p->y = p2->x;
        p->z = z/ty;
        HASH_ADD_STR(hash, x, p);
    } else {
        p1 = malloc(sizeof(Hash));
        p2 = malloc(sizeof(Hash));
        p1->x = x;
        p1->y = y;
        p1->z = z;
        HASH_ADD_STR(hash, x, p1);
        p2->x = y;
        p2->y = y;
        p2->z = 1;
        HASH_ADD_STR(hash, x, p2);
    }
}

double _div(char *x, char *y) {
    Hash *p1, *p2;
    HASH_FIND(hh, hash, x, strlen(x), p1);
    HASH_FIND(hh, hash, y, strlen(y), p2);
    if (p1 && p2) {
        double tx, ty;
        p1 = derive(p1, &tx);
        p2 = derive(p2, &ty);
        if (strcmp(p1->x, p2->x) == 0) {
            return tx/ty;
        }
    } 
    return -1.0;
}

double* calcEquation(char *** equations, int equationsSize, int* equationsColSize, double* values, int valuesSize, char *** queries, int queriesSize, int* queriesColSize, int* returnSize){
    hash = NULL;
    for (int i=0; i<equationsSize; ++i) {
        _add(equations[i][0], equations[i][1], values[i]);
    }
    double *res = malloc(sizeof(double) * queriesSize);
    for (int i=0; i<queriesSize; ++i) {
        res[i] = _div(queries[i][0], queries[i][1]);
    }
    *returnSize = queriesSize;
    return res;
}
