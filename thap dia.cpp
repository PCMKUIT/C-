#include <bits/stdc++.h>
#define loading; ios_base::sync_with_stdio(0),cin.tie(nullptr);
#define N 1000001
using namespace std;

int n,i,cnt=1, a[N], b[N];

int main(){
    loading;
    cin >> n; i=n;
    for(int j = 1; j <= n; j++){cin >> a[j];b[a[j]] = j;}
    while(i>=1){
        while(cnt<b[i]){cout << '\n'; cnt++;}
        while(b[i] <= cnt){if(i==0)break; cout << i << ' '; i--;}
    }
    return 0;
}