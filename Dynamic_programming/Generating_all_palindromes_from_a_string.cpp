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

class Solve{
public:
    vector<vector<string>> v;
    vector<string> vs;
    bool ispalindrome(string s){
        if(s.length() == 0 || s.length() == 1){
            return true;
        }
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve_helper(string s,int start){
        string temp;
        if(s.length() == start){
            v.push_back(vs);
            return;
        }
        for(int i=start;i<s.length();i++){
            temp = temp+s[i];
            if(ispalindrome(temp)){
                vs.push_back(temp);
                solve_helper(s,i+1);
                vs.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        solve_helper(s,0);
        return v;
    }
};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;cin>>s;
  Solve* obj = new Solve();
  vector<vector<string>> res = obj->partition(s);
  for(int i=0;i<res.size();i++){
  	for(int j=0;j<res[i].size();j++){
  		cout<<res[i][j]<<" ";
  	}
  	cout<<endl;
  }
  return 0;
}