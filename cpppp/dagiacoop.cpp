#include<graphics.h>
#include<bits/stdc++.h>
#define loop(i, j, k, in)  for (int i = (j); i < (k); i += (in))
using namespace std;
const float pi=3.1415926535897;
int gd = DETECT, gm;
class Diem{
	private: float hoanhdo,tungdo;
	public:
	Diem(){}
	Diem(float a,float b){hoanhdo=a;tungdo=b;}
	~Diem(){}
	void nhap(){cout<<"\nHoanh do x=";cin>>hoanhdo;
				cout<<"Tung do y=";cin>>tungdo;}
	void xuat(){cout<<"("<<hoanhdo<<","<<tungdo<<")";}
	Diem vector(Diem a){Diem t;
						t.setx(a.getx()-hoanhdo);
						t.sety(a.gety()-tungdo);
						return t;}
	void setx(float a){hoanhdo=a;}
	void sety(float a){tungdo=a;}
	float getx(){return hoanhdo;}
	float gety(){return tungdo;}
	void setxy(float a,float b){hoanhdo=a;tungdo=b;}
	void tinhtien(float a,float b){hoanhdo+=a;tungdo+=b;}
	void quay(float alpha,float c,float d){float x=hoanhdo,y=tungdo;float e=c,f=d;
						   				   hoanhdo=e+(x-e)*cos(alpha)-(y-f)*sin(alpha);
						   				   tungdo=f+(x-e)*sin(alpha)+(y-f)*cos(alpha);}
};

class DaGiac{
	private:int n;Diem A[1000];
	public:
	DaGiac(){}
	DaGiac(Diem x[]){loop(i,0,n,1) A[i]=x[i];}
	~DaGiac(){}
	void nhap(){cout<<"Nhap so dinh cua da giac: ";cin>>n;
				while(n<=2) {cout<<"So dinh khong hop le, vui long nhap lai: ";cin>>n;}bool kt;
				do{ kt=0;
					loop(i,0,n,1){cout<<"Nhap dinh "<<i+1<<":"; A[i].nhap();}
  					Diem d[n]; 
					loop(i,1,n,1) d[i]=A[0].vector(A[i]);
  					loop(i,1,n,1)if(!(float(d[1].getx()*d[i].gety())==float(d[1].gety()*d[i].getx()))){kt=1;}
					if(!kt)cout<<"Da giac khong ton tai, vui long nhap lai:\n";}while(!kt);}
  	bool cmp(Diem a , Diem b, int e) {if(e==0){if((a.getx()<b.getx())||((a.getx()==b.getx())&&(a.gety()<b.gety()))) return 1;return 0 ;}
	  								  else if((a.gety()>b.gety())||((a.gety()==b.gety())&&(a.getx()>b.getx()))) return 1;return 0 ; }
	int partition (Diem a[], int l , int r ,int e) {
    	Diem pivot=a[r];
    	int i=l-1 ;
    	for(int j=l;j<r;j++) {
       		if(cmp(a[j],pivot,e)) {i++;swap(a[i],a[j]);}}i++ ;
    	swap(a[i],a[r]);
    	return i ;}
	void quickSort(Diem a[],int l, int r,int e) {if(l<r) {int p=partition(a,l,r,e);quickSort(a,l,p-1,e); quickSort(a,p+1,r,e);}}
	void xuat(){cout<<"Da giac tao boi "<<n<<" diem: ";A[0].xuat();loop(i,1,n,1){cout<<",";A[i].xuat();}
            	initgraph(&gd, &gm,"");
				Diem B[1000];
            	quickSort(A,0,n-1,0);int j=0,z=-1;
            	loop(i,1,n,1){if(A[i].gety()>=A[j].gety()) {line(A[j].getx(),A[j].gety(),A[i].getx(),A[i].gety());j=i;}
							  else {z++;B[z].setxy(A[i].getx(),A[i].gety());}} 
            	line(A[j].getx(),A[j].gety(),A[n-1].getx(),A[n-1].gety());
            	quickSort(B,0,z,1);
            	line(A[n-1].getx(),A[n-1].gety(),B[0].getx(),B[0].gety());
    			loop(i,0,z,1) line(B[i].getx(),B[i].gety(),B[i+1].getx(),B[i+1].gety());
    			line(B[z].getx(),B[z].gety(),A[0].getx(),A[0].gety());
				cout<<endl;
				system("pause");}        
	void tinhtien (float m,float t){loop(i,0,n,1) A[i].tinhtien(m,t);}
	void quay(float alpha){loop(i,0,n,1) A[i].quay(alpha,A[0].getx(),A[0].gety());}
	void thuphong(float k){loop(i,0,n,1) A[i].setxy(A[i].getx()*k,A[i].gety()*k);}
};

int main(){
float x,y,alpha,k;
DaGiac a;a.nhap(); a.xuat();
cout<<"\nNhap vector v(x,y):\nx=";cin>>x;cout<<"y=";cin>>y;
cout<<"Sau khi tinh tien theo vector v("<<x<<","<<y<<").";a.tinhtien(x,y);a.xuat();a.tinhtien(-x,-y);
cout<<"\nNhap he so phong to (thu nho): ";cin>>k;
cout<<"Sau khi thay doi kich thuoc no di "<<k<<" lan.";a.thuphong(k);a.xuat();a.thuphong(1/k);
cout<<"\nNhap goc quay alpha (tinh theo do): ";cin>>alpha;
cout<<"Sau khi quay theo goc alpha="<<alpha<<".";alpha*=pi/180;a.quay(alpha);a.xuat();
closegraph();
return 0;}