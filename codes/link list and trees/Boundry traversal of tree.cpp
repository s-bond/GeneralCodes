//============================================================================
// Author      : Bond
//============================================================================
#include <iostream>
#include <vector>
#include <conio.h>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <bitset>
#include <set>
#include <cmath>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <cstdio>
#include <assert.h>
#include <functional>
#include <sstream>

/////////////////
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
/////////////////

int N, M, K;
class node {public:int info; node*left,*right;};
node *root, *temp;
node *make_node(int x);
void Ins(node *t, int x);
void in_order(node *t);

void traverseLeft(node *t){
	if(t){
		if(t->left){
			cout<<t->info<<" -> ";
			traverseLeft(t->left);
		}
		else if(t->right){
			cout<<t->info<<" -> ";
			traverseLeft(t->right);
		}		
	}
}

void traverseRight(node *t){
	if(t){
		if(t->right){
			traverseRight(t->right);
			cout<<t->info<<" -> ";
		}
		else if(t->left){
			traverseRight(t->left);
			cout<<t->info<<" -> ";
		}
	}
}

void leaf(node *t){
	if(t){
		leaf(t->left);
		if(t->left==NULL && t->right==NULL)
			cout<<t->info<<" -> ";
		leaf(t->right);
	}
}

void BoundryTraverse(node *t){
	if(t){
		cout<<t->info<<" -> ";
		traverseLeft(t->left);
		leaf(t->left);
		leaf(t->right);
		traverseRight(t->right);
	}
}

int main () {
	int  j = 0, k, t;
	root = temp = NULL;
	while(1){
		cin >> t;
		switch(t){
		case 1://insert
			if(root==NULL){
				root = new node;
				cin >> k;
				root = make_node(k);
				}
			else{
				temp = root;
				cin >> k;
				Ins(temp,k);
				}
			j++;
			break;
		case 2://traverse
			cout<<endl;
			temp = root;
			BoundryTraverse(temp);
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
void Ins(node *t, int x){
	if(x>t->info && t->right)
		Ins(t->right,x);
	else if(x>t->info)
		t->right = make_node(x);
	if(x<t->info && t->left)
		Ins(t->left,x);
	else if(x<t->info)
		t->left = make_node(x);
	}
void in_order(node *t){
	if(t){
		in_order(t->left);
		cout<<t->info<<" -> ";
		in_order(t->right);
		}
	}
