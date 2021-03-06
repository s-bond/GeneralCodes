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
vector < vs > ans;
int N, cnt;
string dictionary[100];
string s;
bool contain(string);
void _do(int x, vs v){
	cnt++;
	if(x >= s.length()){
		ans.pb(v);
	}
	else{
		int i, j;
		string mid("");
		FOR(i,1,s.length()-x+1){
			mid = s.substr(x,i);
			if(contain(mid)){
				v.pb(mid);
				_do(x+i,v);
				v.pop_back();
			}
		}
	}
}
int main(){
	int i, j;
	cout<<"Enter number of words in dictionary # ";
	cin >> N;
	cout<<"Enter Words\n";
	FOR(i,0,N)
		cin >> dictionary[i];
	cin >> s;
	vs d;
	_do(0,d);
	cout<<endl;
	cout<<"\t#################################\n";
	cout<<"Total sentences matched : "<<ans.size()<<endl;
	FORV(i,ans){
		FORV(j,ans[i]){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl<<endl;
	}
	return EXIT_SUCCESS;
}
bool contain(string s){
	int i;
	FOR(i,0,N)
		if(dictionary[i].compare(s)==0)
			return true;
	return false;
}