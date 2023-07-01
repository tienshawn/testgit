#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isMAC48Address(char* inputString)
{
    if (strlen(inputString) != 17) {
        return false;
    }
    for (int i = 0; i < strlen(inputString); ++i) {
        if (i % 3 == 0 || i % 3 == 1) {
            if (!isdigit(inputString[i]) && !(inputString[i] >= 'A' && inputString[i] <= 'F')) {
                return false;
            }
            continue;
        }
        if (inputString[i] != '-') {
            return false;
        }
    }
    return true;
}

int main() {
    char s[1000] = "192.168.1.78 00-2B-63-84-45-E6 192.168.1.10 00-1B-63-84-45-E7 192.168.1.15 00-1B-63-85-45-E6 192.168.1.54 00-1B-67-85-45-E6 192.168.1.60 A0-1A-67-85-47-E6 192.168.1.68 A0-1A-67-85-47-E6 192.168.1.70 A0-1A-68-85-47-E6 192.168.1.72 A0-1B-68-88-47-E6 192.168.1.78 A0-1B-68-85-47-E6 192.168.1.79";
    // gets(s);
    int count = 0;
    char *p = strtok(s, " ");
    do {
        if (isMAC48Address(p)) {
            printf("%d===", count);
            printf("%s\n", p);
            count++;
        }
        p = strtok(NULL, " ");
    } while (p != NULL); 
    return 0;
}
