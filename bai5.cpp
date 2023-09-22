#include <bits/stdc++.h>
using namespace std;
int main(){
string n;
cin>>n;
long long s=0;long long a=0;
for(int i=2;i<n.size();i++){s=s+9*i*pow(10,i-2);} 
if(n[n.size()-1]=='0'){s=s+1;}else{s=s+1+n.size();} 
if(n.size()>2){
for(int i=0;i<n.size()-1;i++){a=a+(n[n.size()-2-i]-'0')*(pow(10,i));}
s=s+(a+1-pow(10,n.size()-2))*n.size();} 
else if (n.size()==2){s=s+(n[0]-'0')*2;}
else if ((n[0]-'0')==1){s=1;}
else {s=2;}
cout<<s;
return 0;
}