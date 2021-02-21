#include<iostream>
#include<algorithm>
#include<vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken 9999999
#define INT_MAX +2147483647
#define INT_MIN -2147483648
using namespace std;

struct node{
	int s_day;
	int e_day;
	int reward;
};

bool comp(node& a,node& b){
    return a.e_day<b.e_day;
}

void solve(int n,node arr[]){
    sort(arr,arr+n,comp);
    int lim_arr[n];
    for(int i=0;i<n;i++){
        lim_arr[i] = arr[i].reward;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j].e_day<arr[i].s_day && lim_arr[i]<lim_arr[j]+arr[i].reward){
                lim_arr[i] = lim_arr[j]+arr[i].reward;
            }
        }
    }
    int max_reward = INT_MIN;
    for(int i=0;i<n;i++){
        max_reward = max(max_reward,lim_arr[i]);
    }
    cout<<max_reward<<endl;
    return;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    node arr[n];
    node temp;
    for(int i=0;i<n;i++){
    	cin>>temp.s_day>>temp.e_day>>temp.reward;
    	arr[i] = temp;
    }
    solve(n,arr);
    return 0;
}