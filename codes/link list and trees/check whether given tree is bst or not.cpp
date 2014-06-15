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
class node{public: int info; node *left, *right;};
/**
Narrowing down the interval for
each of the Nodes
http://leetcode.com/2010/09/determine-if-binary-tree-is-binary.html
*/
bool isBst(node *t, int Min, int Max){
    if(t==NULL)
        return true;
    if(t->info > Min && t->info < Max){
        return isBst(t->left,Min,t->info)
               && isBst(t->right,t->info,Max);
    }
    return false;

}
int main(){
    int i, j;
    return 0;
}
