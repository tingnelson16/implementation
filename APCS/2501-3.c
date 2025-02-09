#include <stdio.h>          // https://zerojudge.tw/ShowProblem?problemid=q183
int main() {
    int n;
    scanf("%d", &n);

    int size = n * (n - 1) / 2;
    int a[size];
    int i;
    for (i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    int min[n], max[n];
    min[0] = 0; // 假設輸出最小字典序的第一個數字是 0
    max[0] = 0; // 假設輸出最大字典序的第一個數字是 0

    for (i = 1; i < size; i++) {
        min[i] = a[size - 1] - a[i]; // 原陣列最大值減去i
        max[i] = a[size - 1] - a[i-1]; // 原陣列最大值減去i-1

        min[n - 1] = a[size - 1];
        max[n - 1] = a[size - 1];
    }

    for (i = 0; i < n; i++) {
        printf("%d ", min[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%d ", max[i]);
    }
    printf("\n");

    return 0;
}

/*

3
3 4 7

min 0 3 7
max 0 4 7
-------------------------
5
1 2 3 3 5 5 6 8 10 11

min 0 1 3 6 11
max 0 5 8 10 11

*/