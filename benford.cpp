/*#include <bits/stdc++.h>
using namespace std;
int kt(int a){
while (a>=10) a=a/10; return a;}
int main (){
int a[10];int m=0,n=0;
for (int i=1;i<=10;i++){cin>>a[i];if (kt(a[i])==1){m++;};if (kt(a[i])==4){n++;}}
if((m==3)&&(n==1)){cout<<"TRUE";} else cout <<"FALSE";
return 0;
}*/

#include <iostream>
using namespace std;
#define MAX 100
#include <bits/stdc++.h>
void Nhapmang(int a[MAX],int &n){
for (int i=1;i<=10;i++){cin>>a[i];}
return;}
int kt(int a){
while (a>=10) a=a/10; return a;}
bool isBenford(int a[MAX],int n){
int b;int m=0,d=0;
for (int i=1;i<=10;i++){b=a[i];if (kt(b)==1){m++;};if (kt(b)==4){d++;}}
if((m==3)&&(d==1)){return 1;} else return 0;}
int main()
{
	int a[MAX], n = 10;
	Nhapmang(a, n);
	if (isBenford(a, n) == true)
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;
	return 0;
}