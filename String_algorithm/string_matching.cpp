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

void solve(string raw_txt,string patt){
	vector<int> lps(patt.size(),0);
	int i=1;
	int j=0;
	while(i<patt.size()){
		if(patt[i]==patt[j]){
			lps[i] = j+1;
			j++;
			i++;
		}else{
			if(j!=0){
				j = lps[j-1];
			}else{
				lps[i] = 0;
				i++;
			}
		}
	}
	i=0;
	j=0;
	int count = 0;
	while(i<raw_txt.size()){
		if(raw_txt[i]==patt[j]){
			i++;
			j++;
		}
		if(j==patt.size()){
			count++;
			j = lps[j-1];
		}else if(i<raw_txt.size() && raw_txt[i]!=patt[j]){
			if(j!=0){
				j = lps[j-1];
			}else{
				i++;
			}
		}
	}
	cout<<count<<endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string raw_txt;
  string patt;
  cin>>raw_txt>>patt;
  solve(raw_txt,patt);
  return 0;
}
