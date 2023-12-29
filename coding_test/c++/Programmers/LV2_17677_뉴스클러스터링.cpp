#include <string>
#include <cmath>
#include <map>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    map<string, int> map1;
    map<string, int> map2;
    set<string> arr;
    
    for (int i = 0; i < str1.size() - 1; i++) {
        if (!isalpha(str1[i]) || !isalpha(str1[i + 1])) continue;
        string sub1 = str1.substr(i, 2);
        for (char &c : sub1) c = tolower(c);
        map1[sub1]++;
        arr.insert(sub1);
    }
    for (int i = 0; i < str2.size() - 1; i++) {
        if (!isalpha(str2[i]) || !isalpha(str2[i + 1])) continue;
        string sub = str2.substr(i, 2);
        for (char& c: sub) c = tolower(c);
        map2[sub]++;
        arr.insert(sub);
    }
    
    double temp1 = 0;
    double temp2 = 0;
    
    if (arr.size() == 0) return 65536;
    
    for (set<string> :: iterator it = arr.begin(); it != arr.end(); it++) {
        string sub = *it;
        if (map1.find(sub) != map1.end()) {
            if (map2.find(sub) != map2.end()) {
                temp1 += min(map1[sub], map2[sub]);
                temp2 += max(map1[sub], map2[sub]);
            }
            else temp2 += map1[sub];
        }
        else {
            temp2 += map2[sub];
        }
    }
    
    answer = (temp1 / temp2) * 65536;
    
    return answer;
}