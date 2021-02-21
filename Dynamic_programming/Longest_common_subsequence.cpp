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

//Top down
void solve(string s,string t){
	int a = s.length();
	int b = t.length();
	int nx[a+1][b+1];
	for(int i=0;i<a+1;i++){
		nx[i][0] = 0;
	}
	for(int i=0;i<b+1;i++){
		nx[0][i] = 0;
	}
	for(int i=1;i<a+1;i++){
		for(int j=1;j<b+1;j++){
			if(s[i-1]==t[j-1]){
				nx[i][j] = 1+nx[i-1][j-1];
			}else{
				nx[i][j] = max(nx[i-1][j],nx[i][j-1]);
			}
		}
	}
	cout<<nx[a][b]<<endl;
	return;
}

//Recursive
/*int lcs(string s,string t,int a,int b){
	if(a<0 || b<0){
		return 0;
	}
	if(s[a]==t[b]){
		return 1+lcs(s,t,a-1,b-1);
	}else{
		return max(lcs(s,t,a,b-1),lcs(s,t,a-1,b));
	}
}

void solve(string s,string t){
	int res = lcs(s,t,s.length()-1,t.length()-1);
	cout<<res<<endl;
	return;
}*/

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s,t;
  cin>>s>>t;
  solve(s,t);
  return 0;
}
