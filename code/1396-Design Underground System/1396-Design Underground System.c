/*
LeetCode 1396 - Design Underground System

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// An underground railway system is keeping track of customer travel times between different stations. They are using this data to calculate the average time it takes to travel from one station to another.

// Implement the UndergroundSystem class:

// void checkIn(int id, string stationName, int t)
// A customer with a card ID equal to id, checks in at the station stationName at time t.
// A customer can only be checked into one place at a time.
// void checkOut(int id, string stationName, int t)
// A customer with a card ID equal to id, checks out from the station stationName at time t.
// double getAverageTime(string startStation, string endStation)
// Returns the average time it takes to travel from startStation to endStation.
// The average time is computed from all the previous traveling times from startStation to endStation that happened directly, meaning a check in at startStation followed by a check out from endStation.
// The time it takes to travel from startStation to endStation may be different from the time it takes to travel from endStation to startStation.
// There will be at least one customer that has traveled from startStation to endStation before getAverageTime is called.
// You may assume all calls to the checkIn and checkOut methods are consistent. If a customer checks in at time t1 then checks out at time t2, then t1 < t2. All events happen in chronological order.



// Example 1:

// Input
// ["UndergroundSystem","checkIn","checkIn","checkIn","checkOut","checkOut","checkOut","getAverageTime","getAverageTime","checkIn","getAverageTime","checkOut","getAverageTime"]
// [[],[45,"Leyton",3],[32,"Paradise",8],[27,"Leyton",10],[45,"Waterloo",15],[27,"Waterloo",20],[32,"Cambridge",22],["Paradise","Cambridge"],["Leyton","Waterloo"],[10,"Leyton",24],["Leyton","Waterloo"],[10,"Waterloo",38],["Leyton","Waterloo"]]

// Output
// [null,null,null,null,null,null,null,14.00000,11.00000,null,11.00000,null,12.00000]

// Explanation
// UndergroundSystem undergroundSystem = new UndergroundSystem();
// undergroundSystem.checkIn(45, "Leyton", 3);
// undergroundSystem.checkIn(32, "Paradise", 8);
// undergroundSystem.checkIn(27, "Leyton", 10);
// undergroundSystem.checkOut(45, "Waterloo", 15);  // Customer 45 "Leyton" -> "Waterloo" in 15-3 = 12
// undergroundSystem.checkOut(27, "Waterloo", 20);  // Customer 27 "Leyton" -> "Waterloo" in 20-10 = 10
// undergroundSystem.checkOut(32, "Cambridge", 22); // Customer 32 "Paradise" -> "Cambridge" in 22-8 = 14
// undergroundSystem.getAverageTime("Paradise", "Cambridge"); // return 14.00000. One trip "Paradise" -> "Cambridge", (14) / 1 = 14
// undergroundSystem.getAverageTime("Leyton", "Waterloo");    // return 11.00000. Two trips "Leyton" -> "Waterloo", (10 + 12) / 2 = 11
// undergroundSystem.checkIn(10, "Leyton", 24);
// undergroundSystem.getAverageTime("Leyton", "Waterloo");    // return 11.00000
// undergroundSystem.checkOut(10, "Waterloo", 38);  // Customer 10 "Leyton" -> "Waterloo" in 38-24 = 14
// undergroundSystem.getAverageTime("Leyton", "Waterloo");    // return 12.00000. Three trips "Leyton" -> "Waterloo", (10 + 12 + 14) / 3 = 12
// Example 2:

// Input
// ["UndergroundSystem","checkIn","checkOut","getAverageTime","checkIn","checkOut","getAverageTime","checkIn","checkOut","getAverageTime"]
// [[],[10,"Leyton",3],[10,"Paradise",8],["Leyton","Paradise"],[5,"Leyton",10],[5,"Paradise",16],["Leyton","Paradise"],[2,"Leyton",21],[2,"Paradise",30],["Leyton","Paradise"]]

// Output
// [null,null,null,5.00000,null,null,5.50000,null,null,6.66667]

// Explanation
// UndergroundSystem undergroundSystem = new UndergroundSystem();
// undergroundSystem.checkIn(10, "Leyton", 3);
// undergroundSystem.checkOut(10, "Paradise", 8); // Customer 10 "Leyton" -> "Paradise" in 8-3 = 5
// undergroundSystem.getAverageTime("Leyton", "Paradise"); // return 5.00000, (5) / 1 = 5
// undergroundSystem.checkIn(5, "Leyton", 10);
// undergroundSystem.checkOut(5, "Paradise", 16); // Customer 5 "Leyton" -> "Paradise" in 16-10 = 6
// undergroundSystem.getAverageTime("Leyton", "Paradise"); // return 5.50000, (5 + 6) / 2 = 5.5
// undergroundSystem.checkIn(2, "Leyton", 21);
// undergroundSystem.checkOut(2, "Paradise", 30); // Customer 2 "Leyton" -> "Paradise" in 30-21 = 9
// undergroundSystem.getAverageTime("Leyton", "Paradise"); // return 6.66667, (5 + 6 + 9) / 3 = 6.66667


// Constraints:

// 1 <= id, t <= 10^6
// 1 <= stationName.length, startStation.length, endStation.length <= 10
// All strings consist of uppercase and lowercase English letters and digits.
// There will be at most 2 * 10^4 calls in total to checkIn, checkOut, and getAverageTime.
// Answers within 10^(-5) of the actual value will be accepted.

#define MAX_LEN 12

typedef struct {
    int id;
    char startName[MAX_LEN];
    int starttime;
    UT_hash_handle hh;
} StartInfo;

typedef struct {
    char stations[2 * MAX_LEN];
    int sum;
    int amount;
    UT_hash_handle hh;
} Table;


typedef struct {
    StartInfo *startInfo;
    Table *table;
} UndergroundSystem;


UndergroundSystem* undergroundSystemCreate() {
    UndergroundSystem *obj = (UndergroundSystem*)malloc(sizeof(UndergroundSystem));
    obj->startInfo = NULL;
    obj->table = NULL;
    return obj;
}

void undergroundSystemCheckIn(UndergroundSystem* obj, int id, char * stationName, int t) {
    StartInfo *pEntry = (StartInfo*)malloc(sizeof(StartInfo));
    pEntry->id = id;
    strcpy(pEntry->startName, stationName);
    pEntry->starttime = t;
    HASH_ADD_INT(obj->startInfo, id, pEntry);
}

void undergroundSystemCheckOut(UndergroundSystem* obj, int id, char * stationName, int t) {
    StartInfo *pEntry1 = NULL;
    HASH_FIND_INT(obj->startInfo, &id, pEntry1);
    if (pEntry1 != NULL) {
        int startTime = pEntry1->starttime;
        char stationInfo[2 * MAX_LEN];
        strcpy(stationInfo, pEntry1->startName);
        strcat(stationInfo, "_");
        strcat(stationInfo, stationName);
        Table *pEntry2 = NULL;
        HASH_FIND_STR(obj->table, stationInfo, pEntry2);
        if (pEntry2 == NULL) {
            pEntry2 = (Table*)malloc(sizeof(Table));
            memcpy(pEntry2->stations, stationInfo, strlen(stationInfo) + 1);
            pEntry2->amount = 1;
            pEntry2->sum = t - startTime;
            HASH_ADD_STR(obj->table, stations, pEntry2);
        } else {
            (pEntry2->amount) ++;
            pEntry2->sum += t - startTime;
        }
        HASH_DEL(obj->startInfo, pEntry1);
        free(pEntry1);
        pEntry1 = NULL;
    }
}

double undergroundSystemGetAverageTime(UndergroundSystem* obj, char * startStation, char * endStation) {
    char stationInfo[2 * MAX_LEN];
    strcpy(stationInfo, startStation);
    strcat(stationInfo, "_");
    strcat(stationInfo, endStation);
    printf("%s\n",stationInfo);
    Table *pEntry = NULL;
    HASH_FIND_STR(obj->table, stationInfo, pEntry);
    if (pEntry != NULL) {
        return (double)(pEntry->sum)/(pEntry->amount);
    }
    return -1;
}

void undergroundSystemFree(UndergroundSystem* obj) {
    StartInfo *tmp = NULL, *curr = NULL;
    HASH_ITER(hh, obj->startInfo, tmp, curr) {
        HASH_DEL(obj->startInfo, tmp);
        free(tmp);
    }
    free(obj->startInfo);
    Table *tmp_ = NULL, *curr_ = NULL;
    HASH_ITER(hh, obj->table, tmp_, curr_) {
        HASH_DEL(obj->table, tmp_);
        free(tmp_);
    }
    free(obj->table);
}

/**
 * Your UndergroundSystem struct will be instantiated and called as such:
 * UndergroundSystem* obj = undergroundSystemCreate();
 * undergroundSystemCheckIn(obj, id, stationName, t);

 * undergroundSystemCheckOut(obj, id, stationName, t);

 * double param_3 = undergroundSystemGetAverageTime(obj, startStation, endStation);

 * undergroundSystemFree(obj);
*/
