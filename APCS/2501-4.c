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

int find_min_range(int *a, int n, int k, int *start) {
    int min_range = a[n-1] - a[0]; // 初始化為整個陣列最大範圍
    for (int i = 0; i <= n - k; i++) {
        int range = a[i + k - 1] - a[i];

        // 找到更小範圍則更新
        if (range < min_range) {
            min_range = range;
            *start = i; // 標記範圍起始數字
        }
    }
    return min_range;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sorted(a, n);  // 先把陣列進行泡沫排序

    int start1, start2;
    int distance1 = find_min_range(a, n, k, &start1);
    int distance2 = a[n-1] - a[0]; // 初始化為整個陣列最大範圍
    

     for (int i = 0; i <= n - k; i++) {
        
        // 跳過與第一組重疊的範圍
        if (i >= start1 && i < start1 + k) continue;
        int range = a[i + k - 1] - a[i];

        // 找到更小範圍則更新
        if (range < distance2) {
            distance2 = range;
            start2 = i;
        }
    }

    // 計算總距離
    printf("%d\n", distance1 + distance2);

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