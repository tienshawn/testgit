#include <stdio.h>

int numofDigit(int n) {
    int len = 1;
    while (n / 10 != 0) {
        len++;
        n /= 10;
    }
    return len;
}

int main() {
    printf("%d", numofDigit(100));
    return 0;
} 