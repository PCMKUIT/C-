#include <bits/stdc++.h>
#define MAXR 500
#define MAXC 500
using namespace std;
void NhapMaTran(double a[MAXR][MAXC],int &n,int m){
	cin>>n;cin>>m;
for (int i=0;i<n;i++){
for (int j=0;j<n;j++){cin>>a[i][j];}}
return;}
void Frobenius(double a[MAXR][MAXC],int &n){ 
    int m=0;int e=-1;
    for(int i=0; i<n; i++){
   		 if(a[i][i]!=1){cout<< "No";return;}}
    for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if((a[i][j] !=0)){cout<<"No";return;}}}
	for(int i=0;i<n;i++){
		for(int j=i+1; j<n; j++){
		if(e==i)continue;
		if((a[j][i] !=0)){e=i;m++;}}}
	
	if (m<=1){cout<<"Yes";} else {cout<<"No";} return;}
	int main() {
    double a[MAXR][MAXC];int n,m;
    NhapMaTran(a, n,m);
    Frobenius(a, n);
    return 0;
}