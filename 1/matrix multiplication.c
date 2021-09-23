#include <stdio.h>
#define sz 10000

int a[sz][sz], b[sz][sz], c[sz][sz];

int main()
{
    int n, m, p, q, k, i, j;
    printf("Enter the dimension of the matrix A(n m): ");
    scanf("%d %d", &n, &m);

    printf("Enter the dimension of the matrix B(m p): ");
    scanf("%d %d", &p, &q);

    if(m!=p)
        printf("Dimension Error!\nThe number of column of first matrix must be equal to the number of the rows of the second matrix.");

    else
    {
        printf("Enter the values of Matrix A: ");
        for (i = 0; i<n; i++)
            for (j=0; j<m; j++)
                scanf("%d", &a[i][j]);

        printf("Enter the values of Matrix B: ");
        for (i = 0; i<m; i++)
            for (j=0; j<q; j++)
                scanf("%d", &b[i][j]);

        /// Matrix Multiplication
        for (i = 0; i<n; i++)
            for (j=0; j<q; j++)
                for(k=0; k<m; k++)
                    c[i][j]+=a[i][k]*b[k][j];

        puts("Matrix C = A * B:");
        for (i = 0; i<n; i++)
            for (j=0; j<q; j++)
                printf("%4d%c", c[i][j]," \n"[j==q-1]);
    }
    return 0;
}
