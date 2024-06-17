#include <bits/stdc++.h>
using namespace std;
int main(){
long long t,b,k; cin>>t; string n;// long long a=0;
for (int i=0;i<t;i++){
cin>>n;
n='0'+n;
//while(n[i]>=10){a=round(n[i]/10); b=n[i]-a*10;
//while(n[i]%10!=0){n[i]+=b;}
int cnt=n.size()-1;
while (n.size()>=2){
int d=1;
b=n[cnt]-'0'; //if(a==1){n[i-1]=n[i-1]+1;} a=0;
if ((b==1)||(b==2)||(b==5)){k=1;}
if ((b==3)||(b==6)){k=3;}
if (b==4){k=2;}
if (b==7){k=7;}
if (b==8){k=4;}
if (b==9){k=9;}
if (b==0){k=0;}
if (n[cnt-1]-'0'+k>=10){n[cnt-1]=n[cnt-1]+k-10;while(n[cnt-1-d]-'0'==9){n[cnt-1-d]=n[cnt-1-d]-9;d++;};n[cnt-1-d]=n[cnt-1-d]+1;}//a=1;
else n[cnt-1]=n[cnt-1]+k;
n.erase(n.begin() + cnt);
cnt--;}
//n[i]=n[i]/10;
b=n[0]-'0';
if(b==9){k=9;}
if((b==8)||(b==4)||(b==2)||(b==1)||(b==5)){k=1;}
if(b==7){k=7;}
if((b==6)||(b==3)){k=3;}
if(b==0)k=0;
 cout<<k<<endl;}}