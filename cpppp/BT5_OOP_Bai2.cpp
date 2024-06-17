#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct thongke { string x; int y;};
bool cmp(string a , string b) { 
	if(a.size()==b.size()) return a<b; 
	return a.size()<b.size();}
bool cmp(thongke a , thongke b) { 
	if(a.y==b.y) return cmp(a.x,b.x); 
	return a.y>b.y;}	

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

class Thong_Ke_Doan_Van{
	private: 
		string str;
		int socau,sotu,data_size[1000];
		string word[1000];
		
	public:
		Thong_Ke_Doan_Van(string a="",int b=0,int c=0){str=a;socau=b;sotu=c;}
		~Thong_Ke_Doan_Van(){str="";socau=0;sotu=0;}
		
		void Nhap_Du_Lieu(){getline(cin,str); return;}
		
		int kt(char a){
			if(a==' '||a==','||a==';'||a=='('||a==')'||a=='{'||a=='}'||a=='['||a==']'||a==':') return 0;
			if(a=='.'||a=='!'||a=='?') return 1;
			return 2;}
			
		bool Compare(string a, string b){
			int min;
			if(a.size()>b.size()) min=b.size();
			else min=a.size();
			for(int i=0;i<min;i++){
				if(int(a[i])>64&&int(a[i])<91){a[i]+=32;}
				if(int(b[i])>64&&int(b[i])<91){b[i]+=32;}
				if(a[i]<b[i]) return 1;
				if(a[i]>b[i]) return 0;
				else continue;}
			return a.size()<b.size();}
			
		void Xuat_So_Luong_Cau_Va_So_Tu_Trong_Moi_Cau(){	
			int num[1000]={0},so_cau=0;
			bool block =1;
			for(int i=0;i<str.size();i++){
				if(kt(str[i])==2&&block) {
					block=0;
					num[so_cau]++;}
				if(kt(str[i])==0) block=1;
				if(kt(str[i])==1) {
					so_cau++;
					block=1;}}
			cout<<so_cau<<"\n";
			for(int i=0;i<so_cau;i++){data_size[i]=num[i];cout<<num[i]<<"\n";}
			socau=so_cau;
			return;}
		
		void Xuat_Cac_Tu_Xuat_Hien_Nhieu_Nhat(){
			int cnt=0;
			bool block=1;
			string split[1000];
			for(int i=0;i<str.size();i++){
				if(kt(str[i])==2) {
					split[cnt]+=str[i];
					block=1;}
				if(kt(str[i])!=2&&block) {
					cnt++;
					block=0;}}
			sotu=cnt;
			for(int i=0;i<cnt;i++) word[i]=split[i];
			thongke a[1000];
			int temp[1000]={0};
			int dem=0;
			quickSort(split,0,cnt-1); 
			a[0].x=split[0];
			for(int i=0;i<cnt-1;i++) {
				if(split[i]==split[i+1]) temp[dem]++;
				else {a[dem].y=temp[dem]+1;
					  dem++;
					  a[dem].x=split[i+1];}}
			a[dem].y=temp[dem]+1;
			quickSort(a,0,dem);
			int save=0; 
			for(int i=0;i<=dem;i++){
				if(i==dem) save=i;
				if(a[i].y!=a[0].y) {save=i-1; break;}}
			for(int i=0;i<=save;i++) {if(i!=save) cout<<a[i].x<<","; else cout<<a[i].x;}
			cout<<"\n";
			return;}
			
		void Xuat_Doan_Van_Da_Sap_Xep_Tang_Dan_Theo_Thu_Tu_Tu_Dien(){
			string copy[socau][sotu];
			string temp;
			int cnt=0;bool block=0;
			for(int i=0;i<socau;i++){
				for(int j=0;j<data_size[i];j++){copy[i][j]=word[cnt];cnt++;}}
			for(int i=0;i<socau;i++){
				for(int j=1;j<data_size[i];j++){
					for(int z=1;z<data_size[i];z++){
						if(Compare(copy[i][z-1],copy[i][z])==0){
						   temp=copy[i][z-1];
						   copy[i][z-1]=copy[i][z];
						   copy[i][z]=temp;}}}
				for(int x=0;x<data_size[i];x++){
					if(x!=data_size[i]-1) cout<<copy[i][x]<<" ";
					else cout<<copy[i][x]<<". ";}}
			return;}
};

int main (){
	Thong_Ke_Doan_Van a;
	a.Nhap_Du_Lieu();
	a.Xuat_So_Luong_Cau_Va_So_Tu_Trong_Moi_Cau();
	a.Xuat_Cac_Tu_Xuat_Hien_Nhieu_Nhat();
	a.Xuat_Doan_Van_Da_Sap_Xep_Tang_Dan_Theo_Thu_Tu_Tu_Dien();
}