#include <bits/stdc++.h>
using namespace std;
int sum;
int save[4],ans[4],pos[4],temp[2];
bool cmp(int a , int b) { return a>b;}
void QuickSort(int a[] , int left, int right){
    int mid=left+right;
    mid/=2;
    int pivot = a[mid];
    int l = left;
    int r = right;
    do{ while((l <= right) && cmp(a[l], pivot)) l++;
        while((r >= left) && cmp(pivot, a[r]))  r--;
        if(l > r)  break;
        swap(a[l], a[r]); l++, r--;} while(l <= r);
    if(left < r) QuickSort(a, left, r);
    if(l < right)QuickSort(a, l, right);}
    
int main (){
	int N,X;
	cin>>N>>X;
	map<int,int> mp;
	int a[N],s[N];
	for(int i=0;i<N;i++) {cin>>a[i]; mp[a[i]]=i+1;}
	QuickSort(a,0,N-1);
	for(int i=0;i<N;i++){
		if(X-a[N-1]-a[N-2]-a[N-3]<0) continue;
		for(int j=i+1;j<N;j++){
			for(int j=i+1;j<N;j++){
			if(X-a[i]-a[N-1]-a[N-2]>=a[j]) {save[1]=a[j];temp[0]=j; break;}}
			for(int k=temp[0]+1;k<N;k++){
				for(int k=temp[0]+1;k<N;k++){
				if(X-a[i]-a[temp[0]]-a[k]-a[N-1]>=0) {save[2]=a[k];temp[1]=k; break;}}
				for(int l=temp[1]+1;l<N;l++){
					for(int l=temp[1]+1;l<N;l++){
					if(X-a[i]-a[temp[0]]-a[temp[1]]-a[l]>=0) {save[3]=a[l]; break;}}
		if(a[i]==0||save[1]==0||save[2]==0||save[3]==0) continue;
		s[i]=a[i]+save[1]+save[2]+save[3];
		if(s[i]>X)  continue;
		if(s[i]>sum){sum=s[i];ans[0]=a[i]; for(int i=1;i<4;i++) ans[i]=save[i];}}}}}
	pos[0]=mp[ans[0]];pos[1]=mp[ans[1]];pos[2]=mp[ans[2]];pos[3]=mp[ans[3]];
	QuickSort(pos,0,3);		
	if(sum>X||sum==0||pos[0]==0||pos[1]==0||pos[2]==0||pos[3]==0) cout<<"Impossible";
	else {cout<<sum<<endl;
		  for(int i=3;i>=0;i--) cout<<pos[i]<<" ";}
	return 0;}