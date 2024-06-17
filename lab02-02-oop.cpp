#include <bits/stdc++.h>
using namespace std;

class SoPhuc{
	private: float thuc,ao;
	public: 
	void Nhap1(){cout<<"Nhap so thuc: ";cin>>this->thuc;
				 cout<<"Nhap so ao: ";cin>>this->ao;}
	void Nhap2(){cout<<"Nhap so thuc: ";cin>>this->thuc;
				 cout<<"Nhap so ao: ";cin>>this->ao;
				while(this->thuc==0&&this->ao==0){
					cout<<"Khong hop le , vui long nhap lai so phuc thu hai: "<<endl;
					cout<<"Nhap so thuc: ";cin>>this->thuc;
					cout<<"Nhap so ao: ";cin>>this->ao;}}
				
	void Xuat(){if(this->thuc!=0){
				if(this->ao==1) cout<<this->thuc<<" "<<"+"<<" "<<"i"<<endl;
				else if(this->ao==-1)cout<<this->thuc<<" "<<"-"<<" "<<"i"<<endl;
				else if(this->ao>0)cout<<this->thuc<<" "<<"+"<<" "<<this->ao<<"i"<<endl;
				else if(this->ao<0) cout<<this->thuc<<" "<<"-"<<" "<<-this->ao<<"i"<<endl;
				else if(this->ao==0)  cout<<this->thuc<<endl;}
				else {
				if(this->ao==1)cout<<"i"<<endl;
				else if(this->ao==-1) cout<<"-i"<<endl;
				else if(this->ao==0)cout<<0<<endl;
				else cout<<this->ao<<"i"<<endl;}}
				
	SoPhuc Cong (SoPhuc a,SoPhuc b){
		SoPhuc c;
		c.thuc=a.thuc + b.thuc;
		c.ao=a.ao+b.ao;
		return c;}
		
	SoPhuc Tru (SoPhuc a,SoPhuc b){
		SoPhuc c;
		c.thuc=a.thuc-b.thuc;
		c.ao=a.ao-b.ao;
		return c;}
		
	SoPhuc Nhan (SoPhuc a,SoPhuc b){
		SoPhuc c;
		c.thuc=a.thuc*b.thuc-a.ao*b.ao;
		c.ao=a.thuc*b.ao+a.ao*b.thuc;
		return c;}
		
	SoPhuc Chia (SoPhuc a,SoPhuc b){
		SoPhuc c;
		c.thuc=(a.thuc*b.thuc+a.ao*b.ao)/(pow(b.thuc,2)+pow(b.ao,2));
		c.ao=(b.thuc*a.ao-a.thuc*b.ao)/(pow(b.thuc,2)+pow(b.ao,2));
		return c;}
	};

int main (){
	SoPhuc a,b,c,d,e,f;
	cout<<"So phuc thu nhat:"<<'\n';a.Nhap1();
	cout<<"So phuc thu hai:"<<'\n';b.Nhap2();
	cout<<"Tong hai so phuc la: ";c=c.Cong(a,b);c.Xuat();
	cout<<"Hieu hai so phuc la: ";d=d.Tru(a,b);d.Xuat();
	cout<<"Tich hai so phuc la: ";e=e.Nhan(a,b);e.Xuat();
	cout<<"Thuong hai so phuc la: ";f=f.Chia(a,b);f.Xuat();
	return 0;}