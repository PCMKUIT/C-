#include<bits/stdc++.h>
using namespace std;
int n;
struct SinhVien{ 
int MSSV;
string TEN;
int TUOI;
float MON1,MON2,MON3;};
vector <SinhVien> DuLieu;
void Nhap(SinhVien &A){
	cout<<"Nhap MSSV: "; cin>>A.MSSV;
	cin.ignore();
	cout<<"Nhap ten: "; getline(cin,A.TEN);
	cout<<"Nhap tuoi: "; cin>>A.TUOI;
	cout<<"Nhap diem mon 1: "; cin>>A.MON1;
	cout<<"Nhap diem mon 2: "; cin>>A.MON2;
	cout<<"Nhap diem mon 3: "; cin>>A.MON3;}
void Xuat(SinhVien &A){
	cout<<"MSSV: "<<A.MSSV;
	cout<<"\nTen: "<<A.TEN;
	cout<<"\nTuoi: "<<A.TUOI;
	cout<<"\nDiem mon 1: "<<A.MON1;
	cout<<"\nDiem mon 2: "<<A.MON2;
	cout<<"\nDiem mon 3: "<<A.MON3;
	float DTB=(A.MON1+A.MON2+A.MON3)/3;
	DTB=round(DTB*100)/100;
	cout<<"\nDiem trung binh mon: "<<DTB;}
void NhapDuLieu(){
	cout<<"Nhap so luong sinh vien: "; cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Nhap thong tin cho sinh vien thu "<<i+1<<":\n";
		DuLieu.resize(i+1); Nhap(DuLieu.back());}
		cout<<"\n";}
void XuatDuLieu(){
	cout<<"\nSo luong sinh vien: "<<DuLieu.size();
	for(int i = 0; i < DuLieu.size(); i++){
		cout<<"\nThong tin cua doi tuong thu "<<i+1<<":\n";
		Xuat(DuLieu[i]);}
}
int main(){
	DuLieu.resize(0);
	NhapDuLieu();
	XuatDuLieu();
	return 0;}