#include<stdio.h>
int main()
{
	int adj[100][100], i, j, k, n, m, q, x;
	scanf("%d %d", &n, &m);
	for(i=0; i<m; i++)
	{
		scanf("%d %d %d", &x, &q, &j);
		adj[x][q]=j;
		adj[q][x]=j;
	}
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			printf("%d%c", adj[i][j], " \n"[j==n-1]);
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			for(k=0; k<n; k++)
				if(adj[j][i] && adj[i][k] && j!=k)
					if(!adj[j][k] || adj[j][k] > adj[j][i] + adj[i][k])
						adj[j][k] = adj[j][i] + adj[i][k];
	puts("");
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			printf("%2d%c", adj[i][j], " \n"[j==n-1]);
	return 0;
}