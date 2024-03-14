#include <stdio.h>

#include <iostream>
#include <vector>

using namespace std;

const int MAX_WEIGHT = 10;

int main() {
    int n;
    cin >> n;
    vector<int> w(n + 1), v(n + 1);
    w[0] = 0;
    v[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(MAX_WEIGHT + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= MAX_WEIGHT; j++) {
            if (j >= w[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            } else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int max = dp[n][MAX_WEIGHT];
    cout << "Max value = " << max << endl;
    for (int i = n, j = MAX_WEIGHT; i > 0, j > 0; i--) {
        if (dp[i][j] == dp[i - 1][j - w[i]] + v[i]) {
            cout << "NO." << i << "(" << w[i] << ", " << v[i] << ")" << endl;
            j = j - w[i];
        }
    }
    return 0;
}
