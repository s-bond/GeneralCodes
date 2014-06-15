/* @author
 * bond, s_bond, sidhs
*/
#include <iostream>
#include <vector>
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
class node {public: int info; node *next;};
node *start;
void add(int x); // implemented in STACK ordering (LifO)
node *make_node(int x);
void display();
void reverse_link(){
	node *p, *q, *r;
	p = q = r = NULL;
	q = r = start;
	while(q){
		//cout<<q->info<<" ";
		r = r->next;
		q->next = p;
		p = q;
		q = r;
		}
	start = p;
	}
int main () {
	int i, j, k, t;
	start = NULL;
	while(1){
		cin >> k;
		switch(k)
		{
			case 1:
			cin >> i;
			add(i);
				break;
			case 2:
			reverse_link();
			display();
			cout<<endl;			
				break;
			default:
				exit(0);
				break;
		}
		
		}
	
	return EXIT_SUCCESS;
}
node *make_node(int x){
	node *t;
	t = new node;
	t->info = x;
	t->next = NULL;
	return t;
	}
void add(int x){
	if(start == NULL)
		start = make_node(x);
	else{
		node *t = make_node(x);
		t->next = start;
		start = t;
		}		
	}
void display(){
	node *t = start;
	while(t){
		cout<<t->info<<" -> ";
		t=t->next;
		}
	}