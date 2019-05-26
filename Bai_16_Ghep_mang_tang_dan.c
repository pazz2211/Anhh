#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#define MAX 100

void menu()
{
    printf("\t ______________________________________ \n");
    printf("\t|                MENU                  |\n");
    printf("\t|--------------------------------------|\n");
    printf("\t| 1 - Nhap 2 mang tang dan             |\n");
    printf("\t| 2 - Ghep 2 day                       |\n");
    printf("\t| 3 - In 3 day so                      |\n");
    printf("\t| 4 - Ket thuc                         |\n");
    printf("\t|______________________________________|\n");
    printf("\tVui long chon: ");
}

int nhapSo ()
{
    int n;
    do
    {
        scanf("%d",&n);
        if (n<0)
            printf("\t\aNhap so lon hon 0!!! Nhap lai: ");
    }
    while (n<0);
    return n;
}

int nhapMang (int a[])
{
    int i, n;
    n = nhapSo();
    for (i=0; i<n; i++)
        scanf("%d",&a[i]);
    return n;
}

int laMangTangDan (int a[], int n)
{
    int i;
    for (i=1; i<n; i++)
        if (a[i]<a[i-1])
            return 0;
    return 1;
}

void inMang (int a[], int n)
{
    int i;
    printf("\t");
    for (i=0; i<n; i++)
        printf("%4d",a[i]);
    printf("\n");
}

//Ghep 2 mang, gia ve do dai mang tong
int ghepMang (int a1[], int a2[], int asum[], int n1, int n2)
{
    int i,j,k;
    //Chan cuoi mang voi so rat lon
    a1[n1] = 1<<30;
    a2[n2] = 1<<30;

    //Ghep 2 mang
    for (i=0,j=0,k=0; k<n1+n2;)
        asum[k++] = a1[i]<a2[j]?a1[i++]:a2[j++];
    return k;
}

int main()
{
    int chon;
    int a1[MAX], a2[MAX], a_sum[MAX];
    int flag1 = 0;
    int flag2 = 0;
    int n1,n2,nsum;

    while (1)
    {
        menu();
        fflush(stdin);
        scanf("%d",&chon);
        system("cls");
        switch(chon)
        {
            case 1:
                while (1)
                {
                    printf("\tNhap so phan tu mang 1: ");
                    n1 = nhapMang(a1);
                    if (!laMangTangDan(a1,n1))
                        printf("\tNhap lai, phai nhap mang tang dan\n");
                    else break;
                }

                while (1)
                {
                    printf("\tNhap so phan tu mang 2: ");
                    n2 = nhapMang(a2);
                    if (!laMangTangDan(a2,n2))
                        printf("\tNhap lai, phai nhap mang tang dan\n");
                    else break;
                }
                printf("\tBan da nhap xong 2 mang\n");
                flag1 = 1;
                break;
            case 2:
                if (flag1==0)
                {
                    printf("\t\aNhap mang da!!!\n");
                    break;
                }
                printf("\tBan da chon ghep 2 mang\n");
                nsum = ghepMang(a1,a2,a_sum,n1,n2);
                flag2 = 1;
                printf("\tGhep 2 mang thanh cong\n");
                break;
            case 3:
                if (flag1==0)
                {
                    printf("\t\aNhap mang truoc!!!\n");
                    break;
                }
                if (flag2==0)
                {
                    printf("\t\aChua ghep mang!!!\n");
                    break;
                }
                printf("\tBa mang vua nhap la: \n");
                inMang(a1,n1);
                inMang(a2,n2);
                inMang(a_sum,nsum);
                break;
            case 4:
                printf("\tBan da chon thoat. Xin chao!\n");
                exit(0);
            default:
                printf("\t\aNhap tu 1-4!!!\n");
                break;
        }
        printf("\tBam phim bat ki de ve menu\n");
        getch();
        system("cls");
    }
    return 0;
}

