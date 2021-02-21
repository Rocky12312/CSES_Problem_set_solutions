#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#pragma GCC optimize("Ofast")	
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define INT_MAX +2147483647
#define INT_MIN -2147483648
#define ulmax 4294967295
#define llmin -9223372036854775808
#define llmax 9223372036854775807
#define ullmax 18446744073709551615 
using namespace std;

int solve(int n,int f){
	if(f==1 || f==0){
		return f;
	}
	if(n==1){
		return f;
	}
	int op = INT_MAX;
	for(int k=1;k<f+1;k++){
		int upper_part = solve(n,f-k);//Egg doesn't breaks
		int lower_part = solve(n-1,k-1);//Egg breaks
		op = min(op,max(upper_part,lower_part));
	}
	return 1+op;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;cin>>n;
  int f;cin>>f;
  int res = solve(n,f);
  cout<<res<<endl;
  return 0;
}

