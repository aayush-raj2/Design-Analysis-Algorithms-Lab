#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char X[] = "ABCDGH";
    char Y[] = "AEDFHR";

    int n = strlen(X);
    int m = strlen(Y);

    int dp[n+1][m+1];

    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {

            if(i == 0 || j == 0)
                dp[i][j] = 0;

            else if(X[i-1] == Y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];

            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    printf("Length of LCS: %d\n", dp[n][m]);

    return 0;
}
