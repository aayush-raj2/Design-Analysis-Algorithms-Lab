#include <stdio.h>
#include <string.h>

int main() {
    char text[200], pattern[100];
    int i, j, found = 0;

    printf("Enter text: ");
    gets(text);

    printf("Enter pattern: ");
    gets(pattern);

    int n = strlen(text);
    int m = strlen(pattern);

    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) {
            printf("Pattern found at index %d\n", i);
            found = 1;
        }
    }

    if (!found)
        printf("Pattern not found\n");

    return 0;
}
