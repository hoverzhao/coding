#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int INF = 1e9;
double ESP = 1e-9;

static int x = []() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("aa.in", "r", stdin);
	freopen("aa.out", "w", stdout);
	return 0;
}();

/* luogu-judger-enable-o2 */
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std; 
const int	N = 1e5 + 10; 
const int E = 20 * N; 
typedef long long 	ll; 
typedef unsigned 	intuit;

int n; int m; int p; 
int v[2 * N]; int x[2 * N]; int ct; 
int al[N]; int pre[N]; int dep[N]; 
int a[N]; bool book[N];
stack <int> s[N]; 
int fa[N]; int T;

struct data /* 主席树强行维护信息 */
{
	int v0; ll v1; ll v2; ll v3; 
	data( int a = 0, ll b = 0, ll c = 0, ll d = 0 )
	{
		v0 = a; v1 = b; v2 = c; v3 = d;
	}


	friend data operator +( data a, data b )
	{
		return(data( a.v0 + b.v0, a.v1 + b.v1, a.v2 + b.v2, a.v3 + b.v3 ) );
	}


	friend data operator -( data a, data b )
	{
		return(data( a.v0 - b.v0, a.v1 - b.v1, a.v2 - b.v2, a.v3 - b.v3 ) );
	}
};

struct answ /* 树上前缀和 */
{
	ll v1; ll v2; answ( ll a = 0, ll b = 0 )
	{
		v1 = a; v2 = b;
	}


	friend answ operator +( answ a, answ b )
	{
		return(answ( a.v1 + b.v1, a.v2 + b.v2 ) );
	}


	friend answ operator -( answ a, answ b )
	{
		return(answ( a.v1 - b.v1, a.v2 - b.v2 ) );
	}
} val[N];

struct per_linetree /* 主席树的板子 */
{
	data		v[E]; int s[E][2]; int root[N]; int ct;
	inline void	modify( int p1, int p2, int l, int r, const int & pos, const data & pl )
	{
		v[p2] = v[p1] + pl; if ( r - l == 1 )
		{
			s[p2][0] = 0; s[p2][1] = 0; return;
		}
		int mid = (l + r) / 2;
		if ( pos <= mid )
		{
			s[p2][1] = s[p1][1]; modify( s[p1][0], s[p2][0] = ++ct, l, mid, pos, pl );
		}else                                                                             { s[p2][0] = s[p1][0]; modify( s[p1][1], s[p2][1] = ++ct, mid, r, pos, pl ); }
	}


	inline data query( int p, int l, int r, int dl, int dr )
	{
		if ( p == 0 || dl == l && dr == r )
		{
			return(v[p]);
		}
		int mid = (l + r) / 2; data ret;
		if ( dl < mid )
			ret = ret + query( s[p][0], l, mid, dl, min( dr, mid ) );
		if ( mid < dr )
			ret = ret + query( s[p][1], mid, r, max( dl, mid ), dr );
		return(ret);
	}


	inline void cmodify( int p1, int p2, int pos, const data & pl )
	{
		modify( root[p1], root[p2] = ++ct, 0, n + 1, pos + 1, pl );
	}


	inline data cquery( int p1, int p2, int l, int r )
	{
		return(query( root[p2], 0, n + 1, l + 1, r + 1 ) - query( root[p1], 0, n + 1, l + 1, r + 1 ) );
	}


	inline void clear()
	{
		ct = 1;
	}
} plt;

struct per_array /* 可持久化数组，还是主席树的板子 */
{
	int		v[E]; int s[E][2]; int root[N]; int ct;
	inline void	modify( int p1, int p2, int l, int r, const int & pos, const int & pl )
	{
		v[p2] = pl; if ( r - l == 1 )
		{
			s[p2][0] = 0; s[p2][1] = 0; return;
		}
		int mid = (l + r) / 2;
		if ( pos <= mid )
		{
			s[p2][1] = s[p1][1]; modify( s[p1][0], s[p2][0] = ++ct, l, mid, pos, pl );
		}else                                                                             { s[p2][0] = s[p1][0]; modify( s[p1][1], s[p2][1] = ++ct, mid, r, pos, pl ); }
	}


	inline int query( int p, int l, int r, int pos )
	{
		if ( p == 0 || r - l == 1 )
		{
			return(v[p]);
		}
		int mid = (l + r) / 2;
		if ( pos <= mid )
		{
			return(query( s[p][0], l, mid, pos ) );
		}else                                               { return(query( s[p][1], mid, r, pos ) ); }
	}


	inline void cmodify( int p1, int p2, const int & pos, const int & pl )
	{
		modify( root[p1], root[p2] = ++ct, 0, n + 1, pos + 1, pl );
	}


	inline int cquery( int p, int pos )
	{
		return(query( root[p], 0, n + 1, pos + 1 ) );
	}


	inline void clear()
	{
		ct = 1;
	}
} pa;
inline void add( int u, int V )
{
	v[++ct] = V; x[ct] = al[u]; al[u] = ct;
}


inline void dfs( int u, int f ) /* dfs建树形主席树，顺手处理出pre和树上前缀和 */
{
	pre[u] = s[a[u]].empty() ? 0 : s[a[u]].top(); s[a[u]].push( u ); int dp = dep[pre[u]];
	plt.cmodify( f, u, dp, data( 1, dep[u], dp, (ll) dp * dep[u] ) );
	pa.cmodify( f, u, a[u], u ); fa[u]	= f;
	val[u] = val[f] + answ( dep[u] - dp, (ll) (dep[u] - dp) * (-2 * dep[u] + 2) - 1 );
	for ( int i = al[u]; i; i = x[i] )
	{
		dep[v[i]] = dep[u] + 1; dfs( v[i], u );
	}
	s[a[u]].pop();
}


inline int query1( int u, int v )
{
	if ( dep[u] > dep[v] )
		swap( u, v );
	int lc = u; int lc1 = v;                  /* 暴力找lca */
	for (; lc1 > p; lc1 = fa[lc1] )
		book[lc1] = true;
	for (; lc > p; lc = fa[lc] )
		if ( book[lc] )
			goto ed1;
	lc = (dep[lc] < dep[lc1]) ? lc : lc1; ed1 :;
	for ( int x = v; x > p; x = fa[x] )
		book[x] = false;
	int ans = plt.cquery( fa[lc], v, -1, dep[lc] - 1 ).v0;                                          /* 提取长链信息 */
	for ( int x = u; x != lc; x = fa[x] )
		if ( dep[pre[x]] < dep[lc] && dep[pa.cquery( v, a[x] )] < dep[lc] )
			ans++;
	                                                                                                /* 暴力插入短链 */
	return(ans);
}


inline ll subquery( int l, int r )                                                                      /* 操作2的序列问题 */
{
	ll L = dep[l]; ll R = dep[r]; 
	data ret = (l != r) ? plt.cquery( l, r, -1, dep[l] ) : data();    /* 无脑考虑贡献即可 */
	return( 
			val[l].v1 * (L + R) + 
			val[l].v2 + 
			ret.v0 * L * (R + 1) - 
			L * ret.v1 - 
			(R + 1) * ret.v2 + 
			ret.v3);
}


inline ll query2( int u, int v )                                                                        /* 操作2 */
{
	if ( dep[u] > dep[v] )
		swap( u, v );
	int lc = u; int lc1 = v;                                                                        /* 还是暴力找lca */
	for (; lc1 > p; lc1 = fa[lc1] )
		book[lc1] = true;
	for (; lc > p; lc = fa[lc] )
		if ( book[lc] )
			goto ed1;
	lc = (dep[lc] < dep[lc1]) ? lc : lc1; ed1 :;
	for ( int x = v; x > p; x = fa[x] )
		book[x] = false;
	ll ret = subquery( lc, v ) + subquery( lc, u ) - subquery( lc, lc );                                                    /* 处理直路径 */
	if ( lc == u )
		return(ret);
	data tr = plt.cquery( lc, v, -1, dep[lc] - 1 );                                                                         /* 弯路径的长链贡献,主席树查一发即可 */
	ret += (dep[u] - dep[lc]) * ( (ll) tr.v0 * (dep[v] + 1) - tr.v1) + (ll) (dep[v] - dep[lc]) * (dep[u] - dep[lc]);        /* 记得加上lca */
	for ( int x = u; x != lc; x = fa[x] )
	{
		if ( dep[pre[x]] >= dep[lc] )
		{
			continue;
		}                                                                                                               /* 如果数不到这个点就跳过 */
		int pr = pa.cquery( v, a[x] );
		if ( dep[pr] < dep[lc] )
		{
			ret += (ll) (dep[v] - dep[lc]) * (dep[u] - dep[x] + 1); continue;
		}                                                                                                               /* 如果一定可以插入成功就直接算贡献 */
		for (; dep[pre[pr]] >= dep[lc]; pr = pre[pr] )
			;
		if ( dep[pr] == dep[lc] )
			continue;                                                                                               /* 跳pre找第一次出现的点 */
		ret += (ll) (dep[pr] - dep[lc] - 1) * (dep[u] - dep[x] + 1);                                                    /* 计算贡献 */
	}
	return(ret);
}


namespace Maker                                                                                                                 /* 生成器代码,直接粘就行了 */
{
	uit SA, SB, SC;
	uit rng61()
	{
		SA ^= SA << 16; SA ^= SA >> 5; SA ^= SA << 1; uit t = SA; SA = SB; SB = SC; SC ^= t ^ SA; return(SC);
	}


	void gen()
	{
		scanf( "%d%d%u%u%u", &n, &p, &SA, &SB, &SC );
		for ( int i = 2; i <= p; i++ )
			add( i - 1, i );
		for ( int i = p + 1; i <= n; i++ )
			add( rng61() % (i - 1) + 1, i );
		for ( int i = 1; i <= n; i++ )
			a[i] = rng61() % n + 1;
	}
}
inline void solve()
{
	Maker::gen(); scanf( "%d", &m ); dep[1] = 1; dfs( 1, 0 );
	for ( int i = 1, t, l, r; i <= m; i++ )
	{
		scanf( "%d%d%d", &t, &l, &r ); printf( "%lld\n", (t == 1) ? query1( l, r ) : query2( l, r ) );
	}
}


inline void clear()
{
	plt.clear(); pa.clear(); for ( int i = 1; i <= n; i++ )
		al[i] = 0;
	ct = 0;
}


int main()
{
	scanf( "%d", &T ); for ( int z = 1; z <= T; z++ )
	{
		solve(); clear();
	}
	return(0);
}                                                                          /* 拜拜程序~ */
