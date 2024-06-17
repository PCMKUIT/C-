#include <bits/stdc++.h>
#include<i
using namespace std;
long long size(long long a){
	int i=0;
while (a!=0){a/=10;i++;}
return i;}
signed main (){
ios::sync_with_stdio(0);
cin.tie(NULL),cout.tie(NULL);
int r,c;cin>>r>>c;long long a[r][c], max[10000], b[r][c],ans[r+c];
for(int i=0;i<r;i++){
for(int j=0;j<c;j++){cin>>a[i][j];b[i][j]=a[i][j];}}
for(int j=0;j<c;j++){
for(int i=0;i<r;i++){if(a[i][j]<0){b[i][j]=-10*b[i][j];}
if(b[i][j]>max[j]){max[j]=b[i][j];}}ans[j]=size(max[j]);}
for(int i=0;i<r;i++){
for(int j=0;j<c;j++){cout<<setw(ans[j])<<right<<a[i][j]<<" ";if(j==c-1)cout<<endl;}}
return 0;}