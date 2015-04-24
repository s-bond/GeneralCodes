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
class node {
public:
	int start;
	int end;
	int cost;
};
bool sid(const node &a,const node &b){
		if(b.end==a.end)
			return a.end<b.end;
		else
			return a.start<b.start;
}
node a[10000];
int dp[10000];
// basic idea is either leave i'th node or take it
// it left, i-1'th maximum
// if taken, last non-intersecting taken
int _get(int x){
	int i, j = 0;
	FOR(i,0,x){
		if(a[i].end<=a[x].start)
			if(dp[j] <= dp[i])
				j = i;
	}
	return j;
}
int main(){
	int i, j, k;
	cin >> N;
	FOR(i,1,N+1){
		cin >> a[i].start >> a[i].end >> a[i].cost;
	}
	sort(a+1,a+N+1,sid);
	FOR(i,1,N+1){
		dp[i] = max(dp[i-1], dp[_get(i)]+a[i].cost);
	}

	cout<<dp[N]<<endl;

	return EXIT_SUCCESS;
}