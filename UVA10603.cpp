//
// Created by 84443 on 2019/8/30.
//
#include <iostream>

using namespace std;
static int num = 0;
int a[1000000];
int tmp[1000000];

int search(int x, int y) {
    if (y == x + 2) {
        return (a[y - 1] < a[x]) ? 1 : 0;
    } else if (y == x + 1 || y == x) {
        return 0;
    }
    int m = x + (y - x) / 2;
    int result = search(x, m) + search(m, y);
    int p = x, q = m, i = x;
    while (p < m || q < y) {
        if (q >= y || (p < m && a[p] < a[q])) {
            tmp[i++] = a[p++];
        } else {
            tmp[i++] = a[q++];
            result += m - p;
        }
        num++;
    }
    for (i = x; i < y; i++) {
        a[i] = tmp[i];
    }
    return result;
}

int search2(int len) {
    int time = 0;
    int result = 0;
    for (int i = 0;i < len;i++) {
        for (int j = i + 1;j < len;j++) {
            if (a[i] > a[j]) {
                result++;
            }
            time++;
        }
    }
    cout << result << "  " << time << endl;
}

int main() {
    int b, i = 0;
    while (cin >> b) {
        a[i++] = b;
    }
    search2(i);
    cout << search(0, i) << endl;
    cout << num << endl;
}

