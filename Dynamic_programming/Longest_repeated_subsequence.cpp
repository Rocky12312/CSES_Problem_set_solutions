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

void solve(string s){
	string t = s;
	int a = s.length();
	int nx[a+1][a+1];
	for(int i=0;i<a+1;i++){
		nx[i][0] = 0;
	}
	for(int i=0;i<a+1;i++){
		nx[0][i] = 0;
	}
	for(int i=1;i<a+1;i++){
		for(int j=1;j<a+1;j++){
			if(i-1!=j-1 && s[i-1]==s[j-1]){
				nx[i][j] = 1+nx[i-1][j-1];
			}else{
				nx[i][j] = max(nx[i-1][j],nx[i][j-1]);
			}
		}
	}
	int i=a;
	int j=a;
	string res = "";
	while(i>0 && j>0){
		if(s[i-1]==s[j-1] && i-1!=j-1){
			res.push_back(s[i-1]);
			i=i-1;
			j=j-1;
		}else{
			if(nx[i-1][j]>nx[i][j-1]){
				i = i-1;
			}else{
				j = j-1;
			}
		}
	}
	reverse(res.begin(),res.end());
	cout<<res<<endl;
	cout<<nx[a][a]<<endl;
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin>>s;
  solve(s);
  return 0;
}
