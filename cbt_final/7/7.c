#include <stdio.h>
#include <string.h>
int n, source, dist;
void find_path(int x, int *parent)  //印出由起點到x點的最短路徑
{
    if (x != parent[x]) //先把之前的路徑都印出來
        find_path(parent[x], parent);
    printf("%d ", x + 1);  //再把現在的位置印出來
}
void dijkstra(int w[n][n])
{
    int i, j;
    int d[n];       //記錄起點到各個點的最短路徑長度
    int parent[n];  //記錄各個點在最短路徑樹上的父親是誰
    int visit[n];   //記錄各個點是不是已在最短路徑樹之中
    memset(visit, 0, sizeof(visit));
    memset(d, 0x3f3f3f3f, sizeof(d));
    d[source] = 0;
    parent[source] = source;
    for (i = 0; i < n; i++)
    {
        int a = -1, min = 0x3f3f3f3f;
        for (j = 0; j < n; j++)
            if (!visit[j] && d[j] < min)
            {
                a = j;  //記錄這一條邊
                min = d[j];
            }
        if (a == -1)
            break;     //起點有連通的最短路徑都已找完
        visit[a] = 1;
        for (j = 0; j < n; j++) //以邊a,j進行relaxation
            if (!visit[j] && w[a][j] != 0 && d[a] + w[a][j] < d[j])
            {
                d[j] = d[a] + w[a][j];
                parent[j] = a;
            }
    }
    if(d[dist] == 0x3f3f3f3f) //該點無法到達
        printf("-1");
    else
        find_path(dist, parent);
    printf("\n");
}
int main()
{
    freopen("7input_1.txt", "r", stdin);
    scanf("%d", &n);
    int i, j;
    int w[n][n]; //一張有權重的圖
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &w[i][j]);
    scanf("%d %d", &source, &dist);
    source--;
    dist--;
    dijkstra(w);
    return 0;
}
