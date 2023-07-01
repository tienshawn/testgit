#include <stdio.h>
#include <math.h>

int main() {
    int l, r;
    scanf("%d %d", &l, &r);
    int count = 0;
    int num[1000] = {};
    for (int i = 1; i <= pow(10,3); i++) { 
        int flag = 2;   
        int temp = i;    
        while(temp >= 10) {
            if ((temp % 10) != (((temp / 10) % 10) + 1)) {
                flag = 0;
                break;
            }
            else {
                flag = 1;
                temp = temp / 10;
            }
        }
        if (flag == 1) {
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
    return 0;
}