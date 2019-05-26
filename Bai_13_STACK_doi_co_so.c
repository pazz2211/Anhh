#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 100

//Mot Stack se co 2 thanh phan: mang du lieu va vi tri du lieu dinh?
typedef struct
{
    int top;
    int data[MAX];
}TStack;

//refresh stack
void taoStack (TStack* stack)
{
    stack->top = 0;
}

//Kiem tra xem stack rong hay khong
int isEmpty(TStack* stack)
{
    return (stack->top == 0);
}

//Kiem tra stack day hay chua
int isFull (TStack* stack)
{
    return (stack->top == MAX);
}

//Them 1 phan tu vao stack
void push (TStack* stack, int x)
{
    if (!isFull(stack))
    {
        stack->data[stack->top] = x;
        stack->top++;
    }
}

//Lay du lieu tren cung
int peak (TStack* stack)
{
    return stack->data[stack->top-1];
}

//Xoa du lieu tren cung va return gia tri ra ngoai
int pop (TStack* stack)
{
    if (!isEmpty(stack))
    {
        stack->top--;
        return stack->data[stack->top];
    }
}

//Nhap gia tri 1 stack
void inputStack (TStack* stack)
{
    int x;
    while (1)
    {
        printf("\tNhap phan tu: ");
        scanf("%d",&x);
        push(stack,x);
        printf("\tNhap tiep? y/n: ");
        fflush(stdin);
        char tmp = getchar();
        if (tmp=='n'||tmp=='N')
            break;
    }
}

//Hien thi du lieu 1 stack
void outputStack (TStack* stack)
{
    int i;
    for (i=stack->top-1; i>=0; i--)
        printf("%d",stack->data[i]);
}

void heCoSo_2 (TStack* stack, int n)
{
    while (n>0)
    {
        push(stack,n%2);
        n/=2;
    }
}

void heCoSo_8(TStack* stack, int n)
{
    while (n>0)
    {
        push(stack,n%8);
        n/=8;
    }
}

void menu()
{
    printf("\t ____________________________________________________ \n");
    printf("\t|                         MENU                       |\n");
    printf("\t|----------------------------------------------------|\n");
    printf("\t| 1. Nhap n                                          |\n");
    printf("\t| 2. Chuyen sang he co so 2                          |\n");
    printf("\t| 3. Chuyen sang he co so 8                          |\n");
    printf("\t| 4. Chuyen sang he co so 16                         |\n");
    printf("\t| 0. Exit                                            |\n");
    printf("\t|____________________________________________________|\n");
    printf("\t\tVui long chon: ");
}

int main()
{
    int n = -1;
    int chon;
    TStack stack;
    taoStack(&stack);
    while (1)
    {
        menu();
        scanf("%d",&chon);
        system("cls");
        switch (chon)
        {
            case 1:
                printf("\tBan da chon nhap n \n");
                while (1)
                {
                    printf("\t\tNhap n: ");
                    scanf("%d",&n);
                    if (n<=0)
                        printf("\tVui long nhap so nguyen duong\n");
                    else
                        break;
                }

                break;
            case 2:
                if (n<=0)
                {
                    printf("\tNhap n truoc!!!\n");
                    break;
                }
                printf("\tBan da chon doi sang co so 2\n");

                heCoSo_2(&stack,n);
                printf("\t\t%d(10) = ",n);
                outputStack(&stack);
                printf("(2)\n");

                //Xoa Stack di
                taoStack(&stack);
                break;
            case 3:
                if (n<=0)
                {
                    printf("\tNhap n truoc!!!\n");
                    break;
                }
                printf("\tBan da chon doi sang co so 8\n");

                heCoSo_8(&stack,n);
                printf("\t\t%d(10) = ",n);
                outputStack(&stack);
                printf("(8)\n");

                taoStack(&stack);
                break;

            case 4:
                if (n<=0)
                {
                    printf("\tNhap n truoc!!!\n");
                    break;
                }
                printf("\tBan da chon doi sang co so 16\n");
                printf("\t\t%d(10) = 0X%x(16)\n",n,n);
                break;
            case 0:
                exit(0);
            default:
                printf("\tBan da chon sai, vui long chon lai\n\a");
                break;
        }
        printf("\tBam phim bat ki de ve menu\n");
        getch();
        system("cls");
    }
    return 0;
}
