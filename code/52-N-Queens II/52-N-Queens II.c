// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

 

// Example 1:


// Input: n = 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
// Example 2:

// Input: n = 1
// Output: 1
 

// Constraints:

// 1 <= n <= 9

struct hashTable {
    int key;
    UT_hash_handle hh;
};

struct hashTable* find(struct hashTable** hashtable, int ikey) {
    struct hashTable* tmp = NULL;
    HASH_FIND_INT(*hashtable, &ikey, tmp);
    return tmp;
}

void insert(struct hashTable** hashtable, int ikey) {
    struct hashTable* tmp = NULL;
    HASH_FIND_INT(*hashtable, &ikey, tmp);
    if (tmp == NULL) {
        tmp = malloc(sizeof(struct hashTable));
        tmp->key = ikey;
        HASH_ADD_INT(*hashtable, key, tmp);
    }
}

void erase(struct hashTable** hashtable, int ikey) {
    struct hashTable* tmp = NULL;
    HASH_FIND_INT(*hashtable, &ikey, tmp);
    if (tmp != NULL) {
        HASH_DEL(*hashtable, tmp);
        free(tmp);
    }
}

struct hashTable *columns, *diagonals1, *diagonals2;

int backtrack(int n, int row) {
    if (row == n) {
        return 1;
    } else {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (find(&columns, i) != NULL) {
                continue;
            }
            int diagonal1 = row - i;
            if (find(&diagonals1, diagonal1) != NULL) {
                continue;
            }
            int diagonal2 = row + i;
            if (find(&diagonals2, diagonal2) != NULL) {
                continue;
            }
            insert(&columns, i);
            insert(&diagonals1, diagonal1);
            insert(&diagonals2, diagonal2);
            count += backtrack(n, row + 1);
            erase(&columns, i);
            erase(&diagonals1, diagonal1);
            erase(&diagonals2, diagonal2);
        }
        return count;
    }
}

int totalNQueens(int n) {
    columns = diagonals1 = diagonals2 = NULL;
    return backtrack(n, 0);
}
