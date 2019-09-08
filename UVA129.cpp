//
// Created by 84443 on 2019/8/28.
//
#include <iostream>

using namespace std;

char array[26];
int n, L;

bool canPut(int num, int *printArray, int place) {
    if (num == printArray[place - 1]) {
        return false;
    }
    printArray[place] = num;
    for (int i = 1;i * 2 <= place + 1;i++) {
        bool equal = true;
        for (int j = 0; j < i ; j++) {
            if (printArray[place - i - j] != printArray[place - j]) {
                equal = false;
                break;
            }
        }
        if (equal) {
            printArray[place] = -1;
            return false;
        }
    }
    printArray[place] = -1;
    return true;
}

void work(int *printArray, int place) {
    if (place == n) {
        for (int i = 0;i < n;i++) {
            printf("%c ", array[printArray[i]]);
        }
        printf("\n");
    } else if (place == 0) {
        for (int j = 0;j < L;j++) {
            printArray[place] = j;
            work(printArray, place + 1);
            printArray[place] = -1;
        }
    } else if (place > 0 && place < n) {
        for (int j = 0;j < L;j++) {
            if (canPut(j, printArray, place)) {
                printArray[place] = j;
                work(printArray, place  + 1);
                printArray[place] = -1;
            }
        }
    }
}

int main() {
    for (int i = 0;i < 26; i++) {
        array[i] = 'A' + i;
    }
    while (cin >> n >> L) {
        int printArray[n];
        for (int i = 0;i < n;i++) {
            printArray[i] = -1;
        }
        work(printArray, 0);
    }
}
