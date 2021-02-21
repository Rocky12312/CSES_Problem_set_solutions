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
	int n = s.length();
	vector<int> lps(n,0);
	int i=1;
	int j=0;
	while(i<s.length()){
		if(s[i]==s[j]){
			lps[i]=j+1;
			i++;
			j++;
		}else{
			if(j!=0){
				j= lps[j-1];
			}else{
				lps[i] = 0;
				i++;
			}
		}
	}
	int idx = lps[n-1];
	vector<int> res;
	while(idx>0){
		res.push_back(idx);
		idx = lps[idx-1];
	}
	sort(res.begin(),res.end());
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
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
