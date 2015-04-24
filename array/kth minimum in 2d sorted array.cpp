//============================================================================
// Author       : Bond
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
	int num;
	int row;
	int column;
	bool operator()(const node &a, const node &b){
		return a.num > b.num;
	}
};
int a[1000][1000];
int R, C;
int _do(int x){
	int _count = 0;
	priority_queue<node,vector<node>,node> q;
	node temp;
	int i;
	FOR(i,0,R){
		temp.num    = a[i][0];
		temp.column = 0;
		temp.row	= i;
		q.push(temp);
	}
	while(_count<x){
		temp = q.top();
		q.pop();
		_count++;
		if(_count <x && temp.column+1<C){
			temp.column++;
			temp.num = a[temp.row][temp.column];
			q.push(temp);
		}
		else if(_count<x && temp.column+1==C){
			;
		}
		else
			break;
	}
	return temp.num;
}
int main(){
	int i, j, k;
	cin >> R >> C;
	FOR(i,0,R)
		FOR(j,0,C)
			cin >> a[i][j];
	while(1){
		cin >> k;
		cout<<_do(k)<<endl;
	}
}
