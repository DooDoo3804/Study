#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 위부터 시계방향
int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


vector<int> solution(string command) {
    vector<int> answer(2);
    answer[0] = 0;
    answer[1] = 0;
    int direction = 0;
    for (auto cc : command) {
        if (cc == 'R') direction = (direction == 3) ? 0 : direction + 1;
        else if (cc == 'L') direction = (direction == 0) ? 3 : direction - 1;
        else if (cc == 'G') {
            answer[1] += directions[direction][1];
            answer[0] += directions[direction][0];
        }
        else if (cc == 'B') {
            answer[1] -= directions[direction][1];
            answer[0] -= directions[direction][0];}
    }
    return answer;
}