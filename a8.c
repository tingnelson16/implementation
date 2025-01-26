#include <stdio.h>          // https://zerojudge.tw/ShowProblem?problemid=g595
int main() {
    int n, i;
    scanf("%d", &n);

    int h[101], total = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    for (i = 0; i < n; i++) {

        // 特殊狀況: 如果第一個數字是空的
        if (i == 0 && h[i] == 0) {
            total += h[i+1];
        }
        // 特殊狀況: 如果最後一個數字是空的
        if (i+1 == n && h[i] == 0) {
            total += h[i-1];
        }

        if (h[i] == 0 && i > 0 && i < n-1) {
            if (h[i-1] < h[i+1]) {
                total += h[i-1];
            } else total += h[i+1];
        }
    }
    printf("%d", total);
    return 0;
}