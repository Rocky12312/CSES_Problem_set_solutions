#include<iostream>
#include<algorithm>
#include<vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken -9999999
using namespace std;

void solve(int k,vector<int> v,int pos){
	if(v.size()==1){
		cout<<v[0]<<endl;
		return;
	}
	pos = (pos+k)%v.size();
	cout<<v[pos]<<" ";
	v.erase(v.begin()+pos);
	solve(k,v,pos);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v;
    for(int i=1;i<=n;i++){
    	v.push_back(i);
    }
    solve(1,v,0);
    return 0;
}