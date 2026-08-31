#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    int len;

    printf("Enter a comment: ");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);

    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    if (str[0] == '/' && str[1] == '/') {
        printf("Valid Single-line Comment\n");
    }
    else if (str[0] == '/' && str[1] == '*') {
        if (len >= 4 && str[len - 2] == '*' && str[len - 1] == '/') {
            printf("Valid Multi-line Comment\n");
        }
        else {
            printf("Invalid Multi-line Comment\n");
        }
    }
    else {
        printf("Not a Comment\n");
    }

    return 0;
}
