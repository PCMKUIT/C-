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
void Sort(vector<int> a){
	for(int i=1;i<a.size();i++){
		int e;
		for (e=0; e<i; e++) if(a[i]>=a[e]) {break;}
		cout<<"i="<<i<<": "<<"pos="<<a[i] <<" e="<<e<<endl;
		for(int j=e;j<=i;j++){swap(a[j],a[i]);}}
    return;}
    
int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}