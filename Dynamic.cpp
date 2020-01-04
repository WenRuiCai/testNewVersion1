



//
// Created by 84443 on 2019/9/7.
//
#include <iostream>
#include <memory.h>

#define INF 9999999
using namespace std;

const int maxN = 50;
const int maxT = 200;
int count = 1;
int eachTime[maxN];
int has_train[maxT][maxN][2];
int dp[maxT][maxN];

int main() {
    while (true) {
        memset(eachTime, 0, maxN);
        memset(dp, 0, maxT * maxN);
        memset(has_train, 0, maxT * maxN * 2);
        int n, T, M1, M2;
        cin >> n;
        if (n == 0) {
            break;
        }
        cin >> T;
        for (int i = 1;i <= n - 1;i++) {
            cin >> eachTime[i];
        }
        cin >> M1;
        for (int i = 1;i <= M1;i++) {
            int beginTime, tmp;
            cin >> beginTime;
            has_train[beginTime][1][0] = 1;
            tmp = beginTime;
            for (int j = 1;j <= n - 1;j++) {
                has_train[tmp + eachTime[j]][j + 1][0] = 1;
                tmp += eachTime[j];
            }
        }
        cin >> M2;
        for (int i = 1;i <= M2;i++) {
            int beginTime, tmp;
            cin >> beginTime;
            has_train[beginTime][n][1] = 1;
            tmp = beginTime;
            for (int j = n - 1;j >= 1;j--) {
                has_train[tmp + eachTime[j]][j][1] = 1;
                tmp += eachTime[j];
            }
        }
        dp[T][n] = 0;
        for (int i = 1; i <= n - 1; i++) {
            dp[T][i] = INF;
        }
        for (int i = T - 1; i >= 0;i--) {
            for (int j = 1; j <= n;j++) {
                dp[i][j] = dp[i + 1][j] + 1;
                if (j < n && has_train[i][j][0] && i + eachTime[j] <= T) {
                    dp[i][j] = min(dp[i][j], dp[i + eachTime[j]][j + 1]);
                }
                if (j > 1 && has_train[i][j][1] && i + eachTime[j - 1] <= T) {
                    dp[i][j] = min(dp[i][j], dp[i + eachTime[j - 1]][j - 1]);
                }
            }
        }
        if (dp[0][1] >= INF) {
            cout << "Case Number " << count++ << ": " << "impossible" << endl;
        } else {
            cout << "Case Number " << count++ << ": " << dp[0][1] << endl;
        }
    }
    return 0;
}