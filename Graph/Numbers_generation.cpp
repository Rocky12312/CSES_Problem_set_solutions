/*#include<iostream>
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

void solve_helper(string or_st,int s_idx,string& s_temp,vector<string>& vs,unordered_map<int,string>& um){
	if(s_temp.length()==or_st.length()){
		vs.push_back(s_temp);
		return;
	}
	for(int idx=0;idx<3;idx++){
		char x = um[or_st[s_idx]-'0'][idx];
		s_temp = s_temp+x;
		solve_helper(or_st,s_idx+1,s_temp,vs,um);
		s_temp.pop_back();
	}

	return;
}

void solve(int n){
	unordered_map<int,string> um;
	string temp = "ABC";
	um[2] = temp;
	for(int i=3;i<=9;i++){
		for(int j=0;j<3;j++){
			temp[j] = ((temp[j]-'0')+3)+'0';
		}
		um[i] = temp;
	}
	vector<string> vs;
	string s_temp = "";
	int s_idx = 0;
	string or_st = to_string(n);
	solve_helper(or_st,s_idx,s_temp,vs,um);
	for(int i=0;i<vs.size();i++){
		cout<<vs[i]<<endl;
	}
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
  	int n;
  	cin>>n;
  	solve(n);
  }
  return 0;
}*/


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

void solve_helper(string or_st,int n,int s_idx,string& s_temp,vector<string>& vs,unordered_map<int,string>& um,unordered_map<int,vector<bool>>& visited){
	if(s_temp.length()==or_st.length()){
		vs.push_back(s_temp);
		return;
	}
	for(int idx=0;idx<3;idx++){
		if(visited[or_st[s_idx]-'0'][idx]==false){
			visited[or_st[s_idx]-'0'][idx]=true;
			char x = um[or_st[s_idx]-'0'][idx];
			s_temp = s_temp+x;
			solve_helper(or_st,n,s_idx+1,s_temp,vs,um,visited);
			s_temp.pop_back();
			visited[or_st[s_idx]-'0'][idx]=false;
		}
	}
	return;
}

void solve(int n){
	unordered_map<int,string> um;
	string temp = "ABC";
	um[2] = temp;
	for(int i=3;i<=9;i++){
		for(int j=0;j<3;j++){
			temp[j] = ((temp[j]-'0')+3)+'0';
		}
		um[i] = temp;
	}
	vector<string> vs;
	string s_temp = "";
	int s_idx = 0;
	string or_st = to_string(n);
	unordered_map<int,vector<bool>> visited;
	for(int i=0;i<or_st.length();i++){
		vector<bool> op(3,false);
		visited[or_st[i]-'0'] = op;
	}
	solve_helper(or_st,n,s_idx,s_temp,vs,um,visited);
	for(int i=0;i<vs.size();i++){
		cout<<vs[i]<<endl;
	}
	cout<<vs.size()<<endl;
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
  	int n;
  	cin>>n;
  	solve(n);
  }
  return 0;
}
