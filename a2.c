#include <stdio.h>          // https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=21&page=show_problem&problem=1870
int main() {
    int N[1000];
    int i, j = 0;

    for (i = 0; i < 1000; i++) {
        scanf("%d", &N[i]);
        if (N[i] == 0) {
            break;
        }
        j++;    //陣列儲存的數字+1
    }

    //判斷是否為11的倍數
    for (i = 0; i < j; i++) {
        if (N[i] % 11 == 0) {
            printf("%d is a multiple of 11.\n", N[i]);
        } else {
            printf("%d is a not multiple of 11.\n", N[i]);
        }
    }
    return 0;
}