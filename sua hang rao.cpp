#include <bits/stdc++.h>
#define loading; ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
const int N=1e5+7;
using namespace std;
int n,m,a[N],b[N],c[N],d[2*N],l=1e8+7,mid,r1,r,ans,cnt;
bool kt (int mid){
	int save=1;
	for(int i=1;i<=n;i++){
		for (int j=save;j<=m;j++){
			if(a[i]>=mid) {c[i]=a[i];break;}
			if(a[i]+b[j]>=mid) {c[i]=a[i]+b[j];save=j+1;break;}
		}
		if(a[i]>=mid) {c[i]=a[i];}
		if(c[i]!=0) c[i]=0; else return 0;
	}
	return 1;
}
int main (){
	loading;
	int r2=r1;
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i];l=min(l,a[i]);r1=max(r1,a[i]);}
	cin>>m;
	for(int i=1;i<=m;i++){cin>>b[i];r2=max(r2,b[i]);}
	r=r1+r2;;  
	while(l<=r){
		mid=(l+r)>>1; 
		if(kt(mid)!=0){
			 ans=mid;
			 l = mid + 1;}
		else r = mid - 1;
	}
	int save=1;cnt=0; int k = 0; 
	for(int i=1;i<=n;i++){
		for (int j=save;j<=m;j++){
			if(a[i]>=ans) {break;}
			if(a[i]+b[j]>=ans) {d[k++]=i;d[k++]=j;cnt++;save=j+1;break;}
		}}
	cout<<ans<<" "<<cnt<<endl;
	int z = 0;
	while(d[z]!=0){cout<<d[z]<<" "<<d[z+1]<<endl;z+=2;}
	return 0;
}