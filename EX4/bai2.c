#include <stdio.h>
#include <math.h>
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

int countXOR(int a, int b) {
    if (a == b) return 0;
    else return 1;
}

int toBinary(int n) {
    int temp;
    int count = 0;
    int binum = 0;
    while (n != 0) {
        temp = n % 2;
        binum += temp*pow(10, count);
        n /= 2;
        count++;
    }
    return binum;
}

int getXOR(int x, int y) {
    int bx = toBinary(x);
    int by = toBinary(y);
    // printf("%d === %d\n", bx, by);
    int numXOR = 0;
    int count = 0;
    int x1, y1;
    do {
        if (bx == 0 && by != 0) x1 = 0;
        if (by == 0 && bx != 0) y1 = 0;
        x1 = bx % 10;
        bx = bx / 10;
        y1 = by % 10;
        by = by / 10; 
        // printf("%d - %d = %d\n", x1, y1, countXOR(x1,y1));
        numXOR += countXOR(x1, y1)* pow(10, count);
        count++;
    } while (bx != 0 || by != 0);
    return numXOR;
}

int toDecimal(int n) {
    int num = 0;
    int count = 0;
    while (n != 0) {
        num += (n % 10) * pow(2, count);
        n /= 10;
        count++;
    }
    return num;
}

int main() {
    int a, b;
    scanf ("%d%d", &a, &b);
    printf("%d , %d\n", a, b);
    int max = 0;
    for (int i = min(a,b); i <= max(a,b); i++) {
        for (int j = min(a,b); j <= max(a,b); j++) {
            // printf("==%d XOR %d\n", i, j);
            // printf("%d XOR %d = %d\n", toBinary(i), toBinary(j), getXOR(i, j));
            // printf("--------------\n");
            if (max < getXOR(i,j)) {
                max = getXOR(i,j);     
            }
        }
    }
    printf("Final: %d", toDecimal(max));
    return 0;
}