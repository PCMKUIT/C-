#include<bits/stdc++.h>
using namespace std;

struct SinhVien{string HoTen;float DiemToan,DiemVan, DTB;};
void error(){cout<<"Diem khong hop le , vui long nhap lai: ";}
void Nhap(SinhVien &A){
	cout<<"Nhap ho ten: ";getline(cin,A.HoTen);
	cout<<"Nhap diem toan: ";cin>>A.DiemToan;while(A.DiemToan<0||A.DiemToan>10){error();cin>>A.DiemToan;}
	cout<<"Nhap diem van: ";cin>>A.DiemVan;while(A.DiemVan<0||A.DiemVan>10){error();cin>>A.DiemVan;}
	A.DTB=(A.DiemToan+A.DiemVan)/2;}

void Xuat(SinhVien &A){cout<<"Diem trung binh cua ban "<<A.HoTen<<" la: "<<A.DTB;}

int main (){
	SinhVien A;
	Nhap(A);
	Xuat(A);
	return 0;
}