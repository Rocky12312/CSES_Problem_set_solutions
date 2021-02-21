#include<iostream>
#include<algorithm>
#include<vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define Mod 1000000007
#define not_taken -9999999
using namespace std;

struct customer{
    int a;
    int b;
};

bool comp(customer& x,customer& y){
    return x.a<y.a;
}

void solve(vector<customer>& v){
    if(v.size()==0){
        cout<<0<<endl;
        return;
    }
    sort(v.begin(),v.end(),comp);
    int max_customer = 0;
    int temp_customer = 0;
    for(int i=0;i<v.size();i++){
        temp_customer = temp_customer+v[i].b;
        max_customer = max(max_customer,temp_customer);
    }
    cout<<max_customer<<endl;
    return;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<customer> v;
    int p,q;
    customer temp;
    for(int i=0;i<n;i++){
        cin>>p;
        cin>>q;
        temp.a = p;
        temp.b = 1;
        v.push_back(temp);
        temp.a = q;
        temp.b = -1;
        v.push_back(temp);
    }
    solve(v);
    return 0;
}