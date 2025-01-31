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

    for (i = 1; i < n; i++) {
        min[i] = min[i-1] + a[i-1];
    }

    for (i = size; i >)

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

0 3 7
0 4 7
-------------------------
5
1 2 3 3 5 5 6 8 10 11

0 1 3 6 11
0 5 8 10 11

*/