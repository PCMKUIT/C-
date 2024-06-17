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
class SUBJECT_POINT{
	private: string Name;
			 float Point_Of_Process,Midterm_Point;
			 float Final_Point,Point _Average_Of_Subject;
	public:
		SUBJECT_POINT(string a="", float b=0, float c=0, float d=0, float e=0){
			Name=a; Point_Of_Process=b;
			Midterm_Point=c;Final_Point=d;
			Point _Average_Of_Subject=e;}
		~SUBJECT_POINT(){}	
		friend istream & operator >> (istream & In, SUBJECT_POINT & sp){
			cout<<"Nhap ten mon hoc: "; In>>sp.Name;
			cout<<"Nhap diem qua trinh: "; In>>sp.Point_Of_Process;
			cout<<"Nhap diem giua ky: "; In>>sp.Midterm_Point;
			cout<<"Nhap diem cuoi ky: "; In>>sp.Final_Point;}
		friend ostream & operator << (ostream & Out,const SUBJECT_POINT sp){
			cout<<"Diem trung binh mon la: "<<sp.Point _Average_Of_Subject;}
		void Cal_ Point _Average_Of_Subject (){
			Point _Average_Of_Subject = Point_Of_ Process * 0.2 + Midterm_Point* 0.3 + Final_Point * 0.5;}T
};
int main{
	return;}