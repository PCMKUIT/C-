#include <bits/stdc++.h> 
using namespace std ;
int _day(int dd,int mm, int yy) {
    int ans ;
    yy -= (14-mm)/12;
    mm += 12*((14-mm)/12)-2;
    ans = (dd + yy + yy/4 - yy/100 + yy/400 + (31*mm)/12)%7;
    switch(ans){
    	case 0: return 8;
    	case 1: return 2;
    	case 2: return 3;
    	case 3: return 4;
    	case 4: return 5;
    	case 5: return 6;
    	case 6: return 7;
	}
    return 0;}
    
int main() {
    int x,y,i,j,cnt=0 ; cin >>x >>y >> i >> j ;
    if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)  {
            for(int a=1;a<=31;a++) {
                if(_day(a,i,j)==y) cnt++;
                if(cnt==x){cout<<a;return 0;}}
            if (cnt<x) cout<<-1;}
    else if(i==4||i==6||i==9||i==11) {
            for(int a=1;a<=30;a++) {
            	if(_day(a,i,j)==y) cnt++;
            	if(cnt==x) {cout<<a;return 0;}}
            if (cnt<x) cout<<-1 ;}
    else {for(int a=1;a<=29;a++) {
            	if(a==29&&j%400!=0&&(j%4!=0||j%100==0)) break;
                if(_day(a,i,j)==y) cnt++ ;
                if(cnt==x) { cout<<a;  return 0 ;}}
            if (cnt<x) cout<<-1 ;}
			return 0;}