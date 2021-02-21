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
    void helper(int start,string s,vector<string> wordDict,vector<string> &ans,string till_now,unordered_map<string,bool> um){
        string temp;
        if(start==s.length()){
            ans.push_back(till_now);
            return;
        }
        for(int i=start;i<s.length();i++){
            temp=temp+s[i];
            if(um[temp]){
                if(i==s.length()-1){
                    helper(i+1,s,wordDict,ans,till_now+temp,um);
                }
                else{
                    helper(i+1,s,wordDict,ans,till_now+temp+" ",um);
                }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict){
        unordered_map<string,bool> um;
        for(int i=0;i<wordDict.size();i++){
            um[wordDict[i]] = true;
        }
        vector<string> ans;
        helper(0,s,wordDict,ans,"",um);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;cin>>n;
  string s;cin>>s;
  vector<string> wd(n,"");
  for(int i=0;i<n;i++){
    cin>>wd[i];
  }
  Solve* obj = new Solve();
  vector<string> res = obj->wordBreak(s,wd);
  for(int i=0;i<res.size();i++){
    cout<<res[i]<<endl;
  }
  return 0;
}