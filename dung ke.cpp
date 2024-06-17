#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n; ll x,b,a; double c;
vector <ll> arr;
int main(){
	cin>>n>>x;
	arr.push_back(n);
	if(x>((n-2)*(n-1)/2)) cout<<-1;
	else{
	c=(2*n-3-sqrt(pow(3-2*n,2)-8*x))/2;
	if(c>int(c)) c=int(c)+1; 
	a=1ll*c;
	b= n-x-1+((a-1)*(n-1)-((a-1)*a)/2);
	if(b!=0) arr.push_back(b);
	for(int i=a-(b>0);i>=1;i--){
		arr.push_back(i);}
		arr.push_back(n-1);
	for(int i=n-2;i>=a+1-(b>0);i--){
		if(i==b) continue;
		arr.push_back(i);}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";}}
	return 0;}