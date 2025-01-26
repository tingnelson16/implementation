#include <stdio.h>          // https://zerojudge.tw/ShowProblem?problemid=q184

void sorted(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sorted(a, n);  // 先將陣列進行泡沫排序

    int distance1 = 9999, distance2 = 9999;

    // 找到第一組最小距離
    for (int i = 0; i < n - (k - 1); i++) {
        if (a[i + k - 1] - a[i] < distance1) {
            distance1 = a[i + k - 1] - a[i];
        }
    }

    // 把第一組裡面的數字搞爛
    for (int i = 0; i < n - (k - 1); i++) {
        if (a[i + k - 1] - a[i] == distance1) {
            for (int j = i; j < i + k; j++) {
                a[j] = -999;
            }
        }
    }

    // 找到第二組最小距離
    for (int i = 0; i < n - (k - 1); i++) {
        if (a[i + k - 1] - a[i] < distance2 && a[i] != -999 && a[i + k - 1] != -999) {
            distance2 = a[i + k - 1] - a[i];
        }
    }

    // 計算總距離
    int total_distance = distance1 + distance2;
    printf("%d\n", total_distance);

    return 0;
}

/*

6 2
0 2 5 6 6 9
→ (6,6) (0,2)

7 3
0 2 2 3 6 8 9
→ (2,2,3) (6,8,9)

*/