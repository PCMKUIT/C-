#include <bits/stdc++.h>
using namespace std;
int main(){
int n; cin>>n;int g=pow(n,2);int S=0;
long long a[g+n];
for (int i=1;i<=g+n;i++){if(i%(n+1)!=0){cin>>a[i];}else a[i]=0;}
for (int i=1;i<=g+n;i++){if (a[i]==1){
if(a[i+1]!=1){S++;}
if(a[i-1]!=1){S++;}
if(a[i+n+1]!=1){S++;}
if(a[i-n-1]!=1){S++;}}}
cout<<S;
return 0;
}
