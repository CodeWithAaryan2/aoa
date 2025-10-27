#include <stdio.h>
#include <string.h>
void naiveStringMatch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    printf("Pattern found at positions: ");
    int found = 0;
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) {
            printf("%d ", i);  // pattern found at index i
            found = 1;
        }
    }
    if (!found)
        printf("None");
    printf("\n");
}
int main() {
    char text[100], pattern[50];
    printf("Enter the text: ");
    scanf("%[^\n]", text);  // read full line including spaces
    getchar();              // consume newline
    printf("Enter the pattern to search: ");
    scanf("%[^\n]", pattern);
    naiveStringMatch(text, pattern);
    return 0;
}
Output:
Enter the text: ABCABCABCABCABC 
Enter the pattern to search: ABC 
Pattern found at positions: 0 3 6 9 12 
