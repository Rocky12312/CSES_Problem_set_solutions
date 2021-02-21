#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken 9999999
using namespace std;

void solve(string s,string t){
    int len1 = s.length();
    int len2 = t.length();
    int nx[len1+1][len2+1];
    for(int i=0;i<len1+1;i++){
        for(int j=0;j<len2+1;j++){
            if(i==0){
                nx[i][j] = j;
            }else if(j==0){
                nx[i][j] = i;
            }
        }
    }
    for(int i=1;i<len1+1;i++){
        for(int j=1;j<len2+1;j++){
            if(s[i-1]==t[j-1]){
                nx[i][j] = nx[i-1][j-1];
            }else{
                nx[i][j] = 1+min(nx[i-1][j-1],min(nx[i-1][j],nx[i][j-1]));
            }
        }
    }
    cout<<nx[len1][len2]<<endl;
    return;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    string t;
    cin>>t;
    solve(s,t);
    return 0;
}