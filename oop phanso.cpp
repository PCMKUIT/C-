#include <bits/stdc++.h>
using namespace std;
class PhanSo{
	private: int tu,mau;
	public: 
	void Nhap1(){cout<<"Nhap tu so: ";cin>>this->tu;
		 		 cout<<"Nhap mau so: ";cin>>this->mau; 
				 while(this->mau==0){cout<<"Mau so khong hop le , vui long nhap lai: ";cin>>this->mau;}}
		 		
	void Nhap2(){cout<<"Nhap tu so: ";cin>>this->tu;
				 while(this->tu==0){cout<<"Tu so khong hop le , vui long nhap lai: ";cin>>this->tu;}
		 		 cout<<"Nhap mau so: ";cin>>this->mau; 
				 while(this->mau==0){cout<<"Mau so khong hop le , vui long nhap lai: ";cin>>this->mau;}}
		 		
	void Xuat(){if(this->mau==1)cout<<this->tu<<endl;
				else cout<<this->tu<<"/"<<this->mau<<endl;}
				
	PhanSo Cong (PhanSo b){
		PhanSo c;
		c.tu=tu*b.mau+mau*b.tu;
		c.mau=mau*b.mau;
		return c;}
		
	PhanSo Tru (PhanSo a,PhanSo b){
		PhanSo c;
		c.tu=a.tu*b.mau-a.mau*b.tu;
		c.mau=a.mau*b.mau;
		return c;}
		
	PhanSo Nhan (PhanSo a,PhanSo b){
		PhanSo c;
		c.tu=a.tu*b.tu;
		c.mau=a.mau*b.mau;
		return c;}
		
	PhanSo Chia (PhanSo a,PhanSo b){
		PhanSo c;
		c.tu=a.tu*b.mau;
		c.mau=a.mau*b.tu;
		return c;}

	void Rutgon (PhanSo a){
		if(this->mau<0) {this->mau=-this->mau;this->tu=-this->tu;}
		int d=__gcd(abs(this->mau),abs(this->tu));
		this->mau/=d;
        this->tu/=d;}
	};

int main (){
	PhanSo a,b,c,d,e,f;
	cout<<"Phan so thu nhat:"<<'\n';a.Nhap1();
	cout<<"Phan so thu hai:"<<'\n';b.Nhap2();
	cout<<"Tong hai phan so la: ";c=a.Cong(b);c.Rutgon(c);c.Xuat();
	cout<<"Hieu hai phan so la: ";d=d.Tru(a,b);d.Rutgon(d);d.Xuat();
	cout<<"Tich hai phan so la: ";e=e.Nhan(a,b);e.Rutgon(e);e.Xuat();
	cout<<"Thuong hai phan so la: ";f=f.Chia(a,b);f.Rutgon(f);f.Xuat();
	return 0;}