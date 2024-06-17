#include <bits/stdc++.h>
using namespace std;
struct PhanSo{int tu;int mau;};
void Nhap1(PhanSo &a){
		cout<<"Nhap tu so: ";cin>>a.tu;
		cout<<"Nhap mau so: ";cin>>a.mau;
	 while(a.mau==0){cout<<"Mau so khong hop le , vui long nhap lai: ";cin>>a.mau;}}

void Nhap2(PhanSo &b){
		cout<<"Nhap tu so: ";cin>>b.tu;
	 while(b.tu==0){cout<<"Tu so khong hop le , vui long nhap lai: ";cin>>b.tu;}
		cout<<"Nhap mau so: ";cin>>b.mau;
	 while(b.mau==0){cout<<"Mau so khong hop le , vui long nhap lai: ";cin>>b.mau;}}
	 
void Xuat(PhanSo a){  
 	if(a.mau<0){a.mau=-a.mau;a.tu=-a.tu;}
    int c=__gcd(abs(a.tu),abs(a.mau));a.tu/=c;a.mau/=c;
                if (a.mau==1) cout<<a.tu<<endl;
                else cout<<a.tu<<"/"<<a.mau<<endl;}

PhanSo Cong(PhanSo a,PhanSo b){
	PhanSo c;
    c.tu= a.tu*b.mau +a.mau*b.tu;
    c.mau=a.mau*b.mau;
    return c;}
    
PhanSo Tru(PhanSo a,PhanSo b){
	PhanSo c;
    c.tu= a.tu*b.mau -a.mau*b.tu;
    c.mau=a.mau*b.mau;
    return c;}
    
PhanSo Nhan(PhanSo a,PhanSo b){
	PhanSo c;
    c.tu= a.tu*b.tu;
    c.mau=a.mau*b.mau;
	return c;}
	
PhanSo Chia(PhanSo a,PhanSo b){
	PhanSo c;
    c.tu= a.tu*b.mau ;
    c.mau=a.mau*b.tu;
    return c;}
    
int main(){
    PhanSo a,b;
    cout<<"Phan so thu nhat:"<<'\n';Nhap1(a);
    cout<<"Phan so thu hai:"<<'\n';Nhap2(b);
    cout<<"Tong hai phan so la: ";Xuat(Cong(a,b));
    cout<<"Hieu hai phan so la: ";Xuat(Tru(a,b));
	cout<<"Tich hai phan so la: ";Xuat(Nhan(a,b));
    cout<<"Thuong hai phan so la: ";Xuat(Chia(a,b));
    return 0;}