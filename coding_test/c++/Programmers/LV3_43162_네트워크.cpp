#include <iostream>
#include <string>
#include <vector>

using namespace std;

int parents[201] = { 0 };

int find_parent(int a) {
    if (parents[a] == a) return parents[a];
    return parents[a] = find_parent(parents[a]);
}

void make_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a == b) return;
    if (a > b) parents[a] = b;
    else parents[b] = a;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < 201; i++) parents[i] = i;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (computers[i][j] == 0) continue;
            make_parent(i, j);
        }
    }
    
    answer = n;
    for (int i = 0; i < n; i++) {
        if (parents[i] != i) answer--;
    }
    
    return answer;
}