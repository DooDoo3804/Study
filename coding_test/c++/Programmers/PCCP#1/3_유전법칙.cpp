#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    vector<int> t;
    
    for (auto q : queries) {
        int gen = q[0];
        int ent = q[1] - 1;
        int gens = q[0] - 2;
        t = vector<int>();
        
        if (gen == 1) answer.push_back("Rr");
        else {
            while(gens--) {
                t.push_back(ent % 4);
                ent/=4;
            }
            t.push_back(ent);
            
            reverse(t.begin(), t.end());

            for (int i = 0; i < t.size(); i++) { 
                if (i == t.size() - 1) {
                  if (t[i] == 1 || t[i] == 2) {
                    answer.push_back("Rr");
                    break; 
                    }
                    else continue;
                }
                else {
                    if (t[i] == 0) {
                        answer.push_back("RR");
                        break;
                    }
                    if (t[i] == 3) {
                        answer.push_back("rr");
                        break;
                    }    
                }
                
            }
        }
    }
    
    
    
    
    return answer;
}