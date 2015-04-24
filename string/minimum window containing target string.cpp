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
int _start, _end;
int find_diff(char *s, char *t){
	int ans = INT_MAX;
	int target[256];
	int current[256];
	Clear(target);Clear(current);
	int i, _count, x, y, target_length, start, end;
	start = end = _count = 0;
	i = 0;
	while(t[i]!='\0')
		target[t[i++]]++;
	target_length = i;
	i = 0;
	while(s[i]!='\0'){
		current[s[i]]++;
		x = current[s[i]];
		y = target[s[i]];
		end = i;
		if(x<=y){
			_count++;
		}
		if(_count==target_length){
			while(current[s[start]]>target[s[start]]){
				current[s[start]]--;
				start++;
				_start = start;
				_end = end;
			}
			ans = min(ans,end-start+1);
		}
		i++;
	}
	return ans;
}
int main(){
	int i;
	char s[100], t[100];
	scanf("%s%s",&s,&t);
	cout << find_diff(s,t)<<endl;
	FOR(i,_start,_end+1)
		cout<<s[i];


}
