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
typedef priority_queue <int> PQ;
int a[1000], b[1000];
#define debug 0
int _do(int a_start, int a_end, int b_start, int b_end){
	int mid_a, mid_b, i;
	int median_a, median_b;
	mid_a = a_start + (a_end-a_start)/2;
	mid_b = b_start + (b_end-b_start)/2;
#if debug
	FOR(i,a_start,a_end+1)
		cout<<a[i]<<" ";
	cout<<"\t\t";
	FOR(i,b_start,b_end+1)
		cout<<b[i]<<" ";
	cout<<endl;
	cout<<endl;
#endif
	if(a_end-a_start+1==2 && b_end-b_start+1==2){
		return ((min(a[a_end],b[b_end]) + max(a[a_start],b[b_start]))>>1);
	}
	int N = a_end - a_start + 1 ;
	N = (N-1)%2;
	// TAKE CARE OF EVEN LENGTH MEDIAN !!!!!!!
	median_a = a[mid_a] + a[mid_a+N]; median_a/=2;
	median_b = b[mid_b] + b[mid_b+N]; median_b/=2;
	if(median_a == median_b)
		return median_a;
	else if(median_a > median_b)
		return _do(a_start,mid_a+N,mid_b,b_end);
	else
		return _do(mid_a,a_end,b_start,mid_b+N);

	}
int main(){
	int i, j, k;
	cin >> k;
	FOR(i,0,k)
		cin >> a[i];
	FOR(j,0,k)
		cin >> b[j];
	cout << _do(0,k-1,0,k-1)<<endl;
}
