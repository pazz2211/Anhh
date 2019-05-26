#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define MAX 100

void menu()
{
    printf("\t ______________________________________ \n");
    printf("\t|                MENU                  |\n");
    printf("\t|--------------------------------------|\n");
    printf("\t| 1 - Nhap n                           |\n");
    printf("\t| 2 - Tinh ma tran xoay                |\n");
    printf("\t| 3 - Hien thi ma tran xoay            |\n");
    printf("\t| 4 - Thoat                            |\n");
    printf("\t|______________________________________|\n");
    printf("\tVui long chon: ");
}


void tinhMatrix (int m[MAX][MAX], int n)
{
    //Định ra lề trái phải trên dưới
    int i, j;
    int top = 0;
    int left = 0;
    int bot = n-1;
    int right = n-1;
    j = 1;

    //Điền lần lượt giá trị vào ma trận theo chiều xoắn ốc, điền xong 1 đường thẳng là thu hẹp lề lại
    while (1)
    {

        //Điền từ trái qua phải ở lề trên
        for (i=left; i<=right; i++)
            m[top][i] = j++;
        top++;                          //Thu hẹp lề trên


        if (j>n*n)
            break;

        //Điền từ trên xuống dưới ở lề phải
        for (i=top; i<=bot; i++)
            m[i][right] = j++;
        right--;                        //Thu hẹp lề phải
        if (j>n*n)
            break;

        //Điền từ phải qua trái ở lề dưới
        for (i=right; i>=left; i--)
            m[bot][i] = j++;
        bot--;                          //Thu hẹp lề dưới

        if (j>n*n)
            break;

        //Điền từ dưới lên trên ở lề trái
        for (i=bot; i>=top; i--)
            m[i][left] = j++;
        left++;                         //Thu hẹp lề trái
        if (j>n*n)
            break;
    }
}

//In ma tran
void inMatrix (int m[MAX][MAX], int n)
{
    int i, j;
    for (i=0; i<n; i++)
    {
        printf("\t\t");
        for (j=0; j<n; j++)
            printf("%4d",m[i][j]);
        printf("\n");
    }
}

//Nhap so nguyen duong
int nhapSo()
{
    int n;
    do
    {
        scanf("%d",&n);
        if (n<0)
            printf("\t\aNhap n >= 0. Nhap lai: ");
    }
    while (n<0);
    return n;
}


int main()
{
    int select;
    int m[MAX][MAX];
    int flag1 = 0;
    int flag2 = 0;
    int n;
    while (1)
    {
        menu();
        scanf("%d",&select);
        system("cls");
        switch(select)
        {
            case 1:
                printf("\tBan da chon nhap kich co ma tran vuong\n");
                printf("\tNhap n: ");
                n = nhapSo();
                flag1 = 1;
                printf("\tBan da nhap ma tran vuong cap %d\n",n);
                break;
            case 2:
                if (flag1==0)
                {
                    printf("\t\aNhap n truoc!!!\n");
                    break;
                }
                printf("\tBan da chon tinh ma tran vuong cap %d\n",n);
                tinhMatrix(m,n);
                flag2 = 1;
                break;
            case 3:
                if (flag1==0)
                {
                    printf("\t\aNhap n truoc!!!\n");
                    break;
                }
                if (flag2==0)
                {
                    printf("\t\aTinh ma tran da!!!\n");
                    break;
                }
                printf("\tMa tran xoay cap %d la: \n",n);
                inMatrix(m,n);
                break;
            case 4:
                printf("\tBan da chon thoat, xin chao!");
                exit(0);
            default:
                printf("\t\aNhap cac so tu 1-4!!!\n");
                break;
        }
        printf("\tBam phim bat ky de ve menu\n");
        getch();
        system("cls");
    }

}

