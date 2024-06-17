#include <bits/stdc++.h>
using namespace std;
int N,X,ans;
typedef pair<int,int> pii;
map <int,vector<pii>> mp;

bool cmp(int a , int b) { return a<b;}
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
    
int main(){
    cin>>N>>X;
    int a[N+1],pos[4];
    for(int i = 1; i <= N; i++){
        cin>>a[i]; 
        for(int j = 1; j < i; j++){
            int sum = a[i] + a[j];
            if(sum >= X) continue;
            if(mp.find(X-sum) != mp.end()){
                for(pii P : mp[X-sum]){
                    if(P.first != j && P.second != j && P.first != i && P.second != i){
                    	pos[0]=P.first; pos[1]=P.second; pos[2]=i; pos[3]=j;
                    	QuickSort(pos,0,3);
                    	for(int i=0;i<4;i++) ans+=a[pos[i]];
                    	cout<<ans<<"\n";
						for(int i=0;i<4;i++) cout<<pos[i]<<" ";
                        return 0;}}}
		else mp[sum].push_back({j, i});}}
    if(true) cout<<"Impossible";
    return 0;}