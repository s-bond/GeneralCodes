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
#define FORV(i,v) for((i)=0;i<v.size();i++)
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
class node{
public:
	int info;
	node *left;
	node *right;
};
void do_inorder(node *);
node *make_node(int);
vi in, pre;
int IDX;
#define debug 1
node *make_tree(int Left, int Right){
	if(Left>Right)
		return NULL;
	int x = pre[IDX++];
	node *t = make_node(x);
	int i, j;
	FOR(i,Left,Right+1){
		if(in[i]==x)
			break;
	}
#if debug
	cout<<"NODE == "<<x<<endl;
	cout<<"LEFT == ";
	FOR(j,Left,i)
		cout<<in[j]<<" ";
	cout<<endl;
	cout<<"Right == ";
	FOR(j,i+1,Right)
		cout<<in[j]<<" ";
	cout<<endl;
#endif
	t->left = make_tree(Left,i-1);
	t->right = make_tree(i+1,Right);
	return t;
}
int main(){
	int i, j, N;
	node *root;
	N = GI;
	cout<<"enter in-order";
	FOR(i,0,N){
		cin >> j;
		in.pb(j);
	}
	cout<<"enter pre-order";
	FOR(i,0,N){
		cin >> j;
		pre.pb(j);
	}
	root = make_tree(0,N-1);
	cout<<endl;
	do_inorder(root);
}
node *make_node(int x){
	node *t;
	t = new node;
	t->info  = x;
	t->left  = NULL;
	t->right = NULL;
	return t;
}
void do_inorder(node *t){
	if(t){
		do_inorder(t->left);
		cout<<t->info<<" -> ";
		do_inorder(t->right);
	}
}


/*//============================================================================
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
#define FORV(i,v) for((i)=0;i<v.size();i++)
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
class node{
public:
	int info;
	node *left;
	node *right;
};
void do_inorder(node *);
node *make_node(int);
vi in, pre;
int IDX;
#define debug 0
node *make_tree(vi v){
	if(!v.size())
		return NULL;
	int x = pre[IDX++];
	node *t = make_node(x);
	vi left, right;
	int i, j;
	FORV(i,v){
		if(v[i]!=x)
			left.pb(v[i]);
		else
			break;
	}
	FOR(j,i+1,v.size()){
		right.pb(v[j]);
	}
#if debug
	cout<<"NODE == "<<x<<endl;
	cout<<"LEFT == ";
	FORV(i,left)
		cout<<v[i]<<" -> ";
	cout<<endl;
	cout<<"Right == ";
	FORV(i,right)
		cout<<right[i]<<" -> ";
	cout<<endl;
#endif
	t->left = make_tree(left);
	t->right = make_tree(right);
	return t;
}
int main(){
	int i, j, N;
	node *root;
	N = GI;
	cout<<"enter in-order";
	FOR(i,0,N){
		cin >> j;
		in.pb(j);
	}
	cout<<"enter pre-order";
	FOR(i,0,N){
		cin >> j;
		pre.pb(j);
	}
	root = make_tree(in);
	cout<<endl;
	do_inorder(root);
}
node *make_node(int x){
	node *t;
	t = new node;
	t->info  = x;
	t->left  = NULL;
	t->right = NULL;
	return t;
}
void do_inorder(node *t){
	if(t){
		do_inorder(t->left);
		cout<<t->info<<" -> ";
		do_inorder(t->right);
	}
}
*/