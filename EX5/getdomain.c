#include <stdio.h>
#include <string.h>

char* domain(char* address) {
    char *p = strtok(address, "@");
    return p;
}

int main() {
    char add[1000] = "abc@gmail.com";
    char *p = add;
    printf("%s", add - domain(p));
    return 0;
}