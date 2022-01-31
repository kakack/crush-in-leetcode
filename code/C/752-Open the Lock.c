/*
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.



Example 1:

Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
Example 2:

Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation:
We can turn the last wheel in reverse to move from "0000" -> "0009".
Example 3:

Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation:
We can't reach the target without getting stuck.
Example 4:

Input: deadends = ["0000"], target = "8888"
Output: -1


Constraints:

1 <= deadends.length <= 500
deadends[i].length == 4
target.length == 4
target will not be in the list deadends.
target and deadends[i] consist of digits only.
*/

struct HashTable {
    char str[5];
    UT_hash_handle hh;
};

struct  Node {
    char str[5];
    int val;
};

char num_prev(char x) {
    return (x == '0' ? '9' : x - 1);
}

char num_next(char x) {
    return (x == '9' ? '0' : x + 1);
}

char** getNextStatus(char* status, int* retSize) {
    char** ret = malloc(sizeof(char*) * 8);
    *retSize = 0;
    for (int i = 0; i < 4; i ++) {
        char num = status[i];
        status[i] = num_prev(num);
        ret[(*retSize)] = malloc(sizeof(char) * 5);
        strcpy(ret[(*retSize) ++], status);
        status[i] = num_next(num);
        ret[(*retSize)] = malloc(sizeof(char) * 5);
        strcpy(ret[(*retSize) ++], status);
        status[i] = num;
    }
    return ret;
}

int openLock(char** deadends, int deadendsSize, char* target) {
    char str_0[5] = "0000";
    if (strcmp(str_0, target) == 0) {
        return 0;
    }
    struct HashTable* dead = NULL;
    struct HashTable* tmp;
    for (int i = 0; i < deadendsSize; i ++) {
        HASH_FIND(hh, dead, deadends[i], sizeof(char) * 5, tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(struct HashTable));
            strcpy(tmp->str, deadends[i]);
            HASH_ADD(hh, dead, str, sizeof(char) * 5, tmp);
        }
    }
    HASH_FIND(hh, dead, str_0, sizeof(char) * 5, tmp);
    if (tmp != NULL) {
        return -1;
    }

    struct Node queue[10001];
    int head = 0, tail = 0;
    strcpy(queue[tail].str, str_0);
    queue[tail++].val = 0;

    struct HashTable* seen = NULL;
    tmp = malloc(sizeof(struct HashTable));
    strcpy(tmp->str, str_0);
    HASH_ADD(hh, seen, str, sizeof(char) * 5, tmp);
    
    while (head < tail) {
        char* status = queue[head].str;
        int step = queue[head ++].val;
        int nextStatusSize;
        char** nextStatus = getNextStatus(status, &nextStatusSize);
        for (int i = 0; i < nextStatusSize; i ++) {
            struct HashTable *tmp1, *tmp2;
            HASH_FIND(hh, dead, nextStatus[i], sizeof(char) * 5, tmp1);
            HASH_FIND(hh, seen, nextStatus[i], sizeof(char) * 5, tmp2);
            if (tmp1 == NULL && tmp2 == NULL) {
                if (strcmp(nextStatus[i], target) == 0) {
                    return step + 1;
                }
                strcpy(queue[tail].str, nextStatus[i]);
                queue[tail ++].val = step + 1;
                tmp = malloc(sizeof(struct HashTable));
                strcpy(tmp->str, nextStatus[i]);
                HASH_ADD(hh, seen, str, sizeof(char) * 5, tmp);
            }
        }
    }
    return -1;
}