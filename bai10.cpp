#include <bits/stdc++.h>
using namespace std;
int main(){
long long t,a,b; cin>>t; long long n[t];
for (int i=0;i<t;i++){
cin>>n[i];
while(n[i]>=10){a=round(n[i]/10); b=n[i]-a*10;
//while(n[i]%10!=0){n[i]+=b;}
if ((b==1)||(b==2)||(b==5)){n[i]=n[i]-b+10;}
if ((b==3)||(b==6)){n[i]=n[i]-b+30;}
if (b==4){n[i]=n[i]-b+20;}
if (b==7){n[i]=n[i]-b+70;}
if (b==8){n[i]=n[i]-b+40;}
if (b==9){n[i]=n[i]-b+90;}
n[i]=n[i]/10;
}
if(n[i]==9){n[i]=9;}
if((n[i]==8)||(n[i]==4)||(n[i]==2)||(n[i]==1)||(n[i]==5)){n[i]=1;}
if(n[i]==7){n[i]=7;}
if((n[i]==6)||(n[i]==3)){n[i]=3;}
}
for (int i=0;i<t;i++) cout<<n[i]<<endl;
return 0;}

