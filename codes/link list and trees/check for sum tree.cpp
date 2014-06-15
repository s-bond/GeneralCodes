//============================================================================
// Author      : Bond
// Institute   : IIIT A
//============================================================================
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <set>
#include <cmath>
#include <ctime>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <functional>
#include <sstream>
#include <limits.h>
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({long long int t;scanf("%I64d",&t);t;})
#define PInt(a) printf("%d\n",(a))
#define PLng(a) printf("%I64d\n",(a))
#define FOR(i,a,b) for((i)=(a);(i)<(b);i++)
#define FORR(i,b,a) for((i)=(b);(i)>=(a);(i)--)
#define FORV(i,v) for((i)=0;(i)<v.size();i++)
#define FORI(it,v) for( typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define All(v) v.begin(),v.end()
#define BS(v,val) (lower_bound(All(v),val)-v.begin())
#define pb(a) push_back((a))
#define Clear(a) memset((a),0,sizeof(a))
#define SV(v) sort((v).begin(),(v).end())
#define SA(a,n) sort((a),(a)+(n))
#define mp make_pair
#define IT ::iterator
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<string,int> msi;
typedef pair<int,int> pii;
typedef vector<pii> vp;
typedef vector< vector<int> > vvi;
typedef pair <int, long > pil;
typedef pair <long, long > pll;
typedef set <int> si;
typedef set <LL> sl;
typedef priority_queue <int> PQ;
int N, K, M;
class node {public:int info; node*left,*right;};
queue < node* > q;
node *root, *temp;
node *make_node(int x);
void Ins(int x);
void in_order(node *t);
int _do(node *t){
	if(!t)
		return 0;
	if(t->left==NULL && t->right==NULL)
		return t->info;
	int left  = _do(t->left);
	int right = _do(t->right);
	int _root = t->info;
	if(_root == left+right){
		return _root+left+right;
	}
	else
		return INT_MAX;
}

int main () {
	int  j = 0, k, t, res;
	root = temp = NULL;
	vi v;
	while(1){
		cin >> t;
		switch(t){
		case 1://insert
			if(root==NULL){
				root = new node;
				cin >> k;
				root = make_node(k);
				q.push(root);
				}
			else{
				//temp = root;
				cin >> k;
				Ins(k);
				}
			j++;
			break;
		case 2://traverse
			cout<<endl;
			res = _do(root);
			res>>=1;
			cout<<res<<endl;
			if(res==root->info)
				cout<<"YES\n";
			else
				cout<<"NO\n";
			cout<<endl;
			break;
		case 3:
			exit(0);
			break;
		default:
			cout<<"invalid\n";
			break;
		}
		}
	return EXIT_SUCCESS;
}

node *make_node(int x){
	node *t;
	t = new node;
	t->info = x;
	t->left = t->right = NULL;
	return t;
	}
void Ins(int x){
	node *temp1 = q.front();
	if(temp1->left==NULL){
		temp1->left = make_node(x);
		q.push(temp1->left);
	}
	else if(temp1->right==NULL){
		temp1->right = make_node(x);
		q.push(temp1->right);
	}
	else{
		q.pop();
		Ins(x);
	}
}
void in_order(node *t){
	if(t){
		in_order(t->left);
		cout<<t->info<<" -> ";
		in_order(t->right);
		}
	}


