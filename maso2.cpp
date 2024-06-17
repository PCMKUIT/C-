#include<bits/stdc++.h>
using namespace std;
signed main(){
    string s; cin >> s;
    vector<int> cnt(26, 0);
    long long ans = 0,tmp = 1;
    for (int i = 0; i < s.size(); i++) {
        int id = s[i] - 'a';
        for (int j = 0; j < 26; j++) if (id != j) ans += cnt[j];
        tmp = ans;
        cnt[id]++;
    }
    bool k=0;
    for(int i=0;i<26;++i){if(cnt[i] > 1){k=1; break;}}
    cout << ans + k;
}