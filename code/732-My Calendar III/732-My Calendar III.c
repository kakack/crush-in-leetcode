A k-booking happens when k events have some non-empty intersection (i.e., there is some time that is common to all k events.)

// You are given some events [start, end), after each given event, return an integer k representing the maximum k-booking between all the previous events.

// Implement the MyCalendarThree class:

// MyCalendarThree() Initializes the object.
// int book(int start, int end) Returns an integer k representing the largest integer such that there exists a k-booking in the calendar.
 

// Example 1:

// Input
// ["MyCalendarThree", "book", "book", "book", "book", "book", "book"]
// [[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
// Output
// [null, 1, 1, 2, 3, 3, 3]

// Explanation
// MyCalendarThree myCalendarThree = new MyCalendarThree();
// myCalendarThree.book(10, 20); // return 1, The first event can be booked and is disjoint, so the maximum k-booking is a 1-booking.
// myCalendarThree.book(50, 60); // return 1, The second event can be booked and is disjoint, so the maximum k-booking is a 1-booking.
// myCalendarThree.book(10, 40); // return 2, The third event [10, 40) intersects the first event, and the maximum k-booking is a 2-booking.
// myCalendarThree.book(5, 15); // return 3, The remaining events cause the maximum K-booking to be only a 3-booking.
// myCalendarThree.book(5, 10); // return 3
// myCalendarThree.book(25, 55); // return 3
 

// Constraints:

// 0 <= start < end <= 10^9
// At most 400 calls will be made to book.

typedef struct {
    int idx;
    int val;
    UT_hash_handle hh;
} hashCnt;

int id_sort(hashCnt *a, hashCnt *b) {
    return (a->idx - b->idx);
}

typedef struct {
    hashCnt *cnt;
} MyCalendarThree;


MyCalendarThree* myCalendarThreeCreate() {
    MyCalendarThree* obj = malloc(sizeof(MyCalendarThree));
    obj->cnt = NULL;
    return obj;
}

int myCalendarThreeBook(MyCalendarThree* obj, int start, int end) {
    int ans = 0;
    int maxBook = 0;
    hashCnt *pEntry = NULL, *pEntry_ = NULL, *iter, *tmp;
    HASH_FIND_INT(obj->cnt, &start, pEntry);
    if (pEntry == NULL) {
        pEntry = (hashCnt*)malloc(sizeof(hashCnt));
        pEntry->idx = start;
        pEntry->val = 1;
        HASH_ADD_INT(obj->cnt, idx, pEntry);
    } else {
        pEntry->val ++;
    }
    HASH_FIND_INT(obj->cnt, &end, pEntry_);
    if (pEntry_ == NULL) {
        pEntry_ = (hashCnt*)malloc(sizeof(hashCnt));
        pEntry_->idx = end;
        pEntry_->val = -1;
        HASH_ADD_INT(obj->cnt, idx, pEntry_);
    } else {
        pEntry_->val --;
    }
    HASH_SORT(obj->cnt, id_sort);
    HASH_ITER(hh, obj->cnt, iter, tmp) {
        maxBook += iter->val;
        ans = fmax(ans, maxBook);
    }
    return ans;
}

void myCalendarThreeFree(MyCalendarThree* obj) {
    hashCnt  *iter, *tmp;
    HASH_ITER(hh, obj->cnt, iter, tmp) {
        HASH_DEL(obj->cnt, iter);
        free(iter);
    }
    free(obj->cnt);
    free(obj);
}

/**
 * Your MyCalendarThree struct will be instantiated and called as such:
 * MyCalendarThree* obj = myCalendarThreeCreate();
 * int param_1 = myCalendarThreeBook(obj, start, end);
 
 * myCalendarThreeFree(obj);
*/