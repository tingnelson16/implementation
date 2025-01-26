#include <stdio.h>          // https://zerojudge.tw/ShowProblem?problemid=c039

int cycle_length(int n) {
    int length = 1;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        length++;
    }
    return length;
}

int main() {
    int i, j;
    while (scanf("%d %d", &i, &j) == 2) {
        int max = 0;
        int start, end;

        if (i < j) {
            start = i;
            end = j;
        } else {
            start = j;
            end = i;
        }
        
        for (int n = start; n <= end; n++) {
            int x = cycle_length(n);
            if (x > max) {
                max = x;
            }
        }
        printf("%d %d %d\n", i, j, max);
    }
    return 0;
}
