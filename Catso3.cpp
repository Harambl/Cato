#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void generate_next_masks(int row, int current_mask, int next_mask, int n, vector<int>& results) {
    if (row == n) {
        results.push_back(next_mask);
        return;
    }
    if (current_mask & (1 << row)) {
        generate_next_masks(row + 1, current_mask, next_mask, n, results);
    }
    else {
        if (row + 1 < n && !(current_mask & (1 << (row + 1)))) {
            generate_next_masks(row + 2, current_mask, next_mask, n, results);
        }
        generate_next_masks(row + 1, current_mask, next_mask | (1 << row), n, results);
    }
}

long long solve(int n, int m) {
    if ((n * m) % 2 != 0) {
        return 0;
    }

    int total_masks = 1 << n;
    vector<vector<int>> transitions(total_masks);
    for (int mask = 0; mask < total_masks; ++mask) {
        vector<int> results;
        generate_next_masks(0, mask, 0, n, results);
        transitions[mask] = results;
    }

    vector<long long> dp(total_masks, 0);
    dp[0] = 1;

    for (int col = 0; col < m; ++col) {
        vector<long long> new_dp(total_masks, 0);
        for (int mask = 0; mask < total_masks; ++mask) {
            if (dp[mask] == 0) continue;
            for (int next_mask : transitions[mask]) {
                new_dp[next_mask] += dp[mask];
            }
        }
        dp = move(new_dp);
    }

    return dp[0];
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m;
    fin >> n >> m;

    long long ans = solve(n, m);
    fout << ans << endl;

    fin.close();
    fout.close();
    return 0;
}
