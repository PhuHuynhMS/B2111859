#include<stdio.h>

#include<string.h>

#define Maxlength 40

typedef struct{
	char mssv[10];
	char hoten[50];
	float DiemLT, DiemTH1, DiemTH2;
}SinhVien;

typedef struct{
	SinhVien A[Maxlength];
	int n;
}DanhSach;

void dsRong(DanhSach *pL){
	(*pL).n = 0;
}

void nhap(DanhSach *pL){
	dsRong(pL);
	scanf("%d",&(*pL).n);
	for(int i = 0 ; i <(*pL).n ; i++){
		scanf(" ");
		fgets((*pL).A[i].mssv,sizeof((*pL).A[i].mssv),stdin);
		if((*pL).A[i].mssv[strlen((*pL).A[i].mssv) - 1] == '\n')
			(*pL).A[i].mssv[strlen((*pL).A[i].mssv) - 1] = '\0';
		fgets((*pL).A[i].hoten,sizeof((*pL).A[i].hoten),stdin);
		if((*pL).A[i].hoten[strlen((*pL).A[i].hoten) - 1] == '\n')
			(*pL).A[i].hoten[strlen((*pL).A[i].hoten) - 1] = '\0';
		scanf("%*c");
		scanf("%f %f %f",&(*pL).A[i].DiemLT,&(*pL).A[i].DiemTH1,&(*pL).A[i].DiemTH2);	
	}
}

void hienThi(DanhSach L){
	for(int i = 0 ; i < L.n ; i++){
		printf("%s - %s - %.2f - %.2f - %.2f\n",L.A[i].mssv,L.A[i].hoten,L.A[i].DiemLT,L.A[i].DiemTH1,L.A[i].DiemTH2);
	}
}

void tim_kiem(char ms[], DanhSach L){
	int temp = 0;
	for(int i = 0 ; i < L.n ; i++){
		if(strcmp(L.A[i].mssv, ms)){
			temp = 1;
			printf("Tim thay sinh vien %s. Thong tin sinh vien:\n%s - %s - %.2f - %.2f - %.2f",L.A[i].mssv,L.A[i].mssv,L.A[i].hoten,L.A[i].DiemLT,L.A[i].DiemTH1,L.A[i].DiemTH2);
		}		
	}
	if(temp == 0)
		printf("Khong tim thay sinh vien %s",ms);
}

void xoaSV(char ms[], DanhSach *pL){
	for(int i = 0 ; i < (*pL).n ; i++){
		if(strcmp((*pL).A[i].mssv, ms)){
			for(int j = i; j < (*pL).n - 1 ; j++)
				(*pL).A[j] = (*pL).A[j+1];
			(*pL).n --;
		}
}
}

int main(){
	DanhSach L;
	nhap(&L);
	hienThi(L);
	scanf(" ");
	char msct[10];
	fgets(msct,sizeof(msct),stdin);
	if(msct[strlen(msct) - 1] == '\n')
		msct[strlen(msct) - 1] = '\0';
	tim_kiem(msct,L);
	xoaSV(msct,&L);
	printf("bla bla bla");
	return 0;
}
