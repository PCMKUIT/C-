#include <bits/stdc++.h>
using namespace std;
int main (){
string a;cin>>a;int m=2;
if(a[0]=='-'){cout<<"false";}
else {for (int i=0;i<=int((a.size()-1)/2);i++){if(a[i]!=a[a.size()-1-i]){m=3;}}
if(m==2){cout<<"true";}
else cout<<"false";}
return 0;}