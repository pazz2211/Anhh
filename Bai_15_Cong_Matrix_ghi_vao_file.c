#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define MAX 100

FILE* f = NULL;

void taoMatrixBatKy_file ()
{
    int r, c;
    int i, j;
    r = rand()%10+1;
    c = rand()%10+1;

    f = fopen ("MA_TRAN.C","w+");
    fprintf(f,"%d %d\n",r,c);

    //In ra ma tran A
    fprintf(f,"Ma tran A\n");
    for (i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
            fprintf(f,"%d ",rand()%100);
        fprintf(f,"\n");
    }

    //In ra ma tran B
    fprintf(f,"Ma tran B\n");
    for (i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
            fprintf(f,"%d ",rand()%100);
        fprintf(f,"\n");
    }

    fclose(f);
}

void docMatrix_file (int m1[][MAX], int m2[][MAX], int* r, int* c)
{
    char ch;
    int i, j;
    f = fopen("MA_TRAN.C","r");
    if (f==NULL)
    {
        printf("\tKhong mo duoc file!\n");
        return;
    }

    fscanf(f,"%d%d\n",r,c);

    //Doc xau "Ma tran A"
    while (1)
    {
        ch=fgetc(f);
        if (ch=='A')
            break;
    }

    //Nhap ma tran A vao mang
    for (i=0; i<*r; i++)
    {
        for (j=0; j<*c; j++)
            fscanf(f,"%d",&m1[i][j]);
    }

    //In ra man hinh ma tran A
    printf("\tMa tran A duoc nhap:\n");
    for (i=0; i<*r; i++)
    {
        for (j=0; j<*c; j++)
            printf("%4d",m1[i][j]);
        printf("\n");
    }
    printf("\tBam phim bat ky de nhap tiep ma tran B\n");
    getch();

    //Doc xau Ma tran B
    while (1)
    {
        ch=fgetc(f);
        if (ch=='B')
            break;
    }

    //Nhap ma tran B
    for (i=0; i<*r; i++)
    {
        for (j=0; j<*c; j++)
            fscanf(f,"%d",&m2[i][j]);
    }

    //In ra man hinh
    printf("\tMa tran B duoc nhap:\n");
    for (i=0; i<*r; i++)
    {
        for (j=0; j<*c; j++)
            printf("%4d",m2[i][j]);
        printf("\n");
    }
    printf("\tDoc 2 ma tran thanh cong!\n");
    fclose(f);
}

void inMatrixTong_file (int m1[][MAX], int m2[][MAX], int r, int c)
{
    int i,j;
    f = fopen("MA_TRAN.C","a");
    fprintf(f,"\nMa tran C\n",r,c);
    for (i=0; i<r; i++)
    {

        for (j=0; j<c; j++)
            fprintf(f,"%4d",m1[i][j]+m2[i][j]);
        fprintf(f,"\n");
    }
    fclose(f);
}



void menu()
{
    printf("\t ______________________________________ \n");
    printf("\t|                MENU                  |\n");
    printf("\t|--------------------------------------|\n");
    printf("\t| 1 - Doc 2 ma tran tu file            |\n");
    printf("\t| 2 - Ghi ma tran tong C vao cuoi tep  |\n");
    printf("\t| 3 - Tao 2 ma tran bat ky vao file    |\n");
    printf("\t| 4 - Ket thuc                         |\n");
    printf("\t|______________________________________|\n");
    printf("\tVui long chon: ");
}

int main()
{
    srand(time(NULL));
    int chon;
    int m1[MAX][MAX];
    int m2[MAX][MAX];
    int r,c;
    r = c = 0;
    while(1)
    {
        menu();
        scanf("%d",&chon);
        system("cls");
        switch (chon)
        {
            case 1:
                printf("\tBan da chon doc 2 ma tran tu file\n");
                docMatrix_file(m1,m2,&r,&c);
                break;
            case 2:
                printf("\tBan da chon ghi ma tran C vao cuoi tep\n");
                if (r==0)
                {
                    printf("\tVui long tao 2 ma tran da\n");
                    break;
                }


                inMatrixTong_file(m1,m2,r,c);
                break;
            case 3:
                printf("\tBan da chon tao 2 ma tran bat ky vao tep\n");
                taoMatrixBatKy_file();
                break;
            case 4:
                exit(0);
            default:
                printf("\tNhap cac so tu 1-4\n");
        }
        printf("\tNhap phim bat ky de ve menu");
        getch();
        system("cls");
    }
}
