#include <stdio.h>
#include <string.h>

int main() {
    char* input = "abc adasf asdf";
    char* segment;
    // const char morse[10]={
    //     ".-", //morse code of letter A
    //     "-...", //morse code of letter B
    //     "-.-." , //morse code of letter C
    // };
    segment[1000] = strtok(input, " ");
    for (int i = 0; i <strlen(segment); i++) {
        // for (int i = 0; i < 26; i++) {
        //     if(strcmp(segment, morse[i]))
        //     printf("%c", i+65);
        // }
        printf("%c", segment[i]);
    }
    return 0;
}