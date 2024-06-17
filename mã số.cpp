#include <bits/stdc++.h>
using namespace std;
void xau(string s){
int j=1;
for(int i=1;i<s.size()-1;i++){
if(s)[0]==s[i]){j++;s.erase(s.begin+i);}}
cout<<j<<endl; cout<<s;
return;
}
int main(){
string s;cin>>s;
xau (s);
return 0;}
