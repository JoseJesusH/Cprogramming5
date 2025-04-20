#include <stdio.h>

int compare(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] && str2[i]) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

int main() {
    char a[] = "apple";
    char b[] = "apricot";
    int result = compare(a, b);

    if (result == 0) {
        printf("Strings are equal.\n");
    } else if (result < 0) {
        printf("str1 is less than str2.\n");
    } else {
        printf("str1 is greater than str2.\n");
    }

    return 0;
}

