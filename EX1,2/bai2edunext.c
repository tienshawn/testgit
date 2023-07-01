#include <stdio.h>

int checkNum(long n) {
    int arr[1000] = {};
    int flag = 1;
    int count = 0;
    while (n > 0) {
        arr[count] = n % 10;
        count++;
        n = n /10;
    }
    for (int i = 0; i < count - 1; i++) {
        if (arr[i] != arr[i+1] + 1) {
            flag = 0;
        }
    }
    return flag;
}

void swap(int a, int b) {
    int temp = 0;
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
}
//a < b

int main() {
    long l, r;
    int num[1000] = {};
    int count = 0;
    scanf("%ld %ld", &l, &r);
    swap(l, r);
    for (long i = l; i <= r; i++) {
        if (checkNum(i)) {
            num[count] = i;
            count++;
        }
    }
    
    printf("[");
    for (int i = 0; i < count; i++) {
        if (i != count - 1) {
            printf("%d,", num[i]);
        }
        else printf("%d", num[i]);
    }
    printf("]");
}