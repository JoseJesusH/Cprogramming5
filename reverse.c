#include <stdio.h>
#include <string.h>

void reverse(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int main() {
    char word[] = "MC202";
    reverse(word);
    printf("Reversed string: %s\n", word);
    return 0;
}

