#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

int myStrcmp(char s1[], char s2[]);
int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);
void StringReverse(char st[]);

int main()
{
	char s[MAX];
	cin.getline(s,MAX);
	if (myStrcmp(s, "") == 0)
		cout << "Chuoi rong." << endl;
	else
	{
		StringReverse(s);
		cout << s << endl;
	}
	return 0;
}
int myStrlen(char s[],int k){
		int d = 0;
 		while (s[d]  !=  '\0')
 		{d++;}
		return d;
	}

int myStrcmp(char s1[], char s2[])
{   int l=myStrlen(s1,0);
    for (int i=0;i<l;i++)
    {if (s1[i]!=s2[i]) return 1; }
    return 0;
}
	bool myStrcat (char s1[], char s2[])
{
		int m,n;
		for(m=0; s1[m]!='\0' && s1[m+1]!='\0'; ++m);
   		for(n=0; s2[n]!='\0'; ++n, ++m){
      	s1[m]=s2[n];}
      	s1[m]='\0';
		if(myStrlen(s1,0) < MAX)  return true;
		return false;
}
void mySubstr(char s[], int b, int count, char ss[])
{ int j=b;
    for(int i = count;i<=b;i++,j--){
        ss[i] = s[j];}
        if(b!=myStrlen(s,0))ss[b+1]=' ';
    return ;
}
void myStrcpy(char s[], int vt, char s1[], int k){
	for(int i=0;i<myStrlen(s,0);i++){
		s1[i]=s[i];
	}
	s1[myStrlen(s,0)]='\0';
}
void StringReverse(char st[]){
	int j=0,cnt=0;
	int l=myStrlen(st,0);
	char ss[l+1]; 
	for (int i=0;i<l;i++){
		if(st[i]==' '||i==l-1) {if(i==l-1)i++;mySubstr(st,i-1,cnt,ss);cnt=i+1;}}
	//if(cnt==0){for(int i=0;i<l;i++){ss[i]=st[l-i-1];}}
	ss[l]='\0';
	myStrcpy(ss,0,st,0);	
}