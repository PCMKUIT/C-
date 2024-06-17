#include <bits/stdc++.h>
using namespace std;
#define MAX 500000
int n,l=1e6,m,r=0,a[MAX],ans;

int kt(int m){
	int cnt=0;
	for(int i=0;i<n;i++){
		if(a[i]>m) cnt++;}
	return cnt;}
	
int main (){
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		l=min(l,a[i]);
		r=max(r,a[i]);}
	while(l<=r){
		m=(l+r)>>1;
		if(kt(m)<=m){
			ans=m;
			r=m-1;}
		else l=m+1;}
		
	cout<<ans;
	return 0;}