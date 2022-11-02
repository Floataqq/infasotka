#include <stdio.h>
int main()
{
    int n; scanf("%d", &n);
    int sum[n];
    int A[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            A[i][j] = 0;
        }
        sum[i] = 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &A[i][j]);
            if(A[i][j] == 1)
                sum[i]++;
        }
    }
    for(int i = 0; i < n; i++)
        printf("%d %c", sum[i], '\n');
    return 0;
}
