#include <iostream>
#include <algorithm>
using namespace std;
string b[50000];int z;

void permute(string &a) {
    int n = a.size();
    while (true) {
    	b[z]=a; 
    	b[z].insert(b[z].begin()+4,' '); 
    	b[z].insert(b[z].begin()+7,' ');
    	int e=int(a[0]-'0')*1000+int(a[1]-'0')*100+int(a[2]-'0')*10+int(a[3]-'0');
        if(!((a[0]=='0'&&a[1]=='0'&&a[2]=='0'&&a[3]=='0')||(a[4]=='0'&&a[5]=='0')||(a[6]=='0'&&a[7]=='0'))){ 
		if(!((a[4]-'0'>=1&&a[5]-'0'>=3)||(a[4]-'0'>1)||(a[6]-'0'>=3&&a[7]-'0'>=2)||(a[6]-'0'>3))){
		//if(a[6]<=2&&a[7]<=8){z++;break;} 
		if(((a[4]-'0'==0&&(a[5]-'0'==4||a[5]-'0'==6||a[5]-'0'==9))||(a[4]-'0'==1&&a[5]-'0'==1))&&(a[6]!=3&&a[7]!=1)) z++;
		else if(((a[0]=='3'&&a[1]=='3'&&a[2]=='2'&&a[3]=='8')||(a[0]=='6'&&a[1]=='6'&&a[2]=='5'&&a[3]=='6')||(a[0]='9'&&a[1]=='9'&&a[2]=='8'&&a[3]=='4'))&&(a[6]!=3&&a[7]!=1)) z++;
		else if((e%400==0||(e%100!=0&&e%4==0))&&a[4]==0&&a[5]==2&&(a[6]!=3)) z++;
		else if(a[4]==0&&a[5]==2&&(a[6]!=3)&&(a[6]<=2&&a[7]<9)) z++;
		else if((a[4]=='0'&&(a[5]==1||a[5]==3||a[5]==5||a[5]==7||a[5]==8))||(a[4]-'0'==1&&(a[5]=='0'||a[5]-'0'==2))) z++;}}
		//if(!((a[0]=='0'&&a[1]=='0'&&a[2]=='0'&&a[3]=='0')||(a[4]=='0'&&a[5]=='0')||(a[6]=='0'&&a[7]=='0'))) z++;
        int k, l;
        for (k = n-2; k>=0; k--) if (a[k] < a[k+1]) break;
        if (k<0) break;
        for (l = n-1; l>k; l--) if (a[k] < a[l]) break; 
        swap(a[k], a[l]);
        for (int i=k+1, j=n-1; i<j; i++, j--) swap(a[i], a[j]);
    }
    cout<<z<<endl;
}

int main() {
    //ios::sync_with_stdio(false); cin.tie(0);
    string s; getline (cin,s);
	 s.erase(s.begin() + 4);
 	 s.erase(s.begin() + 6);
    sort(s.begin(), s.end());

   /* int res = 1;//8!
    for (int i=2; i<=s.size(); i++) res *= i;
    //8=s.size()
    for (int i=1, c = 1; i<s.size(); i++) {
        if (s[i] == s[i-1]) c++, res /= c;
        else c = 1;
    }
    
    cout << res << '\n';*/
    

    permute(s);
    for(int i=0;i<z;i++) cout<<b[i]<<'\n';
    return 0;
}