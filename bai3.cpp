#include <bits/stdc++.h>
#include<graphics.h>
#define fori(x) for(int i=0;i<x;i++)
#define forj(y) for(int j=0;j<y;j++)
#define fork(z) for(int k=0;k<z;k++)
#define loop(n,m) for(int i=0;i<n;i++) for(int j=0;j<m;j++)
#define pb push_back
#define ll long long
const float pi=3.1415926535897;
int gd = DETECT, gm;
using namespace std;
class Malware{
	protected: string Name, file, detection_rate;
	public:
		Malware(){}
		~Malware(){}
		void Nhap(){
			cout<<"Nhap ten malware: ";cin>>Name;
			cout<<"Nhap ten file: ";cin>>file;}
		void Xuat(){
			cout<<"detection_rate="<<detection_rate;}
		
};
class Virus : public Malware{
	private: string signature, behavior;
	public:
		Virus(){}
		~Virus(){}
		void Nhap(){
			Malware::Nhap();
			cout<<"Nhap chu ky virus: ";cin>>signature;
			cout<<"Nhap hanh vi virus: ";cin>>behavior;}
		void Determine_DetectionRate(){
			if(signature=="ILOVEYOU") detection_rate="99.99%";
			else detection_rate="0.01%";}
};
class Ransomware : public Malware{
	private: string encryptKey;
			 ll ransomAmount;
	public:
		Ransomware(){}
		~Ransomware(){}
		void Nhap(){
			Malware::Nhap();
			cout<<"Nhap khoa ma hoa: ";cin>>encryptKey;
			cout<<"Nhap so tien chuoc: ";cin>>ransomAmount;
			while(ransomAmount<0){
				cout<<"So tien chuoc khong hop le, vui long nhap lai: ";
				cin>>ransomAmount;}}
		void Determine_DetectionRate(){
			if(encryptKey.length()<8) detection_rate="96.69%";
			else detection_rate="3.31%";}
};
int main (){
	Malware *a[2];
	a[0]=new Virus;
	a[0]->Nhap();
	a[1]=new Ransomware;
	a[1]->Nhap();
	a[0]->Xuat();
	a[1]->Xuat();}