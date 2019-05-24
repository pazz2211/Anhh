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

void sapXepMangTangDan (int a[], int n)
{
    int i, j, tmp;
    for (i=0; i<n-1; i++)
        for (j=i+1; j<n; j++)
            if (a[i]>a[j])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
}

int main()
{
    int arr[MAX], n;
    printf("Nhap so phan tu: ");
    n = nhapMang(arr);
    printf("Mang ban dau la: \n");
    inMang(arr,n);
    printf("Mang sau khi sap xep tang dan la: \n");
    sapXepMangTangDan(arr,n);
    inMang(arr,n);
    return 0;
}
