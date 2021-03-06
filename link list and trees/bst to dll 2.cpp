//============================================================================
// Author       : Siddharth Maloo
// University   : IIIT A
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
#include <bitset>
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
class node {
public:
	int info;
	node *left;
	node *right;
};
node *root;
void Insert(node**,int);
void pre_order(node*);
node *make_node(int);
void display_list(node*);

node *previous;
void do_left_pointer(node *t){
	if(t){
		do_left_pointer(t->left);
		t->left = previous;
		previous = t;
		do_left_pointer(t->right);
	}
}
node *do_right_pointer(node *t){
	node *temp = NULL;
	while(t && t->right)
		t= t->right;
	while(t && t->left){
		temp = t;
		t = t->left;
		t->right = temp;
	}
	return t;
}
node *BST_to_DLL(node *t){
	previous = NULL;
	do_left_pointer(t);
	return do_right_pointer(t);
}

int main(){
	int i, j;
	while(true){
		cin >> i;
		switch(i){
		case 1:
			cin >> j;
			Insert(&root,j);
			break;
		case 2:
			cout<<endl;
			pre_order(root);
			cout<<endl;
			break;
		case 3:
			root = BST_to_DLL(root);
			display_list(root);
			break;
		case 4:
			root=NULL;
			break;
		default:
			break;
		};
	}
	return EXIT_SUCCESS;
}

void display_list(node *t){
	while(1){
		cout<<t->info<<"-->";
		if(t->right)
			t = t->right;
		else
			break;
	}
	cout<<endl<<"\t########\n";
	while(1){
		cout<<t->info<<"-->";
		if(t->left)
			t=t->left;
		else
			break;
	}
	cout<<endl;
}

void Insert(node**t,int x){
	if(*t==NULL)
		*t = make_node(x);
	else{
		if(x > (*t)->info)
			Insert(&(*t)->right,x);
		else
			Insert(&(*t)->left,x);
	}
}

node *make_node(int x){
	node *t = new node;
	t->info = x;
	t->left = NULL;
	t->right = NULL;
	return t;
}

void pre_order(node *t){
	if(t){
		pre_order(t->left);
		cout<<t->info<<"-->";
		pre_order(t->right);
	}
}
