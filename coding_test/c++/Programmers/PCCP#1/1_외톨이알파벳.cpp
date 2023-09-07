#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int check_alpha[26] = { 0 };
int visited[2600] ={ 0 };

bool check (int index, string &input_string) {
    char alpha = input_string[index];
    int pre_index = index;
    int n = input_string.size();
    
    check_alpha[alpha - 'a'] = 1;
    visited[index] = 1;    

    for (int j = index + 1; j < n; j++) {
        if (alpha == input_string[j]) {
            visited[j] = 1;
            if (j - index == 1) index = j;
            else return true;
        }       
    }
    return false;
}

string solution(string input_string) {
    string answer = "";
    for (int i = 0; i < input_string.size(); i++) {
        if (!visited[i] && !check_alpha[input_string[i] - 'a'] && check(i, input_string)) {
            answer.push_back(input_string[i]);
        }
    }
    
    if (answer.empty()) answer.push_back('N');
    else sort(answer.begin(), answer.end());
    
    return answer;
}