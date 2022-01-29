// You are given an m x n grid rooms initialized with these three possible values.

// -1 A wall or an obstacle.
// 0 A gate.
// INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
// Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

//  

// Example 1:


// Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
// Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
// Example 2:

// Input: rooms = [[-1]]
// Output: [[-1]]
//  

// Constraints:

// m == rooms.length
// n == rooms[i].length
// 1 <= m, n <= 250
// rooms[i][j] is -1, 0, or 2^31 - 1.


typedef struct {
    int x;
    int y;
} Position;

void wallsAndGates(int** rooms, int roomsSize, int* roomsColSize){
    const int WALL = -1;
    const int DOOR = 0;
    const int INF = 2147483647;
    const int dirs[4][2] = {
        {1, 0},
        {-1, 0},
        {0, -1},
        {0, 1},
    };

    int m = roomsSize;
    int n = roomsColSize[0];
    Position queue[70000];
    memset(queue, 0, 70000 * sizeof(Position));
    int head = 0, tail = 0;
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            if (rooms[i][j] == DOOR) {
                queue[tail].x = i;
                queue[tail ++].y = j;
            }
        }
    }
    while (head < tail) {
        Position tmp = queue[head ++];
        for (int i = 0; i < 4; i ++) {
            Position newPos;
            newPos.x = tmp.x + dirs[i][0];
            newPos.y = tmp.y + dirs[i][1];
            if (newPos.x < 0 || newPos.x >= m || newPos.y < 0 || newPos.y >= n || rooms[newPos.x][newPos.y] != INF) {
                continue;
            }
            rooms[newPos.x][newPos.y] = rooms[tmp.x][tmp.y] + 1;
            queue[tail].x = newPos.x;
            queue[tail ++].y = newPos.y;
        }
    }
}