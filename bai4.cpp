#include <bits/stdc++.h>
#include<stdio.h>
#include <string.h>
using namespace std;
int main(){
string a,s;
cin>>a;
for (int i=0;i<a.size();i++){s=s+a[a.size()-i-1];} 
if (s==a){cout<<"YES";
} else {cout<<"NO";
}
return 0;
}