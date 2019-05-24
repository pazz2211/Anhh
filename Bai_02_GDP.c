#include <stdio.h>

int main()
{
    int nam = 2014;
    float GDP,GDP_2014;
    float toc_do_tang_truong;

    printf("Nhap GDP nam 2014: ");
    scanf("%f",&GDP_2014);
    GDP = GDP_2014;

    printf("Nhap toc do tang truong (%%): ");
    scanf("%f",&toc_do_tang_truong);

    toc_do_tang_truong /= 100; //Chia lay phan tram

    printf("%8s%8s\n","Nam","GDP");
    while (1)
    {
        printf("%8d%8.1f\n",nam++,GDP*=toc_do_tang_truong);
        if (GDP >= 2* GDP_2014)
            break;
    }
    return 0;
}
