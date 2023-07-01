#include <iostream>
#include <string.h>

using namespace std;

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
    ".---",//1
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
    puts(s);
    char *p = strtok(s, " ");
    do {
        for (int i = 0; i <= 36; i++) {
            if (!strcmp(p, morse[i])) {
                // cout << "Ki tu p: " << p << endl ;
                // cout << " Ki tu: " << characters[i] << endl ;
                // cout <<  "Ma Morse:" << morse[i] << endl;
                cout << characters[i];
            } 
        }
        p = strtok(NULL, " ");
    } while (p != NULL); 

    // for (int i = 0; i <= 36; i++) {
    //     cout << characters[i]  << morse[i] << endl;
    // }
    // for (char *p = strtok(s," "); p != NULL; p = strtok(NULL, " ")) {
        // for (int i = 0; i <= 26; i++) {
        //     if (!strcmp(p, morse[i])) {
        //         cout << "Ki tu p: " << p << endl ;
        //         cout << " Ki tu: " << characters[i] << endl ;
        //         cout <<  "Ma Morse:" << morse[i] << endl;
    //         }
    //     }
    // }
    return 0;
}
