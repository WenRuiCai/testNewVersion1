#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n;

bool isSu(int num) {
    if (num % 2 == 0 && num > 2) {
        return false;
    } else if (num > 3 && num % 3 == 0) {
        return false;
    } else if (num > 5 && num % 5 == 0) {
        return false;
    } else if (num > 7 && num % 7 == 0) {
        return false;
    }
    int n = sqrt((double) num);
    for (int i = 2;i <= n;i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void work(int *printArray, int *usedarray, int place) {
    if (place == n) {
        if (isSu(printArray[n - 1] + printArray[0])) {
            for (int i = 0;i < n;i++) {
                printf("%d ", printArray[i]);
            }
            printf("\n");
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (usedarray[i] == 0) {
            if (place > 0 && place < n) {
                if (isSu(i + 1 + printArray[place - 1])) {
                    printArray[place] = i + 1;
                    usedarray[i] = 1;
                    work(printArray, usedarray, place + 1);
                    usedarray[i] = 0;
                    printArray[place] = 0;
                }
            } else if (place == 0) {
                printArray[place] = i + 1;
                usedarray[i] = 1;
                work(printArray, usedarray, place + 1);
                usedarray[i] = 0;
                printArray[place] = 0;
            }
        }
    }
}

int main() {
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        a[i] = 0;
        b[i] = 0;
    }
    work(a, b, 0);
    return 0;
}