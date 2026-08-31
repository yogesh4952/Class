#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *keywords[] = {
    "int", "float", "char", "if", "else", "for",
    "while", "return", "void"
};

int isKeyword(char word[]) {
    int i;
    for (i = 0; i < 9; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char input[200];
    int i = 0;

    printf("Enter a C statement:\n");
    fgets(input, sizeof(input), stdin);

    while (input[i] != '\0') {
        if (isalpha(input[i]) || input[i] == '_') {
            char word[50];
            int j = 0;
            while (isalnum(input[i]) || input[i] == '_') {
                word[j++] = input[i++];
            }
            word[j] = '\0';

            if (isKeyword(word)) {
                printf("%s -> Keyword\n", word);
            } else {
                printf("%s -> Identifier\n", word);
            }
        }
        else if (isdigit(input[i])) {
            char number[50];
            int j = 0;
            while (isdigit(input[i])) {
                number[j++] = input[i++];
            }
            number[j] = '\0';
            printf("%s -> Number\n", number);
        }
        else if (input[i] == '+' || input[i] == '-' ||
                 input[i] == '*' || input[i] == '/' ||
                 input[i] == '=') {
            printf("%c -> Operator\n", input[i]);
            i++;
        }
        else if (input[i] == ';' || input[i] == '(' ||
                 input[i] == ')' || input[i] == '{' ||
                 input[i] == '}') {
            printf("%c -> Special Symbol\n", input[i]);
            i++;
        }
        else {
            i++;
        }
    }

    return 0;
}
