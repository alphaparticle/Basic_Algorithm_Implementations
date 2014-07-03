#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <cassert>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <complex>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

inline void inpint( int &n ) {
  n=0; register int ch = getchar_unlocked(); int sign = 1;
  while(ch < '0' || ch > '9') { if(ch == '-') sign=-1; ch = getchar_unlocked(); }
  while(ch >= '0' && ch <= '9') { n = (n << 3) + (n << 1) + ch - '0', ch = getchar_unlocked(); }
  n = n * sign;
}

inline string itostr(int a){
    char x[100];
    sprintf(x,"%d",a); string s = x;
    return s;
}

inline int strtoi(string a){
    char x[100]; int res;
    strcpy(x,a.c_str()); sscanf(x,"%d",&res);
    return res;
}

const LL LLINF = 9223372036854775807LL;
const int INF = 2147483647;
const int MOD = 1000000007;
const double eps = 1e-7;
const double PI = acos(-1.0);

#define FORIT(a,b) for (__typeof((b).begin()) (a)=(b).begin(); (a)!=(b).end(); (a)++)
#define FOR(a,b,c) for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c) for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c) for (int (a)=(b); (a)>=(c); (a)--)
#define FORU(a,b,c) for (int (a)=(b); (a)<(c); (a)++)
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define REPD(i,n) FORD(i,n,1)

#define ABS(x)   ((x)<0?-(x):(x))
#define SQR(x) 	 ((x)*(x))
#define CUBE(x)  ((x)*(x)*(x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define SYNC ios_base::sync_with_stdio(0);
#define SIZE(a) (int)(a.size())
#define MIN(a,b) (a) = min((a),(b))
#define MAX(a,b) (a) = max((a),(b))
#define input(in) freopen(in,"r",stdin)
#define output(out) freopen(out,"w",stdout)
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define QUIT return 0
#define EXIT return 0
#define SIZE(a) (int)(a.size())
#define GETINT(x) scanf("%d",&x)
#define SCAN(n,arr) {GETINT(n); REPN(i,n) GETINT(arr[i]);}

#define FIN(x) freopen(x,"r",stdin)
#define FOUT(x) freopen(x,"w",stdout)
#define FCLOSE {fclose(stdin); fclose(stdout);}

#define fi first
#define se second
#define pb push_back
#define mp make_pair

int dr[] = {1,0,-1,0,-1,1,1,-1};
int dc[] = {0,-1,0,1,1,1,-1,-1};
int n, q, segtree[400005]; //stores how many coins are heads up
bool lazy[400005];

void update(int node, int left, int right, int lquery, int rquery){

	if(lazy[node]){
		segtree[node] = right - left + 1 - segtree[node];

		if(left != right){
			lazy[node*2] = !lazy[node*2];
			lazy[node*2+1] = !lazy[node*2+1];
		}

		lazy[node] = false;
	}

	if(left > rquery || right < lquery) return;

	if(left >= lquery && right <= rquery){
		segtree[node] = right - left + 1 - segtree[node];

		if(left != right){
			lazy[node*2] = !lazy[node*2];
			lazy[node*2+1] = !lazy[node*2+1];
		}

		return;
	}

	int mid = (left + right) / 2;
	update(node * 2, left, mid, lquery, rquery);
	update(node * 2 + 1, mid + 1, right, lquery, rquery);

	segtree[node] = segtree[node*2] + segtree[node*2+1];

}

int query(int node, int left, int right, int lquery, int rquery){

	if(lazy[node]){
		segtree[node] = right - left + 1 - segtree[node];

		if(left != right){
			lazy[node*2] = !lazy[node*2];
			lazy[node*2+1] = !lazy[node*2+1];
		}

		lazy[node] = !lazy[node];
	}

	if(left >= lquery && right <= rquery) return segtree[node];
	if(left > rquery || right < lquery) return 0;

	int mid = (left + right) / 2;
	int l = query(node * 2, left, mid, lquery, rquery);
	int r = query(node * 2 + 1, mid + 1, right, lquery, rquery);
	return l + r;
}

int main(){
	inpint(n);inpint(q);
	REPN(i,q){
		int c, a, b;
		inpint(c);inpint(a);inpint(b);
		a++; b++;
		if(!c){
			//update
			update(1,1,n,a,b);
			//puts("updated.");
		}
		else{
			//query
			printf("%d\n",query(1,1,n,a,b));
		}
	}

	return 0;
}
