#include <bits/stdc++.h>
#include <ctime>
using namespace std;
int Win,Draw,Lose;
int RanDom(int min,int max){
    return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));}
int main (){
	srand(time(NULL));
	int LuaChon; 
	map <int,string> KBB;
	KBB[1]="Keo";
	KBB[2]="Bua";
	KBB[3]="Bao";
	cout<<"                                       TRO CHOI KEO BUA BAO";
	while (true){
		cout<<"\n1.Keo";
		cout<<"\n2.Bua";
		cout<<"\n3.Bao";
		cout<<"\n4.Thong ke ti so";
		cout<<"\n5.Khong choi nua";
		cout<<"\nBan chon: ";
		cin>>LuaChon;
		while(LuaChon<1||LuaChon>5){
			cout<<"Cau lenh khong hop le , vui long nhap lai 1 so tu 1 den 5: ";
			cin>>LuaChon;}
		if(RanDom(1,10)==1){
		if(LuaChon==1){
			int temp=RanDom(1,100);
			if(temp>0&&temp<51) {cout<<"May ra Bua , ban thua."; Lose++;}
			if(temp>50&&temp<81) {cout<<"May ra Keo , hoa."; Draw++;}
			if(temp>80) {cout<<"May ra Bao, ban thang."; Win++;}}
		if(LuaChon==2){
			int temp=RanDom(1,100);
			if(temp>0&&temp<51) {cout<<"May ra Bao , ban thua."; Lose++;}
			if(temp>50&&temp<81) {cout<<"May ra Bua , hoa."; Draw++;}
			if(temp>80) {cout<<"May ra Keo, ban thang."; Win++;}}
		if(LuaChon==3){
			int temp=RanDom(1,100);
			if(temp>0&&temp<51) {cout<<"May ra Keo , ban thua."; Lose++;}
			if(temp>50&&temp<81) {cout<<"May ra Bao , hoa."; Draw++;}
			if(temp>80) {cout<<"May ra Bua, ban thang."; Win++;}}}
		else{
			if(LuaChon==1||LuaChon==2||LuaChon==3){
			int temp=RanDom(1,3);
			int ans=temp-LuaChon;
			if(ans==-2) {cout<<"May ra Keo , ban thua."; Lose++;}
			if(ans==-1) {cout<<"May ra "<<KBB[temp]<<" , ban thang."; Win++;}
			if(ans==0)  {cout<<"May ra "<<KBB[temp]<<" , hoa."; Draw++;}
			if(ans==1) {cout<<"May ra "<<KBB[temp]<<" , ban thua."; Lose++;}
			if(ans==2) {cout<<"May ra Bao , ban thang."; Win++;}}}
		if(LuaChon==4) cout<<"Win: "<<Win<<" Draw: "<<Draw<<" Lose: "<<Lose;
		if(LuaChon==5) {
			cout<<"Ti so chung cuoc la: ";
			cout<<"Win: "<<Win<<" Draw: "<<Draw<<" Lose: "<<Lose<<endl;
			if(Win==0) cout<<"Khong thang noi 1 tran sao, kaka.";
			else if(Lose>Win) cout<<"Ban co ve thua nhieu nhi.";
			else if(Win>Lose) cout<<"Chuc mung nguoi thang cuoc.";
			else if(Win==Lose)cout<<"Co ve can suc day.";
			break;}}
		return 0;}