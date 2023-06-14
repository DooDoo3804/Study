#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), comp);
    
    long long ans = 0;
    
    for (int i = 0; i < A.size(); i++) {
        ans += A[i] * B[i];
    }
    
    return ans;
}