#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>

using std::vector;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::min;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int E, F, N;
    in >> E >> F >> N;

    int target_weight = F - E;

    vector<int> dp(target_weight + 1, INT_MAX);
    dp[0] = 0;


    for (int i = 0; i < N; ++i) {
        int C, W;
        in >> C >> W;

        dp[W] = C;

        for (int w = W; w <= target_weight; ++w) {
            if (dp[w - W] != INT_MAX && dp[w - W] != 0) {
                dp[w] = min(dp[w], dp[w - W] + C);
            }
        }
    }

    if (dp[target_weight] == INT_MAX) {
        out << -1 << endl;
    }
    else {
        out << dp[target_weight] << endl;
    }

    in.close();
    out.close();

    return 0;
}
