#include <iostream>
#include <math.h>
#include <cctype>
#include <string>
using namespace std;
int main(){
string chuoi;
getline (cin,chuoi);
for (int i=0;i<chuoi.size();i++){if (chuoi[i]==' '){ 
}
}
chuoi[0]=toupper (chuoi[0]);
for (int i=1;i<chuoi.size();i++){if (chuoi[i-1]==' '){chuoi[i]=toupper (chuoi[i]);
} else { chuoi[i]= tolower (chuoi[i]);
}}
cout<<chuoi;
return 0;
}