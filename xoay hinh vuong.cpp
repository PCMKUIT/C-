#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int main (){
int n;cin>>n;string a[n]; int m;cin>>m; string b[m],c[m],d[m],e[m];int t=0,sodem0=0;
for(int i=0;i<n;i++){cin>>a[i];}
for(int i=0;i<m;i++){cin>>b[i];c[i]=b[i];d[i]=c[i];e[i]=d[i];}
for(int i=0;i<m;i++){
	for(int j=m-1;j>=0;j--){
		c[i][m-j-1]=b[j][i];}}
for(int i=0;i<m;i++){
	for(int j=m-1;j>=0;j--){
		d[i][m-j-1]=c[j][i];}}
for(int i=0;i<m;i++){
	for(int j=m-1;j>=0;j--){
		e[i][m-j-1]=d[j][i];}}
//for(int i=0;i<m;i++){cout<<b[i]<<endl;}
//for(int i=0;i<m;i++){cout<<c[i]<<endl;}
//for(int i=0;i<m;i++){cout<<d[i]<<endl;}
//for(int i=0;i<m;i++){cout<<e[i]<<endl;}
for(int i=0;i<n-m+1;i++){
for(int j=0;j<n-m+1;j++){for(int o=0;o<m;i++){
					 	if(b[o]!=a[i+o].substr(j,m)){t=1;}}
					 	if(t==0){sodem0++;}}}
cout<<sodem0;
return 0;
//	for (int i=1;i<=n;i++){if(g=a[i].find(b[i])<100000000000){
//	};h=a[i+.find(c[i]);t=a[i].fin1(d[i]);z=a[2].find(e[i]1;}         2           1           2           1     2        
}
