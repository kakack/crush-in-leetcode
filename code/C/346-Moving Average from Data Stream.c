// Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

// Implement the MovingAverage class:

// MovingAverage(int size) Initializes the object with the size of the window size.
// double next(int val) Returns the moving average of the last size values of the stream.
//  

// Example 1:

// Input
// ["MovingAverage", "next", "next", "next", "next"]
// [[3], [1], [10], [3], [5]]
// Output
// [null, 1.0, 5.5, 4.66667, 6.0]

// Explanation
// MovingAverage movingAverage = new MovingAverage(3);
// movingAverage.next(1); // return 1.0 = 1 / 1
// movingAverage.next(10); // return 5.5 = (1 + 10) / 2
// movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
// movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3
//  

// Constraints:

// 1 <= size <= 1000
// -10^5 <= val <= 10^5
// At most 10^4 calls will be made to next.

typedef struct {
    int *queue;
    int count, head, tail, amount;
    long sum;
} MovingAverage;


MovingAverage* movingAverageCreate(int size) {
    MovingAverage* tmp = (MovingAverage *)malloc(sizeof(MovingAverage));
    tmp->queue = (int *)malloc(sizeof(int) * 10000);
    tmp->head = 0;
    tmp->tail = 0;
    tmp->count = 0;
    tmp->sum = 0;
    tmp->amount = size;
    return tmp;
}

double movingAverageNext(MovingAverage* obj, int val) {
    if (obj->count == obj->amount) {
        obj->sum -= obj->queue[obj->head ++];
    } else {
        obj->count ++;
    }
    obj->sum += val;
    obj->queue[obj->tail ++] = val;
    return obj->sum * 1.0 / obj->count;
}

void movingAverageFree(MovingAverage* obj) {
    free(obj->queue);
    free(obj);
}

/**
 * Your MovingAverage struct will be instantiated and called as such:
 * MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);
 
 * movingAverageFree(obj);
*/