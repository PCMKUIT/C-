#include <bits/stdc++.h>
#define loop(j, k)  for (int i = (j); i >= (k); i--)
using namespace std;
class DaThuc {
	private: int n; float A[1000]={0};
	public:
	DaThuc(){n=0;}
	DaThuc(int a,float B[]){n=a;loop(n,0) A[i]=B[i];}
	~DaThuc(){}

	friend istream &operator >> (istream &In, DaThuc &a){
		cout<<"\nNhap so bac: "; In>>a.n;
		while(a.n<0) {cout<<"So bac khong hop le , vui long nhap lai: "; In>>a.n;}
		loop(a.n,2) {cout<<"Nhap he so cua x^"<<i<<": "; In>>a.A[i];}
		if(a.n>=1) {cout<<"Nhap he so cua x: "; In>>a.A[1];}
		cout<<"Nhap he so tu do: "; In>>a.A[0];
		return In;}

	friend ostream &operator << (ostream &Out, DaThuc &a){
		if(a.n>1) {Out<<a.A[a.n]<<"x^"<<a.n;loop(a.n-1,2) {if(a.A[i]>0)Out<<"+"<<a.A[i]<<"x^"<<i;
				   				  						   else if(a.A[i]<0)Out<<"-"<<-a.A[i]<<"x^"<<i;}
				   if(a.A[1]>0) Out<<"+"<<a.A[1]<<"x";
				   else if(a.A[1]<0) Out<<"-"<<-a.A[1]<<"x";
				   if(a.A[0]>0) Out<<"+"<<a.A[0];
				   else if(a.A[0]<0) Out<<"-"<<-a.A[0];return Out;}
		else if(a.n==1) {Out<<a.A[1]<<"x";if(a.A[0]>0) Out<<"+"<<a.A[0]; else if(a.A[0]<0) Out<<"-"<<-a.A[0];return Out;}
		else Out<<a.A[0];return Out;}

	float operator () (float x){float sum=0;loop(n,0) sum+=A[i]*pow(x,i);return sum;}
	DaThuc operator + (DaThuc b){int m=max(n,b.n);float B[m]={0};loop(m,0) B[i]=A[i]+b.A[i]; return DaThuc(m,B);}
	DaThuc operator - (DaThuc b){int m=max(n,b.n);loop(m,0) if(A[i]==b.A[i]) {m--;} else break; float B[m]={0};loop(m,0) B[i]=A[i]-b.A[i]; return DaThuc(m,B);}
	/*void Nhap1(){cout<<"Nhap so bac cua da thuc thu nhat: ";cin>>n1;
				while(n1<0) {cout<<"So bac khong hop le , vui long nhap lai: ";cin>>n1;}
				loop(n1,2) {cout<<"Nhap he so cua x^"<<i<<": "; cin>>A[i];}
				if(n1>=1) cout<<"Nhap he so cua x ";cin>>A[1];
				cout<<"Nhap he so tu do: ";cin>>A[0];} 
	void Nhap2(){cout<<"Nhap so bac cua da thuc thu hai: ";cin>>n2;
				while(n2<0) {cout<<"So bac khong hop le , vui long nhap lai: ";cin>>n2;}
				loop(n2,2) {cout<<"Nhap he so cua x^"<<i<<": "; cin>>B[i];}
				if(n2>=1) cout<<"Nhap he so cua x ";cin>>B[1];
				cout<<"Nhap he so tu do: ";cin>>B[0];} 
				
	void Xuat(float a[],int n){loop(n,2) {cout<<a[i]<<"x^"<<i<<"+";}
							   cout<<a[1]<<"x"<<"+"<<a[0];}
	float GiaTri(float x,float a[],int n){float sum=0;loop(n,0) sum+=a[i]*pow(x,i);return sum;}
	void Tong(){int n=max(n1,n2);float c[n];loop(n,0) c[i]=A[i]+B[i];}
	void Hieu(){int n=max(n1,n2);float c[n];loop(n,0) c[i]=A[i]-B[i];}*/
};
int main (){
	DaThuc f1,f2,f3,f4;float x;
	cout<<"Nhap vao du lieu cua da thuc thu nhat: "; cin>>f1; 
	cout<<"Nhap vao du lieu cua da thuc thu hai: ";  cin>>f2;
	cout<<"Nhap gia tri cua x: ";cin>>x;
	cout<<"Da thuc thu nhat : "<<f1;
	cout<<"\nGia tri cua da thuc thu nhat khi x="<<x<<" la: "<<f1(x);
	cout<<"\nDa thuc thu hai : "<<f2;
	cout<<"\nGia tri cua da thuc thu hai khi x="<<x<<" la: "<<f2(x);
	f3=f1+f2;
	cout<<"\nTong hai da thuc la: "<<f3;
	cout<<"\nTong hai da thuc khi x="<<x<<" la: "<<f3(x);
	f4=f1-f2;
	cout<<"\nHieu hai da thuc la: "<<f4;
	cout<<"\nHieu hai da thuc khi x="<<x<<" la: "<<f4(x);
}