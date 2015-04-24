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
char a[1000010], b[1000010] ;
bool cmp(char *base, char *a){
	/*
	 * return true if base > a , else returns false
	 * */
	int i, j;
	int len = strlen(base);
	i = j = -1;
	while(base[++i]==a[++j] && i<len);
	if(i==len)
		return false;
	if(base[i]<=a[j])
		return false;
	return true;
}
bool is_palin(char *a){
	int i , j;
	int len = strlen(a);
	i = 0;
	j = (len-1)>>1;
	while(i<=j){
		if(a[i]!=a[len-1-i])
			return false;
		i ++;
	}
	return true;
}
void add_one(char *a){
	/*
	 * this method adds one to the middle element
	 * */
	int i, len, mid, carry;
	len = strlen(a);
	int MID = (len-1)>>1;
	mid = a[MID]-48;
	mid ++;
	carry = mid/10;
	mid = mid%10;
	a[MID] = mid + 48;
	i = MID-1;
	while(carry){
		mid = a[i]-48; mid++;
		carry = mid/10;
		mid = mid%10;
		a[i] = mid + 48;
		i--;
	}
}
void mirror_cpy(char *a){

	/*
	 * copy half elements from front to the end
	 * 12 34 -> 12 21
	 *    ||       ||
	 * */
	int i, j;
	int len = strlen(a);
	i = 0;
	j = (len-1)>>1;
	while(i<=j){
		a[len-1-i] = a[i];
		i ++;
	}
}
bool nine(char *a){
	int i, j;
	int len = strlen(a);
	i = j = 0;
	while(i<len)
		if(a[i++]=='9')
			j++;
	if(j==len)
		return true;
	return false;
}
void print_nine(int x){
	int i;
	printf("1");
	x--;
	FOR(i,0,x)
		printf("0");
	printf("1\n");
}
void _do(){
	strcpy(b,a);
	int len = strlen(a);
	if(len==1 && a[0]!='9'){
		a[0]++;
		printf("%s\n",a);
		return;
	}
	mirror_cpy(b);
	if(nine(b)){
		print_nine(len);
		return;
	}
	if(!cmp(b,a)){
		add_one(a);
		mirror_cpy(a);
		printf("%s\n",a);
		return;
	}
	printf("%s\n",b);
}
int main(){
	int t;
	t = GI;
	while(t--){
		scanf("%s",&a);
		_do();
		fflush(stdout);
	}
	return EXIT_SUCCESS;
}
