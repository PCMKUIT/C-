#include <bits/stdc++.h>
using namespace std;
bool kt(char a,char b){
	if((a!='a'&&a!='e'&&a!='i'&&a!='o'&&a!='u'&&a!='y'&&a!='w')&&(b!='a'&&b!='e'&&b!='i'&&b!='o'&&b!='u'&&b!='y'&&b!='w')){
		return true;}
		return false;}
int main (){
	ios::sync_with_stdio(0), cin.tie(NULL),cout.tie(NULL);
	string s;cin>>s;int x,y,m=0, cnt=0;char a[24]; a[0]='b';int t[24]={0};
	for (int i=1;i<25;i++){a[i]=a[0]+i;}
	for (int i=0;i<s.size();i++){
		for (int j=0;j<25;j++){if(s[i]==toupper(a[j])||s[i]==a[j]) x=j;
							   if(s[i+1]==toupper(a[j])||s[i+1]==a[j]) y=j;}
		if((s[i]==a[x])&&(t[x]==1)){s[i]=toupper (s[i]);m=1;}
						  else if((s[i]==a[x])&&(t[x]==2)){m=2;} else m=0;
		if(m==1) {cnt=1;continue;}
		if(m==2) {cnt=0;continue;}
		if(kt(s[i],s[i+1]))	{
		if(cnt%2==0){s[i]=toupper (s[i]);if(s[i]==toupper(a[x])&&t[x]!=2) {t[x]=1;}}//upper 2 lan ko anh huong ket qua
		else if(s[i+1]==a[y]&&t[y]!=2) {t[y]=1;s[i+1]=toupper (s[i+1]);}}
		else cnt=1;
		if (kt(s[i],'k')) {if(s[i]==a[x]&&t[x]!=1) {t[x]=2;}}
		cnt++;}
		cout<<s;
		return 0;
	}
