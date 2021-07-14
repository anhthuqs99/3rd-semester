#include<stdio.h>
int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;


int count = 0;
int len[20];

void bfs(int v)
{
    count++;
 for(i = 1; i <= n; i++)
 if(a[v][i] && !visited[i])
 {
     printf("%d %d\n", i, count);
 q[++r] = i;
 len[i] = count;
 }

 if(f <= r)
 {
     //len[q[f]] = count;
 visited[q[f]] = 1;
 //count++;
 bfs(q[f++]);
 printf("fkhf\n");
 }
}

void main() {
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

 int a;
 printf("Input A: ");
 scanf("%d", &a);
 for (int k = 0; k < 20; k++)
     len[k] = 0;

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
 printf("\n");
 printf("\n");
 for (int k = 0; k < 4; k++)
     //if (len[k] <= a - 1 && len[k] > 0)
         printf("%d ", k);
 printf("\n");

}
