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
			 float Final_Point, Point_Average_Of_Subject;
	public:
		SUBJECT_POINT(string a="", float b=0, float c=0, float d=0, float e=0){
			Name=a; Point_Of_Process=b;
			Midterm_Point=c;Final_Point=d;
			Point_Average_Of_Subject=e;}
		~SUBJECT_POINT(){}	
		friend istream & operator >> (istream & In, SUBJECT_POINT & sp){
			In>>sp.Name;
			In>>sp.Point_Of_Process;
			In>>sp.Midterm_Point;
			In>>sp.Final_Point;
			while(sp.Point_Of_Process<0||sp.Midterm_Point<0||sp.Final_Point<0){
				cout<<"Du lieu khong hop le, vui long nhp lai: ";
				In>>sp.Name;
				In>>sp.Point_Of_Process;
				In>>sp.Midterm_Point;
				In>>sp.Final_Point;}
			return In;}
		friend ostream & operator << (ostream & Out,const SUBJECT_POINT sp){
			cout<<"Diem trung binh mon la: "<<sp.Point_Average_Of_Subject;
			return Out;}
		float Cal_Point_Average_Of_Subject (){
			Point_Average_Of_Subject = Point_Of_Process * 0.2 + Midterm_Point* 0.3 + Final_Point * 0.5;
			return Point_Average_Of_Subject;}
};
bool cmp(float a , float b) { 
	return a<b; }
template <typename T>
void quickSort(T arr[] , int left, int right){
    int mid=left+right;
    mid/=2;
    T pivot = arr[mid];
    int l = left;
    int r = right;  
    do{ while((l <= right) && cmp(arr[l], pivot)) l++;
        while((r >= left) && cmp(pivot, arr[r]))  r--;
        if(l > r)  break;
        swap(arr[l], arr[r]); l++, r--;
	} while(l <= r);
    if(left < r) quickSort(arr, left, r);
    if(l < right)quickSort(arr, l, right);}
class Xulythongtin{
	private: SUBJECT_POINT Dulieu[500];
			 int soluongphantu;
			 float max,min;
	public:
		Xulythongtin(){}
		~Xulythongtin(){}
		friend istream & operator >> (istream & In, Xulythongtin & a){
			int n;
			cout<<"Nhap so luong phan tu trong danh sach: "; In>>a.soluongphantu;
			while(a.soluongphantu<0){cout<<"Khong hop le, vui long nhap lai: ";In>>a.soluongphantu;}
			for(int i=1;i<=a.soluongphantu;i++)
				{cout<<"Nhap thong tin cho phan thu thu "<<i<<": ";In>>a.Dulieu[i];}
			return In;}
		friend ostream & operator << (ostream & Out, Xulythongtin a){
			for(int i=1;i<=a.soluongphantu;i++)
			Out<<"Diem trung binh cua phan tu thu "<<i<<" la: "<<a.Dulieu[i].Cal_Point_Average_Of_Subject()<<endl;
			Out<<"Diem trung binh cao nhat la: "<<a.max;
			Out<<"\nDiem trung binh thap nhat la: "<<a.min;
			return Out;}
		void FINDMAXMIN(){
			float b[soluongphantu+1];
			for(int i=1;i<=soluongphantu;i++) b[i]=Dulieu[i].Cal_Point_Average_Of_Subject();
			quickSort(b,1,soluongphantu);
			max=b[soluongphantu];
			min=b[1];}
};
int main(){
	Xulythongtin A;
	cin>>A;
	A.FINDMAXMIN();
	cout<<A;
	return 0;}