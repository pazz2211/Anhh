#include <stdio.h>

#define MAX 100

int nhapMang (int a[])
{
    int i,n;
    scanf("%d",&n);
    for (i=0; i<n; i++)
        scanf("%d",&a[i]);
    return n;
}

void inMang (int a[], int n)
{
    int i;
    for (i=0; i<n; i++)
        printf("%d ",a[i]);
    printf("\n");
}

int main()
{
    int a[MAX],n,i;
    int max, min;

    n = nhapMang(a);

    //Tim max, min
    for (max=min=a[0], i=0; i<n; i++)
    {
        max = a[i]>max?a[i]:max;
        min = a[i]<min?a[i]:min;
    }

    printf("Gia tri lon nhat cua mang la %d tai vi tri: ",max);
    for (i=0; i<n; i++)
        if (a[i]==max)
            printf("%d ",i+1);
    printf("\n");

    printf("Gia tri nho nhat cua mang la %d tai vi tri: ",min);
    for (i=0; i<n; i++)
        if (a[i]==min)
            printf("%d ",i+1);
    printf("\n");
}
