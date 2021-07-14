#include<stdio.h>
int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;

int len[20];
int count = 0;

void bfs(int v)
{
    count++;
    for(i = 1; i <= n; i++)
        if(a[v][i] && !visited[i])
        {
            visited[i] = 1;
            len[i] = count;
            q[++r] = i;
        }
    if(f <= r)
    {

        bfs(q[f++]);
    }
    count--;
}

void main()
{
	setbuf(stdout, NULL);
    for (int k = 1; k < 20; k++)
        len[k] = 0;

    int v;
    printf("\n Enter the number of vertices:");
    scanf("%d", &n);

    for(i=1; i <= n; i++) {
        q[i] = 0;
        visited[i] = 0;
    }

    printf("\n Enter graph data in matrix form:\n");
    for(i=1; i<=n; i++) {
        for(j=1;j<=n;j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n Enter the starting vertex:");
    scanf("%d", &v);
    len[v] = 0;
    visited[v] = 1;
    bfs(v);
    printf("\n The node which are reachable are:\n");

    for(i=1; i <= n; i++) {
        if(visited[i])
            printf("%d\t", i);
        else {
            printf("\n Bfs is not possible. Not all nodes are reachable");
            break;
        }
    }
    int a;
    printf("\n");
    printf("Input A: ");
    scanf("%d", &a);
    printf("Finding : ");
    int x = 0;
    for (int k = 1; k < 20; k++)
        if (len[k] > 0 && len[k] <= a)
        {
            x++;
            printf("%d ", k);
        }
    if (x == 0)
        printf("Not found\n");
    printf("\n");

}

