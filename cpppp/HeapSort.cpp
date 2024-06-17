#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &v)
{
	int tmp;
	cin >> tmp;
	while (tmp >= 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}
void Recursion(vector<int> &a, int n, int i, int &cnt) {
	int l=i*2+1;
	int r=l+1;
	int max=i;
	if (l<n&&a[max]<a[l]) max=l;
	if (r<n&&a[max]<a[r]) max=r;
	if (max!=i) {
        cnt++;
		swap(a[max],a[i]);
		Recursion(a,n,max,cnt);}}
		
void Sort(vector<int> a) {
    int n=a.size();
	int cnt=0;
	cout<<"\nN="<<n<<":\t";
    for (int i=0;i<a.size();i++) cout<<a[i]<<"\t";
    cout<<"\n";
	for (int i=n/2-1;i>-1;i--) Recursion(a,n,i,cnt);
	cout<<"swap: "<<cnt<<endl;
	int size=n;
	for (int i=n-1; i>0; i--){
		swap(a[0], a[i]);
		cnt=0;
        cout<<"\nN="<<--size<<":\t";
        for (int j=0;j<n; j++) cout<<a[j]<<"\t";
        cout<<"\n";
		Recursion(a,size,0,cnt);
        cout<<"swap: "<<cnt<<"\n";}}
int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}