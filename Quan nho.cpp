//tam giac can rong
#include<bits/stdc++.h>
int h,i,j;
using namespace std;
main(){
cin>>h;
for(i=1;i<h;i++){cout<<" ";}
cout<<"*\n";
for(i=2;i<h;i++)
{
for(j=1;j<=h-i;j++) {cout<<" ";}
cout<<"*";
for(j=2;j<=i*2-2;j++) {cout<<" ";}
cout<<"*\n";
}
for (i=1;i<=h;i++) {cout<<"* ";}
return 0;
}