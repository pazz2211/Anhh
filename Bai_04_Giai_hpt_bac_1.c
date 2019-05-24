#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, d, e, f, dx, dy, dd;
    printf("\tNhap cac he so a, b, c, d, e, f: ");
    scanf("%lf %lf %lf",&a,&b,&e);
    scanf("%lf %lf %lf",&c,&d,&f);
    printf("\tHe phuong trinh co dang:\n");
    printf("\t\t%.1fx + %.1fy = %.1f\n",a,b,e);
    printf("\t\t%.1fx + %.1fy = %.1f\n",c,d,f);
    dd = a*d - b*c;
    dx = e*d - b*f;
    dy = a*f - e*c;
    if (dd==0)
    {
        if((dx==0)&&(dy==0))
        {
            printf("\tHe phuong trinh co vo so nghiem");
        }
        else if ((dx==0&&dy!=0)||(dy==0&&dx!=0))
        {
            printf("\tHe phuong trinh vo nghiem");
        }
    }
    else
    {
        printf("\tHe phuong trinh co nghiem duy nhat\n");
        printf("\tx = %.2f\n",dx/dd);
        printf("\ty = %.2f",dy/dd);
    }
    return 0;
}
