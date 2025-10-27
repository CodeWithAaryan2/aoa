#include <stdio.h>
#include <string.h>
// Function to find max of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}
// Function to compute LCS
void LCS(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);
    int dp[m + 1][n + 1];
    // Build LCS table in bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    // Length of LCS
    int length = dp[m][n];
    printf("Length of LCS: %d\n", length);

    // Backtrack to find LCS string
    char lcs[length + 1];
    lcs[length] = '\0';
    int i = m, j = n, index = length - 1;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index--] = X[i - 1];
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    printf("LCS: %s\n", lcs);
}
int main() {
    char X[100], Y[100];
    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);
    LCS(X, Y);
    return 0;
}



Enter first string: ABCDGH 
Enter second string: AEDFHR 
Length of LCS: 3 
  LCS: ADH 
