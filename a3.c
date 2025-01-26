#include <stdio.h>          // https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=979
#include <math.h>

int main() {
    int n, i = 0;
    int s[3000];  // 儲存陣列
    int max = -99999;

    // 持續讀取直到\n
    while (getchar() != '\n') {
        scanf("%d", &s[i]);
        if (max < s[i]) {
            max = s[i];
        }
        i++;
    }

    n = i;  // 儲存序列長度

    // 特殊情況處理：序列長度為 1 時，必定是 Jolly
    if (n == 1) {
        printf("Jolly\n");
        return 0;
    }

    int jolly = 1;  // 假設是 Jolly

    // 計算差異並紀錄
    int x;
    for (i = 1; i < n; i++) {
        x = abs(s[i] - s[i - 1]);   // 絕對值
        if (x > max) {
            jolly = 0;
        }
    }

    // 根據結果輸出
    if (jolly == 1) {
        printf("Jolly\n");
    } else {
        printf("Not jolly\n");
    }
    return 0;
}