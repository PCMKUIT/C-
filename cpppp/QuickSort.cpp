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
void Recursion(vector<int> &a, int l, int r){
    int pivot=a[(l+r)/2];
    int i=l, j=r;
     cout<<"["<<l<<" - "<<r<<"]: ";
    while(i<j){
        while(a[i]<pivot) i++;
        while(a[j]>pivot) j--;
        if(i<=j) {
            swap(a[i], a[j]);
            i++;j--;}}
    for (int i=l;i<=r;i++) cout<<a[i]<<"\t";
    cout<<"\n";
    if(l<j) Recursion(a,l,j);
    if(i<r) Recursion(a,i,r);}

void Sort(vector<int> a){
	Recursion(a,0,a.size()-1);}
int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}