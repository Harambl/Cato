#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <fstream>

using std::vector;
using std::min;
using std::ifstream;
using std::ofstream;

const double INF = 1e20;

int main() {
    
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N;
    in >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        in >> a[i];
    }

    // Координаты клавиш (строка, столбец)
    vector<int> row(10), col(10);
    for (int d = 1; d <= 9; ++d) {
        row[d] = (d - 1) / 3 + 1; // строки от 1 до 3
        col[d] = (d - 1) % 3 + 1; // столбцы от 1 до 3
    }
    row[0] = 4;
    col[0] = 2;

    // Предвычисление расстояний между всеми парами клавиш
    vector<vector<double>> dist(10, vector<double>(10));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            double dx = row[i] - row[j];
            double dy = col[i] - col[j];
            dist[i][j] = sqrt(dx * dx + dy * dy);
        }
    }

    // dp[L][R] - минимальное время, когда левый палец на L, правый на R
    vector<vector<double>> dp(10, vector<double>(10, INF));
    dp[4][6] = 0.0; // начальное положение

    for (int i = 0; i < N; ++i) {
        int target = a[i];
        vector<vector<double>> new_dp(10, vector<double>(10, INF));
        for (int L = 0; L < 10; ++L) {
            for (int R = 0; R < 10; ++R) {
                if (dp[L][R] >= INF) continue;

                // Нажимаем target левым пальцем
                if (col[target] <= col[R]) {
                    double new_time = dp[L][R] + dist[L][target];
                    if (new_time < new_dp[target][R]) {
                        new_dp[target][R] = new_time;
                    }
                }

                // Нажимаем target правым пальцем
                if (col[L] <= col[target]) {
                    double new_time = dp[L][R] + dist[R][target];
                    if (new_time < new_dp[L][target]) {
                        new_dp[L][target] = new_time;
                    }
                }
            }
        }
        dp = move(new_dp);
 
    }

    // Находим минимальное время среди всех конечных состояний
    double ans = INF;
    for (int L = 0; L < 10; ++L) {
        for (int R = 0; R < 10; ++R) {
            ans = min(ans, dp[L][R]);
        }
    }

    out << ans;

    in.close();
    out.close();

    return 0;
}
