#include <stdio.h>

int steps(int, int, int, int);

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        int result = steps(x1, y1, x2, y2);
        printf("Case %d: %d\n", i, result);  
    }
}

int steps(int x1, int y1, int x2, int y2) {
    int count = 0;

    while (x1 != x2 || y1 != y2) {

        // 跨層動作
        while (x1 + y1 != x2 + y2) {
        if(y1 == 0) {
            int t = x1;
            x1 = y1;
            y1 = t;
            y1++;
        } else {
            x1++;
            y1--;
        }
        count++;
        }
        //同層動作
        if (x1 + y1 == x2 + y2 && x1 < x2) {
            x1++;
            y1--;
            count++;
        }
    }
    
    return count;
}

/*
位置:
(0,0)
(0,1)(1,0)
(0,2)(1,1)(2,0)
(0,3)(1,2)(2,1)(3,0)
(0,4)(1,3)(2,2)(3,1)(4,0)
...
同層動作:
每行 x + 1 加到 每行的大小
y - 1 減到 0

跨層動作:
判斷目標的 x + y !=原本的 x + y
*/