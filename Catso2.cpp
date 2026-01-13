#include <iostream>
#include <cstring>
using namespace std;

long long memo[51][21][21];

long long solve(int pos, int a, int b, int n) {
    if (a == 0 && b == 0) return 1;
    if (pos >= n) return 0;

    if (memo[pos][a][b] != -1) return memo[pos][a][b];

    long long res = 0;

    res += solve(pos + 1, a, b, n);

    if (a > 0) {
        if (pos + 1 <= n) {
            if (pos + 1 == n) {
                res += solve(pos + 1, a - 1, b, n);
            }
            else {
                res += solve(pos + 2, a - 1, b, n);
            }
        }
    }

    if (b > 0) {
        if (pos + 2 <= n) {
            if (pos + 2 == n) {
                res += solve(pos + 2, a, b - 1, n);
            }
            else {
                res += solve(pos + 3, a, b - 1, n);
            }
        }
    }

    return memo[pos][a][b] = res;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    memset(memo, -1, sizeof(memo));
    cout << solve(0, a, b, n) << endl;

    return 0;
}
