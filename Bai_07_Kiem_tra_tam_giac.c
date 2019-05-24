#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Nhap 3 canh tam giac: ");
    scanf("%d%d%d",&a,&b,&c);
    if (a+b<=c||b+c<=a||c+a<=b)
        printf("(%d,%d,%d) khong phai 3 canh tam giac",a,b,c);
    else
    {
        if (a==b&&b==c)
            printf("(%d, %d, %d) la tam giac deu",a,b,c);
        else if (a==b||b==c||c==a)
            printf("(%d, %d, %d) la tam giac can",a,b,c);
        else if (a*a+b*b==c*c||b*b+c*c==a*a||c*c+a*a==b*b)
            printf("(%d, %d, %d) la tam giac vuong",a,b,c);
        else
            printf("(%d, %d, %d) la tam giac thuong",a,b,c);
    }

}
