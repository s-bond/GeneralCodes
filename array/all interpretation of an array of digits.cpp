//============================================================================
// Author      : Bond
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
int N, M, K;
int a[100];
vc v;
vector< vc > ans;
void _do(int x){

	if(x>N) {
		ans.pb(v);
	}
	else{
		if(a[x]>2){
			v.pb('a'+(a[x]-1));
			_do(x+1);
			v.pop_back();
		}
		else{
			v.pb('a'+(a[x]-1));
			_do(x+1);
			v.pop_back();
			if(((a[x+1]<7 && a[x] == 2) || (a[x]==1)) && x+1<N){
				int i = a[x]*10 + a[x+1];
				v.pb('a'+(i-1));
				_do(x+2);
				v.pop_back();
			}
		}
	}
}
int main(){
	int i, j;
	cin >> N;
	FOR(i,0,N)
		cin >> a[i];
	_do(0);
	FORV(i,ans){
		FORV(j,ans[i]){
			if(j!=ans[i].size()-1)
				cout<<ans[i][j];
		}
		cout<<endl;
	}
}