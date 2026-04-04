#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, count;
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    int len = strlen(str);
    
    for (i = 0; i < len; i++) {
        count = 1;
        
        // Count consecutive identical characters
        while (i < len - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        
        // Print character and its count
        printf("%c%d", str[i], count);
    }
    
    printf("\n");
    return 0;
}