#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#define MAX 100

void menu()
{
    printf("\t ______________________________________ \n");
    printf("\t|                MENU                  |\n");
    printf("\t|--------------------------------------|\n");
    printf("\t| 1 - Nhap he so da thuc               |\n");
    printf("\t| 2 - Tinh he so da thuc tong          |\n");
    printf("\t| 3 - In he so 3 da thuc               |\n");
    printf("\t| 4 - In gia tri 3 da thuc             |\n");
    printf("\t| 5 - Ket thuc                         |\n");
    printf("\t|______________________________________|\n");
    printf("\tVui long chon: ");
}

int nhapSo()
{
    int n;
    do
    {
        scanf("%d",&n);
        if (n<0)
            printf("\t\aSo phan tu phai lon hon 0!!! Nhap lai: ");
    }
    while (n<0);
    return n;
}

int nhapMang (int a[])
{
    int i, n;
    n = nhapSo();
    printf("\tNhap tung he so: ");
    for (i=MAX-n; i<MAX; i++)
        scanf("%d",&a[i]);
    return n;
}

void inMang (int a[], int n)
{
    int i, flag;
    printf("\t");
    for (i=MAX-n,flag=0; i<MAX; i++)
    {
        if (a[i]==0&&flag==0)
            printf("%4s","");
        else
        {
            printf("%4d",a[i]);
            flag=1;
        }
    }
    printf("\n");
}

void ganZero (int a[], int n)
{
    int i;
    for (i=0; i<n; i++)
        a[i] = 0;
}


int tongMang(int a1[], int a2[], int a_sum[], int n1, int n2)
{
    int i;
    for (i=0; i<MAX; a_sum[i]=a1[i]+a2[i++]);
    return n1<n2?n2:n1;
}

float giaTriDaThuc (int a[], float x, int n)
{
    int i;
    float sum;
    for (i=n-1,sum=0; i>=0; i--)
        sum+=a[i]*pow(x,n-i-1);
    return sum;
}

int main()
{
    int select;
    int a1[MAX] = {0}, a2[MAX] = {0}, a_sum[MAX] = {0};
    int flag1 = 0;
    int flag2 = 0;
    int n1, n2, n_sum;
    while (1)
    {
        menu();
        scanf("%d",&select);
        system("cls");
        switch(select)
        {
            case 1:
                //Xoa cac da thuc cu
                ganZero(a1,MAX);
                ganZero(a2,MAX);
                ganZero(a_sum,MAX);

                //Nhap da thuc moi
                printf("\tBan chon nhap he so da thuc: \n");
                printf("\tDa thuc thu nhat \n");
                printf("\tNhap so bac: ");
                n1 = nhapMang(a1);
                printf("\tBan da nhap xong da thuc thu nhat\n");
                printf("\tDa thuc thu hai \n");
                printf("\tNhap so bac: ");
                n2 = nhapMang(a2);
                printf("\tBan da nhap xong da thuc thu hai\n");
                flag1 = 1;
                break;
            case 2:
                if (flag1==0)
                {
                    printf("\t\aNhap cac da thuc truoc!!!\n");
                    break;
                }
                printf("\tBan da chon tinh tong 2 da thuc\n");
                n_sum = tongMang(a1,a2,a_sum,n1,n2);
                flag2 = 1;
                break;
            case 3:
                if (flag1==0)
                {
                    printf("\t\aNhap cac da thuc truoc!!!\n");
                    break;
                }
                if (flag2==0)
                {
                    printf("\t\aTinh da thuc tong da!!!\n");
                    break;
                }
                printf("\tBan da chon hien thi he so cac da thuc\n");
                printf("\tHe so cac da thuc: \n");
                printf("\t%-12s ","Da thuc 1:");
                inMang(a1,n_sum);
                printf("\t%-12s ","Da thuc 2:");
                inMang(a2,n_sum);
                printf("\t%-12s ","Da thuc tong:");
                inMang(a_sum,n_sum);
                break;
            case 4:
                if (flag1==0)
                {
                    printf("\t\aNhap cac da thuc truoc!!!\n");
                    break;
                }
                if (flag2==0)
                {
                    printf("\t\aTinh da thuc tong da!!!\n");
                    break;
                }
                printf("\tBan da chon tinh cac da thuc\n");
                float x;
                printf("\tNhap gia tri x: ");
                scanf("%f",&x);
                printf("\tHe so cac da thuc: \n");
                inMang(a1,n_sum);
                inMang(a2,n_sum);
                inMang(a_sum,n_sum);
                printf("\tGia tri cua da thuc 1 = %.2f\n",giaTriDaThuc(a1,x,MAX));
                printf("\tGia tri cua da thuc 2 = %.2f\n",giaTriDaThuc(a2,x,MAX));
                printf("\tGia tri cua da thuc tong = %.2f\n",giaTriDaThuc(a_sum,x,MAX));
                break;
            case 5:
                printf("\tBan da chon thoat. Xin chao!\n");
                exit(0);
            default:
                printf("\t\aNhap tu 1-5!!!\n");
                break;
        }
        printf("\tBam phim bat ky de ve menu\n");
        getch();
        system("cls");
    }

    return 0;
}


