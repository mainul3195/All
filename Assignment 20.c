#include <stdio.h>
#define sz 10

int adj[sz][sz];

int main()
{
    int n, m, i, x, y, z, j, q, k;
    scanf("%d %d", &n, &m);

    for (i=0; i<m; i++)
    {
        scanf("%d %d %d", &x, &y, &j);
        adj[x][y] = j; 
        adj[y][x] = j;
    }

    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            for (k=0; k<n; k++)
                if(adj[j][i] && adj[i][k] && j!=k && (!adj[j][k] || adj[j][k] > adj[j][i] + adj[i][k]))
                    adj[j][k] = adj[j][i] + adj[i][k];

//    for (i=0; i<n; i++)
//        for (j=0; j<n; j++)
//            printf("%3d%c",adj[i][j]," \n"[j==n-1]);

    scanf("%d", &q); //Enter number of queries
    for (i=0; i<q; i++)
    {
        scanf("%d %d", &x, &y); //Enter two node to calculate shortest path
        if(!adj[x][y])
            printf("Shortest path from node %d to %d: Unable to reach at desired node\n", x,y);
        else
            printf("Shortest path from node %d to %d: %d\n", x,y,adj[x][y]);
    }
    return 0;

}
/**
10 9
0 1 5
0 5 1
2 3 4
1 2 3
8 2 1
5 3 6
4 9 1
5 8 2
9 7 2
10
8 3
9 6
0 3
1 3
2 7
3 3
7 4
6 4
4 5
5 1
*/