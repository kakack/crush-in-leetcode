/*
You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.



Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination:
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination:
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination:
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"


Constraints:

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.
*/

struct HashTable {
    int key;
    int len;
    int* vec;
    UT_hash_handle hh;
};

int cmp(int* a, int* b) {
    return *b - *a;
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b, *b = tmp;
}

struct DisjointSetUnion {
    int *f, *rank;
    int n;
};

void init(struct DisjointSetUnion* obj, int _n) {
    obj->n = _n;
    obj->rank = malloc(sizeof(int) * obj->n);
    memset(obj->rank, 0, sizeof(int) * obj->n);
    obj->f = malloc(sizeof(int) * obj->n);
    for (int i = 0; i < obj->n; i ++) {
        obj->f[i] = i;
    }
}

int find(struct DisjointSetUnion* obj, int x) {
    if (obj->f[x] == x) {
        return x;
    } else {
        return obj->f[x] = find(obj, obj->f[x]);
    }
}

void unionSet(struct DisjointSetUnion* obj, int x, int y) {
    int fx = find(obj, x), fy = find(obj, y);
    if (fx == fy) {
        return;
    }
    if (obj->rank[fx] < obj->rank[fy]) {
        swap(&fx, &fy);
    }
    obj->rank[fx] += obj->rank[fy];
    obj->f[fy] = fx;
}

char* smallestStringWithSwaps(char* s, int** pairs, int pairsSize, int* pairsColSize) {
    int n = strlen(s);
    struct DisjointSetUnion* dsu = malloc(sizeof(struct DisjointSetUnion));
    init(dsu, n);
    for (int i = 0; i < pairsSize; i++) {
        unionSet(dsu, pairs[i][0], pairs[i][1]);
    }
    struct HashTable *mp = NULL, *iter, *tmp;
    for (int i = 0; i < n; i++) {
        int ikey = find(dsu, i);
        HASH_FIND_INT(mp, &ikey, tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(struct HashTable));
            tmp->key = ikey;
            tmp->len = 1;
            tmp->vec = NULL;
            HASH_ADD_INT(mp, key, tmp);
        } else {
            tmp->len++;
        }
    }
    HASH_ITER(hh, mp, iter, tmp) {
        iter->vec = malloc(sizeof(int) * iter->len);
        iter->len = 0;
    }
    for (int i = 0; i < n; i++) {
        int ikey = find(dsu, i);
        HASH_FIND_INT(mp, &ikey, tmp);
        tmp->vec[tmp->len++] = s[i];
    }
    HASH_ITER(hh, mp, iter, tmp) {
        qsort(iter->vec, iter->len, sizeof(int), cmp);
    }

    for (int i = 0; i < n; i++) {
        int ikey = find(dsu, i);
        HASH_FIND_INT(mp, &ikey, tmp);
        s[i] = tmp->vec[--tmp->len];
    }
    return s;
}
