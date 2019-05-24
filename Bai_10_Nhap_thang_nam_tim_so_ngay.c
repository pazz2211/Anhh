#include <stdio.h>

int laNhuan (int nam)
{
    if (nam%400==0)
        return 1;
    if (nam%100==0)
        return 0;
    if (nam%4==0)
        return 1;
    return 0;
}

int main()
{
    int thang, nam;
    printf("Nhap thang: ");
    scanf("%d",&thang);
    printf("Nhap nam: ");
    scanf("%d",&nam);
    switch (thang)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            printf("Thang %d nam %d co 31 ngay",thang,nam);
            break;
        case 2:
            printf("Thang %d nam %d co %d ngay",thang,nam,laNhuan(nam)?29:28);
            break;
        case 4: case 6: case 9: case 11:
            printf("Thang %d nam %d co 30 ngay",thang,nam);
            break;
        default:
            printf("Thang nhap khong hop le");
    }

}
