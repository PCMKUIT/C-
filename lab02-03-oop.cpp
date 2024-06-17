#include<bits/stdc++.h>
using namespace std;

class Candidate{
	private: int Ma,NgaySinh,ThangSinh,NamSinh;string HoTen;float DiemToan,DiemVan,DiemAnh;
	public:
	int leap(int y){return ((y%4==0&&y%100!=0)||y%400==0);}
	int dayinmonth(int m,int y){
  		switch(m){
    	case 1:case 3:case 5:case 7:case 8:case 10:case 12:{return 31;break;}
    	case 2:{if(leap(y)){return 29;}return 28;}
    	case 4:case 6:case 9:case 11:{return 30;}}}
    	
	void Birthday_input(){
		cout<<"Nam: ";cin>>this->NamSinh;
		cout<<"Thang: ";cin>>this->ThangSinh;
		while(this->ThangSinh<1||this->ThangSinh>12)
		{cout<<"Thang sinh khong hop le , vui long nhap lai: ";cin>>this->ThangSinh;}
		cout<<"Ngay: ";cin>>this->NgaySinh;
		while(this->NgaySinh<1||this->NgaySinh>31||(this->NgaySinh>(dayinmonth(this->ThangSinh,this->NamSinh)))) 
		{cout<<"Ngay sinh khong hop le , vui long nhap lai: ";cin>>this->NgaySinh;}
	}
	
	void error(){cout<<"Diem khong hop le , vui long nhap lai: ";}
	
	void Nhapthongtin(int x){
	cout<<"Nhap thong tin cua sinh vien thu "<<x+1<<": "<<'\n';
	cout<<"Nhap ma so thi sinh: ";cin>>this->Ma;fflush(stdin);
	cout<<"Nhap ho ten thi sinh: ";getline(cin,this->HoTen);fflush(stdin);
	cout<<"Nhap ngay, thang, nam sinh cua thi sinh: "<<'\n';Birthday_input();
	cout<<"Nhap diem toan: ";cin>>this->DiemToan;
	while(this->DiemToan<0||this->DiemToan>10){error();cin>>this->DiemToan;}
	cout<<"Nhap diem van: ";cin>>this->DiemVan;
	while(this->DiemVan<0||this->DiemVan>10){error();cin>>this->DiemVan;}
	cout<<"Nhap diem anh: ";cin>>this->DiemAnh;
	while(this->DiemAnh<0||this->DiemAnh>10){error();cin>>this->DiemAnh;}}
	
	float DiemTong(){return (this->DiemToan+this->DiemVan+this->DiemAnh);}
	
	void Xuat(){
		cout<<"Ho ten: "<<this->HoTen<<'\n';
		cout<<"Ma so thi sinh: "<<this->Ma<<'\n';
		cout<<"Ngay sinh: "<<this->NgaySinh<<"/"<<this->ThangSinh<<"/"<<this->NamSinh<<'\n';
		cout<<"Diem Toan: "<<this->DiemToan<<'\n';
		cout<<"Diem Van: "<<this->DiemVan<<'\n';
		cout<<"Diem Anh: "<<this->DiemAnh<<'\n';
		cout<<"Diem Tong: "<<DiemTong()<<'\n'<<'\n';}
};
class TestCandidate{
	private:int n; Candidate A[10000];
	public: 
	void Nhapdanhsach(){
		cout<<"Nhap so luong thi sinh: ";cin>>n;
		for(int i=0;i<n;i++){A[i].Nhapthongtin(i);}}
	
	void Kiemtravaxuat(){
		cout<<'\n'<<"Danh sach cac thi sinh co tong diem lon hon 15: "<<'\n'<<'\n';
		for(int i=0;i<n;i++){if(kiemtra(A[i])) A[i].Xuat();}}
		
	bool kiemtra(Candidate x){return (x.DiemTong()>15);}
};
int main (){
	TestCandidate a;
	a.Nhapdanhsach();
	a.Kiemtravaxuat();
	return 0;
}