// Design a logger system that receives a stream of messages along with their timestamps. Each unique message should only be printed at most every 10 seconds (i.e. a message printed at timestamp t will prevent other identical messages from being printed until timestamp t + 10).

// All messages will come in chronological order. Several messages may arrive at the same timestamp.

// Implement the Logger class:

// Logger() Initializes the logger object.
// bool shouldPrintMessage(int timestamp, string message) Returns true if the message should be printed in the given timestamp, otherwise returns false.
//  

// Example 1:

// Input
// ["Logger", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage"]
// [[], [1, "foo"], [2, "bar"], [3, "foo"], [8, "bar"], [10, "foo"], [11, "foo"]]
// Output
// [null, true, true, false, false, false, true]

// Explanation
// Logger logger = new Logger();
// logger.shouldPrintMessage(1, "foo");  // return true, next allowed timestamp for "foo" is 1 + 10 = 11
// logger.shouldPrintMessage(2, "bar");  // return true, next allowed timestamp for "bar" is 2 + 10 = 12
// logger.shouldPrintMessage(3, "foo");  // 3 < 11, return false
// logger.shouldPrintMessage(8, "bar");  // 8 < 12, return false
// logger.shouldPrintMessage(10, "foo"); // 10 < 11, return false
// logger.shouldPrintMessage(11, "foo"); // 11 >= 11, return true, next allowed timestamp for "foo" is 11 + 10 = 21
//  

// Constraints:

// 0 <= timestamp <= 109
// Every timestamp will be passed in non-decreasing order (chronological order).
// 1 <= message.length <= 30
// At most 104 calls will be made to shouldPrintMessage.

typedef struct {
    char* msg;
    int time;
    UT_hash_handle hh;
} HashItem;

typedef struct {
    HashItem * msgMap;    
} Logger;


Logger* loggerCreate() {
    Logger* obj = (Logger*)malloc(sizeof(Logger));
    obj->msgMap = NULL;
    return obj;
}

bool loggerShouldPrintMessage(Logger* obj, int timestamp, char * message) {
    HashItem *pEntry = NULL;
    HASH_FIND_STR(obj->msgMap, message, pEntry);
    if (pEntry == NULL) {
        pEntry = (HashItem*)malloc(sizeof(HashItem));
        pEntry->msg = message;
        pEntry->time = timestamp;
        HASH_ADD_STR(obj->msgMap, msg, pEntry);
        return true;
    } else {
        if (timestamp - pEntry->time >= 10) {
            pEntry->time = timestamp;
            return true;
        } else {
            return false;
        }
    }
}

void loggerFree(Logger* obj) {
    HashItem *iter, *cur;
    HASH_ITER(hh, obj->msgMap, iter, cur) {
        HASH_DEL(obj->msgMap, iter);
        free(iter);
    }
    free(obj->msgMap);
    free(obj);
}

/**
 * Your Logger struct will be instantiated and called as such:
 * Logger* obj = loggerCreate();
 * bool param_1 = loggerShouldPrintMessage(obj, timestamp, message);
 
 * loggerFree(obj);
*/
