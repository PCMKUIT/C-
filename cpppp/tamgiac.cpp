#include<graphics.h>
#include<bits/stdc++.h>
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
	void quay(float alpha,float c,float d){
		 float x=hoanhdo,y=tungdo;float e=c,f=d;
		 hoanhdo=e+(x-e)*cos(alpha)-(y-f)*sin(alpha);
		 tungdo=f+(x-e)*sin(alpha)+(y-f)*cos(alpha);}
};

class TamGiac{
	private:Diem A,B,C;
	public:
	TamGiac(){}
	TamGiac(Diem x,Diem y,Diem z){A=x;B=y;C=z;}
	~TamGiac(){}
	void nhap(){bool kt;
				do{ kt=0;
					cout<<"Nhap dinh A:"; A.nhap();
  					cout<<"Nhap dinh B:"; B.nhap();
  					cout<<"Nhap dinh C:"; C.nhap();
  					Diem d,e; d=A.vector(B); e=A.vector(C);
  					if(float(d.getx()*e.gety())==float(d.gety()*e.getx()))
					{kt=1;cout<<"Tam giac khong ton tai, vui long nhap lai:\n";}}while(kt);}
	void xuat(){cout<<"Tam giac tao boi 3 diem: ";
				cout<<"A";A.xuat();cout<<",B";B.xuat();cout<<",C";C.xuat();vetamgiac();}
    void vetamgiac(){initgraph(&gd, &gm,"");
            		 line(A.getx(),A.gety(),B.getx(),B.gety()); 
					 line(B.getx(),B.gety(),C.getx(),C.gety());
					 line(C.getx(),C.gety(),A.getx(),A.gety());
					 cout<<endl;system("pause");}        
	void tinhtien (float m,float n){A.tinhtien(m,n);B.tinhtien(m,n);C.tinhtien(m,n);}
	void quay(float alpha){A.quay(alpha,A.getx(),A.gety());B.quay(alpha,A.getx(),A.gety());C.quay(alpha,A.getx(),A.gety());}
	void thuphong(float k){A.setxy(A.getx()*k,A.gety()*k);B.setxy(B.getx()*k,B.gety()*k);C.setxy(C.getx()*k,C.gety()*k);}
};

int main(){
float x,y,alpha,k;cout<<"Nhap 3 dinh A,B,C cua tam giac:\n"; 
TamGiac a;a.nhap(); a.xuat();
cout<<"\nNhap vector v(x,y):\nx=";cin>>x;cout<<"y=";cin>>y;
cout<<"Sau khi tinh tien theo vector v("<<x<<","<<y<<").";a.tinhtien(x,y);a.xuat();a.tinhtien(-x,-y);
cout<<"\nNhap he so phong to (thu nho): ";cin>>k;
cout<<"Sau khi thay doi kich thuoc no di "<<k<<" lan.";a.thuphong(k);a.xuat();a.thuphong(1/k);
cout<<"\nNhap goc quay alpha (tinh theo do): ";cin>>alpha;
cout<<"Sau khi quay theo goc alpha="<<alpha<<".";alpha*=pi/180;a.quay(alpha);a.xuat();
closegraph();
return 0;}
