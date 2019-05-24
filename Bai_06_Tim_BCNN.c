#include <stdio.h>

int main()
{
    int a, b, i;
    printf("Nhap 2 so: ");
    scanf("%d%d",&a,&b);
    for (i= a>b?a:b;;i++)
        if (i%a==0&&i%b==0)
            break;
    printf("BCNN(%d,%d) = %d",a,b,i);
    return 0;
}
