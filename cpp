#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<vector<long long>> dp(n + 1, vector<long long>(4, 0));

    if (n > 1) dp[1][1] = 1;
    if (n > 2) dp[3][2] = 1;

    if (n == 1 || n == 3) {
        cout << 1;
    }
    else {
        for (long long i = 4; i <= n; ++i) {
            for (int j = 1; j <= 3; ++j) {
                if (j - 1 >= 1 && i - j >= 0) {
                    dp[i][j] += dp[i - j][j - 1];
                }
                if (j + 1 <= 3 && i - j >= 0) {
                    dp[i][j] += dp[i - j][j + 1];
                }
            }
        }
        long long result = dp[n][1] + dp[n][2] + dp[n][3];
        cout << result << endl;

    }
}
