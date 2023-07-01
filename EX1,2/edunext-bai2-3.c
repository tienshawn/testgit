#include <stdio.h>
#include<string.h>

void Xoa(char *s, int vitrixoa)
{
    int n = strlen(s);
	for (int i = vitrixoa + 1; i < n; i++)
	{
		s[i - 1] = s[i];
	}
	n--; // số lượng phần tử mảng giảm
}

int main() {
    char *s = "1000";
    int len = strlen(s);
    for (int i = 0; i < strlen(s) - 1; i++) {
        if (s[i] == 49 && s[i + 1] == 48) {
            for (int j = i+1; j < strlen(s); j++) {
                Xoa(s, j); 
                i--;
            }
        }
    }
    for (int i = 0; i < 100; i ++) {
        printf("%d", s[i]);
    }
    // char arr[1000] = {};
    // int count = 0;
    // int len = strlen(s);
    // for (int i = 0; i < count; i++) {
    //     printf("%d", arr[i]);
    // }
    // for (int i = 0; i < count - 1; i++) {
    //     if (arr[i] == 1 && arr[i+1] == 0) {
    //         len -= 2;
    //     }
    // }
    // printf("Length: %d", strlen(s));
    return 0;
}
