#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using std::vector;
using std::cin;
using std::cout;
using std::pair;
using std::min;
using std::endl;

int main() {
    int n, k, s;
    cin >> n >> k >> s;

    vector<vector<pair<int, int>>> categoryOffers(k + 1);

    for (int i = 0; i < n; ++i) {
        int t, a, c;
        cin >> t >> a >> c;
        categoryOffers[t].emplace_back(a, c);
    }

    vector<vector<int>> dp(k + 1, vector<int>(s + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j <= s; ++j) {
            if (dp[i - 1][j] != INT_MAX) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            }
        }

        for (const auto& offer : categoryOffers[i]) {
            int a = offer.first;
            int cost = offer.second;
            for (int j = s; j >= 0; --j) {
                if (dp[i - 1][j] != INT_MAX) {
                    int newAmount = min(j + a, s);
                    dp[i][newAmount] = min(dp[i][newAmount], dp[i - 1][j] + cost);
                }
            }
        }
    }

    int result = dp[k][s];
    if (result == INT_MAX) {
        cout << -1 << endl;
    }
    else {
        cout << result << endl;
    }

    return 0;
}
