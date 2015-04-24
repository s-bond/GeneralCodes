/* @author
 * bond, s_bond, sidhs
 * finding the k'th largest/smallest element
 * using the quick sort technique 
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
int a[100001];
int Part(int L, int R){
	int i = L-1;
	int j;
	FOR(j,L,R){
		if(a[j]<=a[R]){
			i++;
			swap(a[i],a[j]);
			}
		}
	i++;
	swap(a[i],a[R]);
	return i;
	}
// Finding K'th largest element !!!
void _do(int L, int R, int x){
	if(L<R){
		int q = Part(L,R);
		//cout << q <<"  ";
		if(q > x)
			_do(L,q-1,x);
		else if( q < x)
			_do(q+1,R,x);
		else 
			return;
		}
	}
int Part_2(int L, int R){
	int i = L-1;
	int j;
	FOR(j,L,R){
		if(a[j]>=a[R]){
			i++;
			swap(a[i],a[j]);
			}
		}
	i++;
	swap(a[i],a[R]);
	return i;
	}
// Finding K'th largest element !!!
void _do_2(int L, int R, int x){
	if(L<R){
		int q = Part_2(L,R);
		//cout << q <<"  ";
		if(q > x)
			_do(L,q-1,x);
		else if( q < x)
			_do(q+1,R,x);
		else 
			return;
		}
	}
int main () {
	int i, j, k, t;
	N = GI;
	FOR(i,0,N) a[i] = GI;
	K = GI;
	_do(0,N-1,K-1);
	cout<<K<<" th minimum = "<<a[K-1]<<endl;
	_do_2(0,N-1,K-1);
	cout<<K<<" th maximum = "<<a[K-1]<<endl;
	
	return EXIT_SUCCESS;
}