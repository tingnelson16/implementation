#include <stdio.h>          // https://zerojudge.tw/ShowProblem?problemid=j605
int main() {
    int k;
    int times = 0, max_score = -1, wrong = 0;
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        // 計算最高分
        if (b > max_score) {
            max_score = b;
            times = a;
        } else if (b == -1) {
            wrong++;
        }
    }
    int total;
    total = max_score - k - wrong * 2;

    if (total < 0) {
        total = 0;
    }

    printf("%d %d\n", total, times);
    
    return 0;
}

/*

輸出結果:
總分 第一次獲得最高分的時間點

*/