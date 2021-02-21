#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken -99999999
using namespace std;

int solve(int n){
	if(n>=0 && n<=9){
		return 1;
	}
	string temp = to_string(n);
	int min_count = not_taken;
	for(int i=0;i<temp.length();i++){
		//int tmp = temp[i]-'0';
		int temp_ans = 1+solve(n-(temp[i]-'0'));
		min_count = min(min_count,temp_ans);
	}
	return min_count;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int res = solve(n);
    cout<<res<<endl;
    return 0;
}