#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
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
const int sz = 1e5+5;
using namespace std;

struct node{
	int val;
	node* child[sz];
	node(int d){
		val = d;
		for(int ix=0;ix<sz;ix++){
			child[ix] = NULL;
		}
	}
};

node* generate_tree(int n,int arr[]){
	unordered_map<int,node*> um;
	node* root = new node(1);
	um[1] = root;
	for(int i=2;i<=n;i++){
		if(um.find(arr[i])!=um.end()){
			if(um.find(i)==um.end()){
				um[i] = new node(i);
				for(int j=0;j<sz;j++){
					if(um[arr[i]]->child[j]==NULL){
						um[arr[i]]->child[j] = um[i];
						break;
					}
				}
			}else{
				for(int j=0;j<sz;j++){
					if(um[arr[i]]->child[j]==NULL){
						um[arr[i]]->child[j] = um[i];
						break;
					}
				}	
			}
		}else{
			if(um.find(i)!=um.end()){
				um[arr[i]] = new node(arr[i]);
				um[arr[i]]->child[0] = um[i];
			}else{
				um[arr[i]] = new node(arr[i]);
				um[i] = new node(i);
				um[arr[i]]->child[0] = um[i];
			}
		}
	}
	return root;
}

void levelorder_traversal(node* root){
	queue<node*> q;
	q.push(root);
	while(q.empty()==false){
		node* temp = q.front();
		cout<<temp->val-1<<" ";
		q.pop();
		for(int idx=0;idx<sz;idx++){
			if(temp->child[idx]!=NULL){
				q.push(temp->child[idx]);
			}
		}
	}
	return;
}

int generating_bsum_tree(node* root){
	if(root == NULL){
		return 0;
	}
	int sum = 0;
	for(int idx=0;idx<sz;idx++){
		sum = sum+generating_bsum_tree(root->child[idx]);
	}
	root->val = 1+sum;
	return root->val;
}

void solve(int n,int arr[]){
	node* root = generate_tree(n,arr);
	int temp_res = generating_bsum_tree(root);
	levelorder_traversal(root);
	return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  int arr[n+1];
  for(int i=2;i<=n;i++){
  	cin>>arr[i];
  }
  solve(n,arr);
  return 0;
}