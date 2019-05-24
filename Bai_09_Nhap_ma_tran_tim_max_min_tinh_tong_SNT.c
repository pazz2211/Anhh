#include <stdio.h>
#include <math.h>
#define MAX 100

void nhapMaTran(int m[][MAX], int dong, int cot)
{
    int i,j;
    for (i=0; i<dong; i++)
        for (j=0; j<cot; j++)
            scanf("%d",&m[i][j]);
}

void inMaTran (int m[][MAX], int dong, int cot)
{
    int i,j;
    for (i=0; i<dong; i++)
    {
        for (j=0; j<cot; j++)
            printf("%4d",m[i][j]);
        printf("\n");
    }
}

int minMaTran (int m[][MAX], int dong, int cot)
{
    int i,j,min;
    min=m[0][0];
    for (i=0;i<dong; i++)
        for (j=0; j<cot; j++)
            if (m[i][j]<min)
                min = m[i][j];
    return min;
}

int maxMaTran (int m[][MAX], int dong, int cot)
{
    int i,j,max;
    max=m[0][0];
    for (i=0;i<dong; i++)
        for (j=0; j<cot; j++)
            if (m[i][j]>max)
                max = m[i][j];
    return max;
}

int laSNT (int n)
{
    if (n<2)
        return 0;
    int i;
    for (i=2; i<=sqrt(n);i++)
        if (n%i==0)
            return 0;
    return 1;
}

int tongSNT (int m[][MAX], int dong, int cot)
{
    int i, j, tong;
    tong = 0;
    for (i=0; i<dong; i++)
        for (j=0; j<cot; j++)
            tong += laSNT(m[i][j])?m[i][j]:0;
    return tong;
}

int main()
{
    int m[MAX][MAX];
    int dong, cot;
    printf("Nhap so dong: ");
    scanf("%d",&dong);
    printf("Nhap so cot: ");
    scanf("%d",&cot);
    nhapMaTran(m,dong,cot);

    printf("Ma tran vua nhap la:\n");
    inMaTran(m,dong,cot);

    printf("Max = %d, min = %d\n",maxMaTran(m,dong,cot),minMaTran(m,dong,cot));
    printf("Tong SNT = %d",tongSNT(m,dong,cot));
}
