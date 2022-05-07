// A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

// Suppose we need to investigate a mutation from a gene string start to a gene string end where one mutation is defined as one single character changed in the gene string.

// For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
// There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

// Given the two gene strings start and end and the gene bank bank, return the minimum number of mutations needed to mutate from start to end. If there is no such a mutation, return -1.

// Note that the starting point is assumed to be valid, so it might not be included in the bank.

 

// Example 1:

// Input: start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
// Output: 1
// Example 2:

// Input: start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
// Output: 2
// Example 3:

// Input: start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
// Output: 3
 

// Constraints:

// start.length == 8
// end.length == 8
// 0 <= bank.length <= 10
// bank[i].length == 8
// start, end, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].

typedef struct {
    char key[16];
    UT_hash_handle hh;
} HashItem;

bool hashInsert(HashItem ** obj, const char * str) {
    HashItem * pEntry = (HashItem *)malloc(sizeof(HashItem));
    strcpy(pEntry->key, str);
    HASH_ADD_STR(*obj, key, pEntry);
    return true;
}

bool hashFind(HashItem ** obj, const char * str) {
    HashItem * pEntry = NULL;
    HASH_FIND_STR(*obj, str, pEntry);
    if (NULL == pEntry) {
        return false;
    } else {
        return true;
    }
}

void hashFree(HashItem ** obj) {
    HashItem *curr, *tmp;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    } 
}


int minMutation(char * start, char * end, char ** bank, int bankSize){
    HashItem *cnt = NULL;
    HashItem *visited = NULL;
    const char keys[4] = {'A', 'C', 'G', 'T'}; 
    if (strcmp(start, end) == 0) {
        return 0;
    }       
    for (int i = 0; i < bankSize; i++) {
        hashInsert(&cnt, bank[i]);
    }
    if (!hashFind(&cnt, end)) {
        return -1;
    }
    char ** queue = (char **)malloc(sizeof(char *) * bankSize);
    int head = 0;
    int tail = 0;
    queue[tail] = (char *)malloc(sizeof(char) * 16);
    strcpy(queue[tail], start);
    hashInsert(&visited, start);
    tail++;
    int step = 1;
    while (head != tail) {
        int sz = tail - head;
        for (int i = 0; i < sz; i++) {
            char * curr = queue[head++];
            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 4; k++) {
                    if (keys[k] != curr[j]) {
                        char *next = (char *)malloc(sizeof(char) * 16);
                        strcpy(next, curr);
                        next[j] = keys[k];
                        if (!hashFind(&visited, next) && hashFind(&cnt, next)) {
                            if (strcmp(next, end) == 0) {
                                while (head != tail) {
                                    free(queue[head++]);
                                }
                                hashFree(&cnt);
                                hashFree(&visited);
                                free(queue);
                                return step;
                            }
                            queue[tail++] = next;
                            hashInsert(&visited, next);
                        } else {
                            free(next);
                        }
                    }
                }
            }
            free(curr);
        }
        step++;
    }
    hashFree(&cnt);
    hashFree(&visited);
    free(queue);
    return -1;
}