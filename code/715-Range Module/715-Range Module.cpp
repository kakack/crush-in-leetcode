// A Range Module is a module that tracks ranges of numbers. Design a data structure to track the ranges represented as half-open intervals and query about them.

// A half-open interval [left, right) denotes all the real numbers x where left <= x < right.

// Implement the RangeModule class:

// RangeModule() Initializes the object of the data structure.
// void addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval. Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval [left, right) that are not already tracked.
// boolean queryRange(int left, int right) Returns true if every real number in the interval [left, right) is currently being tracked, and false otherwise.
// void removeRange(int left, int right) Stops tracking every real number currently being tracked in the half-open interval [left, right).
 

// Example 1:

// Input
// ["RangeModule", "addRange", "removeRange", "queryRange", "queryRange", "queryRange"]
// [[], [10, 20], [14, 16], [10, 14], [13, 15], [16, 17]]
// Output
// [null, null, null, true, false, true]

// Explanation
// RangeModule rangeModule = new RangeModule();
// rangeModule.addRange(10, 20);
// rangeModule.removeRange(14, 16);
// rangeModule.queryRange(10, 14); // return True,(Every number in [10, 14) is being tracked)
// rangeModule.queryRange(13, 15); // return False,(Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
// rangeModule.queryRange(16, 17); // return True, (The number 16 in [16, 17) is still being tracked, despite the remove operation)
 

// Constraints:

// 1 <= left < right <= 10^9
// At most 10^4 calls will be made to addRange, queryRange, and removeRange.

class RangeModule {
public:
    RangeModule() {}
    
    void addRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it != intervals.begin()) {
            auto start = prev(it);
            if (start->second >= right) {
                return;
            }
            if (start->second >= left) {
                left = start->first;
                intervals.erase(start);
            }
        }
        while (it != intervals.end() && it->first <= right) {
            right = max(right, it->second);
            it = intervals.erase(it);
        }
        intervals[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it == intervals.begin()) {
            return false;
        }
        it = prev(it);
        return right <= it->second;
    }
    
    void removeRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it != intervals.begin()) {
            auto start = prev(it);
            if (start->second >= right) {
                int ri = start->second;
                if (start->first == left) {
                    intervals.erase(start);
                }
                else {
                    start->second = left;
                }
                if (right != ri) {
                    intervals[right] = ri;
                }
                return;
            }
            else if (start->second > left) {
                start->second = left;
            }
        }
        while (it != intervals.end() && it->first < right) {
            if (it->second <= right) {
                it = intervals.erase(it);
            }
            else {
                intervals[right] = it->second;
                intervals.erase(it);
                break;
            }
        }
    }

private:
    map<int, int> intervals;
};


/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */