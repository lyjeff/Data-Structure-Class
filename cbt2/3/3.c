#include <stdio.h>
int main()
{
    int n, i, j, k;
    freopen("3input_1.txt", "r", stdin);
    scanf("%d", &n);
    int arr[n][n];
    for(i = 0; i < n; i++) //input
        for(j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    for(k = 0; k < n; k++) //allCosts
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                arr[i][j]=arr[i][j] || arr[i][k] && arr[k][j];
    for(i = 0; i < n; i++) //output
    {
        for(j = 0; j < n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    return 0;
}
