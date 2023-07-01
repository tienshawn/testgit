#include <iostream>
#include <string.h>

const char *morseLetters[] = {
    ".-",    // a
    "-...", // b
    "-.-.", // c
    "--.." // z
};
const char *morseDigits[10] = {
    "-----",  // 0
    ".----",  // 2
    "----."
};

int main() {
    string c[1000] = ".- -... -.-. --..";
    get(c);
    printf("%c", c);
    return 0;
}
