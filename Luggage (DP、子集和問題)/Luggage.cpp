#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

 bool IsPossible(vector<int> n){
    int avg = 0;
    for(int i = 0; i < n.size(); i++){
        avg += n[i];
    }
    if(avg % 2 != 0) return false;
    avg /= 2;

    vector<bool> dp(avg + 1, false);
    dp[0] = true;
    for(int i = 0; i < n.size(); i++){
        for(int j = avg; j >= n[i]; j--){
            dp[j] = dp[j] || dp[j - n[i]];
        }
    }
    return dp[avg];
 }

int main(){
    int m = 0;
    cin >> m;
    for(int i = 0; i < m; i++){
        vector<int> n;
        int input = 0;
        do{
            cin >> input;
            n.push_back(input);
        }
        while(cin.get() != '\n');
        if(IsPossible(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}