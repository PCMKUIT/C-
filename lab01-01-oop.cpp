#include <bits/stdc++.h>
using namespace std;
struct PhanSo{int tu;int mau;};
void Nhap(PhanSo &a){
		cout<<"Nhap tu so: ";cin>>a.tu;
		cout<<"Nhap mau so: ";cin>>a.mau;
	 while(a.mau==0){cout<<"Mau so khong hop le , vui long nhap lai: ";cin>>a.mau;}}
	 
void Xuat(PhanSo a){  
 	if(a.mau<0){a.mau=-a.mau;a.tu=-a.tu;}
    int c=__gcd(abs(a.tu),abs(a.mau));a.tu/=c;a.mau/=c;
                if (a.mau==1) cout<<a.tu<<endl;
                else cout<<a.tu<<"/"<<a.mau<<endl;}

int main(){
    PhanSo a;Nhap(a);cout<<"Phan so toi gian la: ";Xuat(a);
    return 0;}