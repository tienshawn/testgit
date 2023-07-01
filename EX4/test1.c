#include <stdio.h>
#include <string.h>

const char *morse[1000] = {
    ".-",    // a
    "-...", // b
    "-.-.", // c
    "-..", // d
    ".", //e
    "..-.", //f
    "--.", //g
    "....", //h
    "..", //i
    ".---", //j
    "-.-", //k
    ".-..", //l
    "--", //m
    "-.", //n
    "---", //o
    ".--.", //p
    "--.-",//q
    ".-.",//r
    "...",//s
    "-",//t
    "..-",//u
    "...-",//v
    ".--",//w
    "-..-",//x
    "-.--",//y
    "--..",//z
    ".----",//1
    "..---",//2
    "...--",//3
    "....-",//4
    ".....",//5
    "-....",//6
    "--...",//7
    "---..",//8
    "----.",//9
    "-----",//0
    "/"//" "
};
const char *characters[1000] = {
    "a",  
    "b",  
    "c",
    "d",
    "e",
    "f",
    "g",
    "h",
    "i",
    "j",
    "k",
    "l",
    "m",
    "n",
    "o",
    "p",
    "q",
    "r",
    "s",
    "t",
    "u",
    "v",
    "w",
    "x",
    "y",
    "z",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "0",
    " "
};

int main() {
    char s[1000];
    gets(s);
    char *p = strtok(s, " ");
    do {
        for (int i = 0; i <= 36; i++) {
            if (!strcmp(p, morse[i])) {
                printf("%s", characters[i]);
            } 
        }
        p = strtok(NULL, " ");
    } while (p != NULL); 
    return 0;
}
