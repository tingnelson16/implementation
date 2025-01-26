#include <stdio.h>          // https://zerojudge.tw/ShowProblem?problemid=m370

int main() {
    int x, n;
    scanf("%d %d", &x, &n);

    int right_count = 0, left_count = 0;
    int max = -201, min = 201;
    int food_positions;
    while (n--) {
        scanf("%d", &food_positions);

        // 食物在右邊
        if (food_positions >= x) {
            right_count++;
            if (food_positions >= max) {
                max = food_positions;
            }
        }

        // 食物在左邊
        if (food_positions <= x) {
            left_count++;
            if (food_positions <= min) {
                min = food_positions;
            }
        }
    }
    
    if (right_count > left_count){
        printf("%d %d\n", right_count, max);
    } else {
        printf("%d %d\n", left_count, min);
    }

    return 0;
}

/*

輸出結果:
最多能吃到的食物數 最後一個吃的食物停下的位置

*/