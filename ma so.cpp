#include <bits/stdc++.h>
using namespace std;
int main (){
int b[100000];int x=0;int ketqua;
string s;cin>>s;int m=0;int c;
sort (s.begin(),s.end());
while(s.empty()==0){int a=0;
while(s[0]==s[a]){a++;}
s.erase(s.begin(),s.begin()+a);
b[x]=a;x++;c=a;}
x--; 
if((x==0)&&(c==1)){cout<<0;}
else if((x==0)&&(c!=1)){cout<<1;}
else{
for (int i=0;i<x;i++){if (b[i]!=1){m=1;break;}}
unsigned long long int X=0;
while(x!=0){int S=0;
for(int i=x-1;i>=0;i--){S+=b[i];}
X+=b[x]*S;x--;}
if (m==1) X++;
cout<<X;}
return 0;}