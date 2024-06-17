#include <bits/stdc++.h>
using namespace std;
int main(){
string n;
cin>>n;
unsigned long long int s=0;int a=0;
for(int i=n.size()-1;i>1;i--){s=s+9*i*pow(10,i-2);} 
if(n[n.size()-1]=='0'){s=s+1;}else{s=s+1+n.size();} 
if(n.size()>2){
for(int i=0;i<n.size()-2;i++){a=a+(n[n.size()-2-i]-'0')*(pow(10,i));}
s=s+(a+1)*(n.size());} 
else if (n.size()==2){s=s+(n[0]-'0')*2;}
else if ((n[0]-'0')==1){s=1;}
else {s=2;}
cout<<s;
return 0;
}