#include <stdio.h>          // https://zerojudge.tw/ShowProblem?problemid=h026
int main() {
    int brother, count;
    int i, result;
    scanf("%d %d", &brother, &count);

    int sister[10];
    for (i = 0; i < count; i++) {
        scanf("%d", &sister[i]);
    }

    printf("%d ", brother);

    for (i = 0; i < count; i++) {
        
        // 哥哥的猜拳策略
        if (i >= 2 && sister[i - 1] == sister[i - 2]) {

            // 如果絲絲連續兩輪出了一樣的拳，下一輪他就會出打敗絲絲前兩輪的拳
            if (sister[i - 1] == 0) {
                brother = 5;
            } else if (sister[i - 1] == 2) {
                brother = 0;
            } else {
                brother = 2;
            }
        } else if (i > 0) {           // 否則，他下一輪會出跟絲絲前一輪一樣的拳
            brother = sister[i - 1];
        }

        if (i > 0) printf("%d ", brother);

        // 判斷勝負
        if ((brother == 0 && sister[i] == 2) || (brother == 2 && sister[i] == 5) || (brother == 5 && sister[i] == 0)) {
            printf(" : Won at round %d\n", i + 1);
            break;
        } else if ((sister[i] == 0 && brother == 2) || (sister[i] == 2 && brother == 5) || (sister[i] == 5 && brother == 0)) {
            printf(" : Lost at round %d\n", i + 1);
            break;
        }
        if (i + 1 == count) {
            printf(" : Drew at round %d\n", i + 1);
        }
    }
    return 0;
}