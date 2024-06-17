#include <bits/stdc++.h>
using namespace std;
int main(){
string chuoi;
getline (cin,chuoi);int a=0,j=0;
while(chuoi[a]==' '){j++;a++;} 
chuoi=chuoi.substr(j,chuoi.size());
chuoi[0]=toupper (chuoi[0]);
for (int i=1;i<chuoi.size();i++){if (chuoi[i-1]==' '){chuoi[i]=toupper (chuoi[i]);
} else { chuoi[i]= tolower (chuoi[i]);
}}
for (int i=1;i<chuoi.size();i++){if ((chuoi[i]==' ')&&(chuoi[i+1]==' ')){chuoi.erase(chuoi.begin()+i);i--;
}
}
cout<<chuoi;
return 0;
}
