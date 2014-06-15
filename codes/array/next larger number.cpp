//============================================================================
// Author      : Siddharth Maloo
// University  : IIIT Allahabad
//============================================================================
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <bitset>
#include <set>
#include <cmath>
#include <functional>
#include <ctime>
#include <cstring>
#include <cstdio>
#include <assert.h>
#include <limits.h>
#include <numeric>
/////////////////
#define FOR(i,a,b) for((i)=(a);(i)<(b);i++)
#define FORR(i,b,a) for((i)=(b);(i)>=(a);(i)--)
#define FORV(i,v) for((i)=0;(i)<v.size();i++)
#define FORI(it,v) for( it=v.begin();it!=v.end();it++)
#define All(v) v.begin(),v.end()
#define BS(v,val) (lower_bound(All(v),val)-v.begin())
#define pb(a) push_back((a))
#define Clear(a) memset((a),0,sizeof(a))
#define SV(v) sort((v).begin(),(v).end())
#define SA(a,n) sort((a),(a)+(n))
#define mp make_pair
#define IT ::iterator
#define INFINITY 1<<30
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef stringstream SS;
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
/////////////////////////////////
int N, M;
int a[100010];
void _do( ){
    int i, prev;
    vi v;
    v.pb(a[0]);
    FOR(i,1,N){
        if(v.size()){
        prev = v.back();
        while(prev < a[i]){
            cout << prev <<" -> " << a[i] << endl;
            v.pop_back();
            if(!v.size())
                break;
            prev = v.back();
        }
        if(prev > a[i])
            v.pb(prev);
        }
        v.pb(a[i]);
    }
    FORV(i,v){
        cout << v[i] <<" -> " << -1 << endl;
    }
}
int main(){
    int i, j = 10;
    while(j--){
        cin >> N;
        FOR(i,0,N) cin >> a[i];
        _do();
    }
    return 0;
}
