#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    float x1, x2, delta;
    printf("Nhap he so: ");
    scanf("%f%f%f",&a,&b,&c);

    if (a==0)
        if (b==0)
            if (c==0)
                printf("Phuong trinh vo so nghiem");
            else
                printf("Phuong trinh vo nghiem");
        else
            printf("Phuong trinh co nghiem duy nhat x = %.2f",-c/b);
    else
    {
        delta = b*b - 4*a*c;
        if (delta<0)
            printf("Phuong trinh vo nghiem");
        else if (delta==0)
            printf("Phuong trinh co nghiem kep x1 = x2 = %.2f",-b/(2*a));
        else
        {
            x1 = (-b+sqrt(delta))/(2*a);
            x2 = (-b-sqrt(delta))/(2*a);
            printf("Phuong trinh co 2 nghiem:\n");
            printf("x1 = %.2f, x2 = %.2f",x1,x2);
        }
    }
    return 0;
}
