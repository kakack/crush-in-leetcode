// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

 

// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4
// Example 2:

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30
// Example 3:

// Input: piles = [30,11,23,4,20], h = 6
// Output: 23
 

// Constraints:

// 1 <= piles.length <= 10^4
// piles.length <= h <= 10^9
// 1 <= piles[i] <= 10^9

class Solution {
private:
    long getTime(const vector<int>& piles, int speed) {
        long time = 0;
        for (int i = 0; i < piles.size(); i ++) {
            time += (piles[i] + speed - 1) / speed;
        }
        return time;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 0;
        for (int i = 0; i < piles.size(); i ++) {
            high = max(high, piles[i]);
        }
        int k = high;
        while (low < high) {
            int speed = (high + low) / 2;
            long time = getTime(piles, speed);
            if (time <= h) {
                k = speed;
                high = speed;
            } else {
                low = speed + 1;
            }
        }
        return k;
    }
};