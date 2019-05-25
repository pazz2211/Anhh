#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

typedef struct
{
	char ho_ten[25];
	int tuoi;
	float diem_TB;
}SinhVien;

typedef struct node
{
	SinhVien du_lieu;
	struct node* tiep;
}node;

node* list = NULL;

SinhVien nhapDuLieu ()
{
	SinhVien sv;
	printf("\tNhap ten: ");
	fflush(stdin);
	gets(sv.ho_ten);
	printf("\tNhap tuoi: ");
	scanf("%d",&sv.tuoi);
	printf("\tNhap diem: ");
	scanf("%d",&sv.diem_TB);
	return sv;
}

node* taoNode ()
{
	//Cap phat dong
	node* pnode = (node*)malloc (sizeof(node));

	//Them du lieu
	pnode->du_lieu = nhapDuLieu();

	//Tro tiep
	pnode->tiep = NULL;

	return pnode;
}

void taoNodeDauTien ()
{
	node* pnode = taoNode();
	list = pnode;
}

void taoNodeViTri_Cuoi()
{
	if (list == NULL)
		taoNodeDauTien();
	else
	{
		//Tao node moi
		node* pnode = taoNode();

		//Tim vi tri cuoi cung
		node* tmp;
		for (tmp = list; tmp->tiep!= NULL; tmp = tmp->tiep);

		//Them pnode vao sau cung
		tmp->tiep = pnode;
	}

}

void hienThiDanhSach()
{
	//In ra Tieu de danh sach
	printf("\t\tDANH SACH\n");
	printf("\t%4s|%-20s|%5s|%6s|\n","STT","Ho ten","Tuoi","DiemTB");

	//Duyet tung phan tu cua danh sach va in gia tri tung phan tu
	int i;
	node* tmp;
	for (tmp = list, i=1; tmp!=NULL; tmp = tmp->tiep)
		printf("\t%4d|%-20s|%5d|%6.2f|\n",i++,tmp->du_lieu.ho_ten,tmp->du_lieu.tuoi,tmp->du_lieu.diem_TB);
}

//Kiem tra ten 1 nguoi co phai thuoc danh sach hay khong
node* laSinhVien(char ten[])
{
	//Duyet tung phan tu cua danh sach, neu co ten thi gia ve node chua ten do
	node* tmp;
	int i;
	for (tmp = list, i=1; tmp!=NULL; tmp = tmp->tiep)
		if (strcmp(tmp->du_lieu.ho_ten,ten)==0)
			return tmp;
	return NULL;
}

//Chen sinh vien theo ten
void chenSinhVienTheoTen (char ten[])
{
	if (laSinhVien(ten) == NULL)
		printf("\tKhong co sinh vien %s trong danh sach\n",ten);
	else
	{
		//Neu co sinh vien, tim vi tri sinh vien do trong danh sach
		node* tmp = laSinhVien(ten);

		//Tao sinh vien moi
		node* pnode = taoNode();

		//Chen sinh vien moi vao sau sinh vien co ten vua nhap
		pnode->tiep = tmp->tiep;
		tmp->tiep = pnode;
	}
}

void xoaSinhVienTheoTen (char ten[])
{
	if (laSinhVien(ten) == NULL)
		printf("\tKhong co sinh vien %s trong danh sach\n",ten);
	else
	{
		//Neu co sinh vien, tim vi tri sinh vien do trong danh sach
		node* del = laSinhVien(ten);

		//Neu day la sinh vien dau tien trong danh sach
		if (del == list)
		{
			list = del->tiep;
			free(del);
		}
		else
		{
		    node* tmp;
			//Tim vi tri sinh vien truoc sinh vien can xoa
			for (tmp = list; tmp->tiep!=del; tmp = tmp->tiep);

			//Xoa sinh vien
			tmp->tiep = del->tiep;
			free(del);
		}
	}
}

void suaSinhVienTheoTen (char ten[])
{
	if (laSinhVien(ten) == NULL)
		printf("\tKhong co sinh vien %s trong danh sach\n",ten);
	else
	{
		//Neu co sinh vien, tim vi tri sinh vien do trong danh sach
		node* tmp = laSinhVien(ten);

		//Nhap lai du lieu cho sinh vien tren
		tmp->du_lieu = nhapDuLieu();
	}
}

void hienThiMenu()
{
	printf("\t\tMENU\n");
	printf("\t1. Tao danh sach sinh vien\n");
	printf("\t2. Hien thi danh sach sinh vien\n");
	printf("\t3. Them sinh vien theo ten\n");
	printf("\t4. Xoa mot sinh vien\n");
	printf("\t5. Sua mot sinh vien\n");
	printf("\t6. Ket thuc\n");
	printf("\t\tVui long chon: ");
}

void taoDanhSachSinhVien ()
{
	for (int i = 1;;i++)
	{
		printf("\tNhap sinh vien thu %d\n",i);
		taoNodeViTri_Cuoi();
		printf("\tNhap tiep? (y/n) \n");
		fflush(stdin);
		char c = getch();
		if (c=='n'||c=='N')
			break;
	}
}


int main()
{
	int chon;
	char ten[20];
	while (1)
	{
		system("cls");
		hienThiMenu();
		scanf("%d",&chon);

		switch (chon)
		{
			case 1:
				system("cls");
				printf("\tBan da chon tao danh sach sinh vien\n");
				taoDanhSachSinhVien();
				printf("\tBam phim bat ky de tro ve menu");
				getch();
				break;
			case 2:
				system("cls");
				printf("\tBan da chon hien thi danh sach sinh vien\n");
				if (list==NULL)
					printf("\tVui long nhap danh sach sinh vien truoc\n");
				else
				{
					hienThiDanhSach();
				}
				printf("\tBam phim bat ky de tro ve menu");
				getch();
				break;
			case 3:
				system("cls");
				printf("\tBan da chon chen sinh vien theo ten\n");
				if (list==NULL)
					printf("\tVui long nhap danh sach sinh vien truoc\n");
				else
				{
					printf("\tNhap ten sinh vien ma ban muon chen dang sau: ");
					fflush(stdin);
					gets(ten);
					chenSinhVienTheoTen(ten);
				}
				printf("\tBam phim bat ky de tro ve menu");
				getch();
				break;
			case 4:
				system("cls");
				printf("\tBan da chon xoa sinh vien theo ten\n");
				if (list==NULL)
					printf("\tVui long nhap danh sach sinh vien truoc\n");
				else
				{
					printf("\tNhap ten sinh vien ma ban muon xoa: ");
					fflush(stdin);
					gets(ten);
					xoaSinhVienTheoTen(ten);
				}
				printf("\tBam phim bat ky de tro ve menu");
				getch();
				break;
			case 5:
				system("cls");
				printf("\tBan da chon sua sinh vien theo ten\n");
				if (list==NULL)
					printf("\tVui long nhap danh sach sinh vien truoc\n");
				else
				{
					printf("\tNhap ten sinh vien ma ban muon sua: ");
					fflush(stdin);
					gets(ten);
					suaSinhVienTheoTen(ten);
				}
				printf("\tBam phim bat ky de tro ve menu");
				getch();
				break;
			case 6:
				system("cls");
				printf("\tBan da chon thoat khoi chuong trinh! Bye~");
				getch();
				exit(0);
			default:
				printf("\tNhap cac so tu 1 den 6\n");
				printf("\tBam phim bat ky de tro ve menu");
				getch();
		}
	}
	return 0;
}
