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
int a[1000];
// First Increasing and then Decreasing
// Find pivot element
// 1 2 3 4 5 4 3 2 1
//		   ^
//         |
//      pivot element
// binary search type algorithm
// note that pivot element is greater than both of the neighbors
int search(int low, int high){
	if(low>high)
		return -1;
	int mid = (low+high)>>1;
	//cout<<mid<<endl;
	if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
		return mid;
	else if(a[mid]>=a[mid-1])
		search(mid+1,high);
	else if(a[mid]<=a[mid-1])
		search(low,mid);
}
int main(){
	int N, i, k;
	cin >> N;
	FOR(i,0,N) cin >> a[i];
	k = search(0,N);
	cout<<" a [- "<<k<<" -] = "<< a[ k ]<<endl;
	return EXIT_SUCCESS;
}
