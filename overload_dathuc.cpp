#include <bits/stdc++.h>
#define loop(j, k)  for (int i = (j); i >= (k); i--)
using namespace std;
class DaThuc {
	private: int n; float A[1000]={0};
	public:
	DaThuc(){n=0;loop(n,1) A[i]=0;}
	DaThuc(int a,float B[]){n=a;loop(n,0) A[i]=B[i];}
	~DaThuc(){}

	friend istream &operator >> (istream &In, DaThuc &a){
		cout<<"\nNhap so bac: "; In>>a.n;
		while(a.n<0) {cout<<"So bac khong hop le , vui long nhap lai: "; In>>a.n;}
		if(a.n==1) {cout<<"Nhap he so cua x: "; In>>a.A[1];
					while(a.A[1]==0) {cout<<"He so nhap vao khong hop le , vui long nhap lai: "; In>>a.A[1];}}
		else{
		if(a.n>1){cout<<"Nhap he so cua x^"<<a.n<<": "; In>>a.A[a.n];
				  while(a.A[a.n]==0) {cout<<"He so nhap vao khong hop le , vui long nhap lai: "; In>>a.A[a.n];}}
		loop(a.n-1,2) {cout<<"Nhap he so cua x^"<<i<<": "; In>>a.A[i];}
		if(a.n>=1) {cout<<"Nhap he so cua x: "; In>>a.A[1];}}
		cout<<"Nhap he so tu do: "; In>>a.A[0];
		return In;}

	friend ostream &operator << (ostream &Out, DaThuc &a) {
		if(a.n>1) {if(a.A[a.n]==1) Out<<"x^"<<a.n;
				   else if(a.A[a.n]==-1) Out<<"-x^"<<a.n;
				   else Out<<a.A[a.n]<<"x^"<<a.n;
				   loop(a.n-1,2) {if(a.A[i]==1)Out<<"+x^"<<i;
				   				  else if(a.A[i]==-1)Out<<"-x^"<<i;
				   				  else if(a.A[i]>0)Out<<"+"<<a.A[i]<<"x^"<<i;
				   				  else if(a.A[i]<0)Out<<a.A[i]<<"x^"<<i;}
				   if(a.A[1]==1) Out<<"+x";
				   else if(a.A[1]==-1) Out<<"-x";
				   else if(a.A[1]>0) Out<<"+"<<a.A[1]<<"x";
				   else if(a.A[1]<0) Out<<a.A[1]<<"x";
				   if(a.A[0]>0) Out<<"+"<<a.A[0];
				   else if(a.A[0]<0) Out<<a.A[0];return Out;}
		else if(a.n==1) {if(a.A[1]==1) Out<<"x"; else if(a.A[1]==-1) Out<<"-x"; else Out<<a.A[1]<<"x";
						 if(a.A[0]>0) Out<<"+"<<a.A[0]; else if(a.A[0]<0) Out<<a.A[0];return Out;}
		else Out<<a.A[0];return Out;}

	float operator () (float x){float sum=0;loop(n,0) sum+=A[i]*pow(x,i);return sum;}
	DaThuc operator + (DaThuc b){int m=max(n,b.n);float B[m+1]={0};loop(m,0) B[i]=A[i]+b.A[i]; return DaThuc(m,B);}
	DaThuc operator - (DaThuc b){int m=max(n,b.n);loop(m,0) if(A[i]==b.A[i]) {m--;} else break; float B[m+1]={0};loop(m,0) B[i]=A[i]-b.A[i]; return DaThuc(m,B);}
	DaThuc operator * (DaThuc b){int m=n+b.n;float temp[m+1]={0},C[m+1]={0};
								 if((n==0&&A[0]==0)||(b.n==0&&b.A[0]==0)) return DaThuc(0,C);
								 for(int z = 0; z<=n; z++) {for(int j=0;j<z;j++) temp[j] = 0;
   															for(int j=z;j<=z+b.n;j++) temp[j] = A[z]*b.A[j-z];
         													loop(m,0) C[i]=C[i]+temp[i];}
								 							return DaThuc(m,C);}
	friend bool operator == (DaThuc a, float b){if(a.n==0&&a.A[0]==b) return 1; return 0;}
	DaThuc operator / (DaThuc b){int m=n-b.n,u=n;float ans[m+1]={0},odd[n+1],C[n+1]={0}; loop(n,0) odd[i]=A[i];
								 while(u>=b.n){ans[u-b.n]=odd[u]/b.A[b.n];
								 			   int t=u-b.n;
   											   for(int j=t;j<=t+b.n;j++) C[j] = ans[t]*b.A[j-t];
         									   loop(u,0) {odd[i]-=C[i];}
											   //DaThuc(u,odd)=DaThuc(u,odd)-DaThuc(u-b.n,ans) * b;
											   u--;} 
											   return DaThuc(m,ans);}
					
	DaThuc operator % (DaThuc b){if(n==b.n) {int c=0;float C[n+1]={0};float a=A[n]/b.A[b.n];
								 loop(n,0) {C[i]=A[i]-a*b.A[i];if(abs(C[i])<0.000001) {C[i]=0;c++;}if(C[n]<0) break;}return DaThuc(n-c,C);} 
								 return DaThuc(n,A)-DaThuc(n,A)/b*b;}						   
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
	DaThuc f1,f2,f3,f4,f5,f6,f7;float x;
	cout<<"Nhap vao du lieu cua da thuc thu nhat: "; cin>>f1; 
	cout<<"Nhap vao du lieu cua da thuc thu hai: ";  cin>>f2;
	cout<<"Nhap gia tri cua x: ";cin>>x;
	cout<<"Da thuc thu nhat : "<<f1;
	cout<<"\nGia tri cua da thuc thu nhat khi x="<<x<<" la: "<<f1(x);
	cout<<"\nDa thuc thu hai : "<<f2;
	cout<<"\nGia tri cua da thuc thu hai khi x="<<x<<" la: "<<f2(x);
	f3=f1+f2;
	cout<<"\nTong hai da thuc la: "<<f3;
	cout<<"\nGia tri cua tong hai da thuc khi x="<<x<<" la: "<<f3(x);
	f4=f1-f2;
	cout<<"\nHieu hai da thuc la: "<<f4;
	cout<<"\nGia tri cua hieu hai da thuc khi x="<<x<<" la: "<<f4(x);
	f5=f1*f2;
	cout<<"\nTich hai da thuc la: "<<f5;
	cout<<"\nGia tri cua tich hai da thuc khi x="<<x<<" la: "<<f5(x);
	if(f2==0) cout<<"\n*Khong chia duoc do Da Thuc chia bang 0";
	else{
	f6=f1/f2;
	cout<<"\nThuong hai da thuc la: "<<f6;
	cout<<"\nGia tri cua thuong hai da thuc khi x="<<x<<" la: "<<f6(x);
	f7=f1%f2;
	cout<<"\nDa thuc du khi chia hai da thuc la: "<<f7;
	cout<<"\nGia tri cua da thuc du khi x="<<x<<" la: "<<f7(x);}
}