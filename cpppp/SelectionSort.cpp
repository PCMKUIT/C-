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
void Sort(vector <int> A) {
	int max,i,j;
	int n=A.size();
	for (i=0;i<n-1;i++) {
	max=i;
	for (j=i+1;j<n;j++)
	if (A[j]>A[max]) max=j;
	swap(A[i],A[max]);
	cout<<"i="<<i<<": swap ("<<A[max]<<"-"<<A[i]<<")\n";}
	return;}
int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}