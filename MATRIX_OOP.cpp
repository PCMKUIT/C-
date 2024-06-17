#include <bits/stdc++.h>
#define fori(x) for(int i=0;i<x;i++)
#define forj(y) for(int j=0;j<y;j++)
#define fork(z) for(int k=0;k<z;k++)
#define loop(n,m) for(int i=0;i<n;i++) for(int j=0;j<m;j++)
using namespace std;
class MATRIX{
	private: int sohang, socot;
			 float Matran[100][100];
	public:
		MATRIX(int n=0, int m=0, float A[][100]={0}){
			sohang=n; socot=m;
			loop(n,m) Matran[i][j]=A[i][j];}
		~MATRIX(){}
		
		friend istream & operator >> (istream & In, MATRIX & A){
			cout<<"Nhap so hang: "; In>>A.sohang;
			while(A.sohang<=0) {
				cout<<"So hang cua mot ma tran khong the am, vui long nhap lai: ";
				In>>A.sohang;}
			cout<<"Nhap so cot: ";  In>>A.socot;
			while(A.socot<=0) {
				cout<<"So cot cua mot ma tran khong the am, vui long nhap lai: ";
				In>>A.socot;}
			cout<<"Nhap ma tran:\n";
			loop(A.sohang,A.socot) {cout<<"["<<i<<"]["<<j<<"]: "; In>>A.Matran[i][j];}
			return In;}
			
		friend ostream & operator << (ostream & Out,const MATRIX A){
			fori(A.sohang){forj(A.socot) Out<<A.Matran[i][j]<<" "; cout<<"\n";}
			return Out;}
			
		bool check (MATRIX A) const {
			if(sohang==A.sohang&&socot==A.socot) return true;
			return false;}
			
		int check (MATRIX A,MATRIX B) const {
			if((A.socot==B.sohang)&&(A.sohang==B.socot)) return 1;
			if(A.socot==B.sohang) return 2;
			return 0;}
			
		MATRIX operator + (const MATRIX A){
			if(sohang!=A.sohang||socot!=A.socot) {
				float B[0][100];
				return MATRIX(-1,0,B);}
			float B[100][100];
			loop(sohang,socot) B[i][j]=Matran[i][j]+A.Matran[i][j];
			return MATRIX(sohang,socot,B);}
			
		MATRIX operator - (const MATRIX A){
			if(sohang!=A.sohang||socot!=A.socot) {
				float B[0][100];
				return MATRIX(-2,0,B);}
			float B[100][100];
			loop(sohang,socot) B[i][j]=Matran[i][j]-A.Matran[i][j];
			return MATRIX(sohang,socot,B);}
			
		MATRIX operator * (const MATRIX A){
			if(socot!=A.sohang) {
				float B[0][100];
				return MATRIX(-3,0,B);}
			float B[100][100]={0};
			loop(sohang,A.socot) 
			fork(socot) B[i][j]+=(Matran[i][k] * A.Matran[k][j]);
			return MATRIX(sohang,A.socot,B);}
};

int main(){
	MATRIX a,b,c,d,e,f;
	cout<<"Nhap du lieu cho ma tran thu nhat:\n"; cin>>a;
	cout<<"Nhap du lieu cho ma tran thu hai:\n";  cin>>b;
	cout<<"Ma tran thu nhat:\n"; cout<<a;
	cout<<"Ma tran thu hai:\n";  cout<<b; 
	if(a.check(b)){	
		c=a+b; d=a-b;
		cout<<"Tong cua hai ma tran a va b la:\n"<<c;
		cout<<"Hieu cua ma tran a va ma tran b la:\n"<<d;}
	else cout<<"Hai ma tran nhap vao khong cong va tru cho nhau duoc do khong cung kich thuoc\n";
	if(a.check(a,b)==1) {
		cout<<"Tich cua ma tran thu nhat va ma tran thu hai la:\n"<<a*b;
		cout<<"Tich cua ma tran thu hai va ma tran thu nhat la:\n"<<b*a;}
	else if(a.check(a,b)==2)
		cout<<"Tich cua ma tran thu nhat va ma tran thu hai la:\n"<<a*b;
	else if(a.check(b,a)==2)
		cout<<"Tich cua ma tran thu hai va ma tran thu nhat la:\n"<<b*a;
	else cout<<"Hai ma tran nhap vao khong nhan cho nhau duoc";
	return 0;}