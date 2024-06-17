#include <bits/stdc++.h>
using namespace std;
struct PhanSo{int tu;int mau;};
void Nhap(PhanSo &a){
		cout<<"Nhap tu so: ";cin>>a.tu;
		cout<<"Nhap mau so: ";cin>>a.mau;
	 while(a.mau==0){cout<<"Mau so khong hop le , vui long nhap lai: ";cin>>a.mau;}}
	 
void Xuat1(PhanSo a){cout<<a.tu<<"/"<<a.mau<<endl;}
                
void Xuat2(PhanSo a){  
 	if(a.mau<0){a.mau=-a.mau;a.tu=-a.tu;}
    int c=__gcd(abs(a.tu),abs(a.mau));a.tu/=c;a.mau/=c;
                if (a.mau==1) cout<<a.tu<<endl;
                else cout<<a.tu<<"/"<<a.mau<<endl;}

float PhepSoSanh(PhanSo a,PhanSo b){return (float(a.tu)/float(a.mau)-float(b.tu)/(b.mau));}
    
int main(){
    PhanSo a,b;
    cout<<"Phan so thu nhat:"<<'\n';Nhap(a);
    cout<<"Phan so thu hai:"<<'\n';Nhap(b);
    cout<<"Phan so lon nhat la: ";if(PhepSoSanh(a,b)>0)Xuat1(a);else Xuat1(b);
    cout<<"Phan so lon nhat sau khi da rut gon la: ";if(PhepSoSanh(a,b)>0)Xuat2(a);else Xuat2(b);
    return 0;}