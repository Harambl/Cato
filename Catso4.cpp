#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int M;
    cin >> M;

    vector<int> s(M);
    for (int i = 0; i < M; ++i) {
        cin >> s[i];
    }

    int N;
    cin >> N;

    vector<int> dp(N, 0);
    dp[0] = 1;

    long long ans = 0;

    for (int x = 0; x < N; ++x) {
        if (dp[x] == 0) continue;
        for (int i = 0; i < M; ++i) {
            int nx = x + s[i];
            if (nx >= N) {
                ans = (ans + dp[x]) % MOD;
            }
            else {
                dp[nx] = (dp[nx] + dp[x]) % MOD;
            }
        }
    }

    cout << ans % MOD << '\n';

    return 0;
}
