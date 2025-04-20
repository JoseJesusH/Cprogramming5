#include <stdio.h>

void copy(char str1[], char str2[]) {
    int i = 0;
    while ((str2[i] = str1[i]) != '\0') {
        i++;
    }
}

int main() {
    char source[] = "How are you doing!";
    char dest[100];
    copy(source, dest);
    printf("Copied string: %s\n", dest);
    return 0;
}

