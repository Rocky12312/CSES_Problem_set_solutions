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

/*struct node{
	string str;
	int idx;
};

bool compare(node& a,node& b){
	return a.str<b.str;
}

void solve(string s){
	string t = s;
	sort(t.begin(),t.end());
	if(t[0]==t[t.length()-1]){
		cout<<t<<endl;
		return;
	}
	char x = t[0];
	vector<int> pos;
	for(int i=0;i<s.length();i++){
		if(s[i]==x){
			pos.push_back(i);
		}
	}
	if(pos.size()==1){
		string res = s.substr(pos[0]);
		res = res+s.substr(0,pos[0]);
		cout<<res<<endl;
		return;
	}
	int res_idx = -1;
	vector<node> v;
	node temp;
	for(int i=0;i<pos.size();i++){
		if(i+1<pos.size()){
			temp.str = s.substr(pos[i],pos[i+1]-pos[i]);
			temp.idx = pos[i];
			v.push_back(temp);
		}else{
			temp.str = s.substr(pos[i]);
			temp.str = temp.str+s.substr(0,pos[0]);
			temp.idx = pos[i];
			v.push_back(temp);
		}
	}
	sort(v.begin(),v.end(),compare);
	int final_idx = v[0].idx;
	string res_final = "";
	res_final = res_final+s.substr(final_idx);
	res_final = res_final+s.substr(0,final_idx);
	cout<<res_final<<endl;
	return;
}*/

void solve(string s){
    s+=s;
    int n = s.size();
    int i = 0;
    int ans = 0;
    while (i < n/2) {
        ans = i;
        int k = i, j = i + 1;
        while (j < n && s[j] >= s[k]) {
            if (s[j] == s[k]) k++;
            if (s[j] > s[k] ) k = i;
            j++;
        }
        while(i <= k) i += j - k;
    }
    cout<<s.substr(ans,n/2);
}    

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin>>s;
  solve(s);
  return 0;
}
