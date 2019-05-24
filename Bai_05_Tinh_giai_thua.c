#include <stdio.h>

int main()
{
    int n, i, gt;
    printf("Nhap n: ");
    scanf("%d",&n);
    for (gt=i=1; i<=n; gt*=i++);
    printf("%d! = %d",n,gt);
    return 0;
}
