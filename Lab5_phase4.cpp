#include <bits/stdc++.h>
using namespace std;
int func4(int a1, int a2, int a3){
	int result;
	int v4 = (a3 - a2) / 2 + a2;
  if ( v4 <= a1 )
  {
    if ( v4 >= a1 )
      result = 0;
    else
      result = 2 * func4(a1, v4 + 1, a3) + 1;
  }
  else
  {
    result = 2 * func4(a1, a2, v4 - 1);
  }
  return result;
}
int main(){
	int mark[15]={0};
	int cnt=0;
	int end;
	cout<<"The result of the function with v3 runs from 0 to 14: ";
	for (int i=0;i<=14;i++) {cout<<func4(i,0,14); if(func4(i,0,14)==1) {mark[cnt]=i;cnt++;}}
	if(mark[0]!=0) cout<<"\nfunc4()=1 when v3 = {";
	for (end=0;mark[end]!=0;end++);
	end--;
	for(int i=0;i<=end;i++){cout<<mark[i]; if(i!=end) cout<<",";}
	cout<<"}\nSo the answer is:\n";
	for(int i=0;i<=end;i++){cout<<mark[i]<<" 1";if(i!=end) cout<<"\n";}
	return 0;
}