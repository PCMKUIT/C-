#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;
bool kt;
class diem{
	private: float x,y;
	public:
	diem(){}
	diem(float a,float b){x=a;y=b;}
	~diem(){}
	void nhap(){cout<<"\nhoanh do x=";cin>>x;
				cout<<"tung do y=";cin>>y;}
	void xuat(){cout<<"("<<x<<","<<y<<")";}
	void setx(float a){x=a;}
	void sety(float a){y=a;}
	diem vector(diem a){diem t;
 						t.setx(a.getx()-x);
 						t.sety(a.gety()-y);
						return t;}
	float getx(){return x;}
	float gety(){return y;}
	void setxy(float a,float b){x=a;y=b;}
	void tinhtien(float a=0,float b=0){x+=a;y+=b;}
	void quay(float rad){x=x*cos(rad)+y*sin(rad);
						 y=x*sin(rad)+y*cos(rad);}
};



class tamgiac{
	private:diem A,B,C;
	public:
	tamgiac(){}
	tamgiac(diem x,diem y,diem z){A=x;B=y;C=z;}
	~tamgiac(){}
	void nhap(){do{ cout<<"\nnhap dinh A"; A.nhap();
  					cout<<"\nnhap dinh B"; B.nhap();
  					cout<<"\nnhap dinh C"; C.nhap();
  					diem d,e; d=A.vector(B); e=A.vector(C);
  					if(float(d.getx()*e.gety())==float(d.gety()*e.getx())){kt=1;cout<<"\ntam giac khong ton tai, vui long nhap lai: ";}
  					cout<<"\n";}while(kt);}
	void xuat(){cout<<"\ntam giac tao boi 3 diem: ";A.xuat();cout<<",";B.xuat();cout<<",";C.xuat();}
	void tinhtien(float m=0,float n=0){A.tinhtien(m,n);B.tinhtien(m,n);C.tinhtien(m,n);}
	void quay(float rad){A.quay(rad);B.quay(rad);C.quay(rad);}
	void thuphong(float k){A.setxy(A.getx()*k,A.gety()*k);B.setxy(B.getx()*k,B.gety()*k);C.setxy(C.getx()*k,C.gety()*k);}
};

int main(){
float x,y,rad,k; diem b; b.nhap();
tamgiac a;a.nhap(); a.xuat();
cout<<"\ntinh tien theo vector v(x,y):\nx=";cin>>x;
cout<<"y=";cin>>y;
a.tinhtien(x,y);
a.xuat();
cout<<"quay goc: rad=";cin>>rad;
a.quay(rad);
a.xuat();
cout<<"nhap he so thu phong k=";cin>>k;
a.thuphong(k);a.xuat();system("pause");
int gd = DETECT, gm,color;
            initgraph(&gd, &gm,"C:\\TC\\BGI");
            putpixel(1,2,YELLOW);
            getch();
            closegraph();

return 0;}