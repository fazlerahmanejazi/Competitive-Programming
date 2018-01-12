#include <bits/stdc++.h>


#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define fastIO ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define inf INT_MAX
#define minf INT_MIN
#define clr(ar) memset(ar, 0, sizeof(ar));

typedef long long int lli;

using namespace std;

ofstream outfile;
ifstream infile;

int n, m, first[400010], last[400010], color[400010], ttime;
lli tree[4000010], lazy[4000010], newc[1000010];
vector <vector <int>> graph;

void etour(int root, int par){
	first[root] = ttime;
	newc[ttime++] = 1ll<<color[root];
	for(auto it:graph[root]){
		if(it == par) continue;
		etour(it, root);
	}
	last[root] = ttime;
	newc[ttime++] = 1ll<<color[root];
}

void build_tree(int node, int start, int end){
	if(start == end){
		tree[node] = newc[start];
		//cout << start << " "<< node << " "<< tree[node] << "\n";
		return ;
	}
	int x1 = node*2, x2 = node*2+1, mid = (start+end)/2;
	build_tree(x1, start, mid);
	build_tree(x2, mid+1, end);

	tree[node] = tree[x1] | tree[x2];
}

void update(int node, int start, int end, int l, int r, int col){
	int x1 = node*2, x2 = node*2+1, mid = (start+end)/2;
	if(lazy[node]){
		tree[node] = 1ll<<lazy[node];
		if(start != end)
			lazy[x2] = lazy[x1] = lazy[node];
		lazy[node] = 0;
	}
	if(start > r || end < l)
		return;

	if(start >= l && end <= r){
		//cout << "\n"<< start << " "<< end << "\n";
		tree[node] = 1ll<<col;
		if(start != end)
			lazy[x1] = lazy[x2] = col;
		return;
	}
	update(x1, start, mid, l, r, col);
	update(x2, mid+1, end, l, r, col);
	tree[node] = tree[x1] | tree[x2];
}

lli query(int node, int start, int end, int l, int r){
	int x1 = node*2, x2 = node*2+1, mid = (start+end)/2;
	if(lazy[node]){
		tree[node] = 1ll<<lazy[node];
		if(start != end)
			lazy[x2] = lazy[x1] = lazy[node];
		lazy[node] = 0;
		///cout << start << "s"<< end << " "<< tree[node] << '\n';
	}
	if(start > r || end < l)
		return 0ll;
	if(start >= l && end <= r)
		return tree[node];

	return query(x1, start, mid, l, r) | query(x2, mid+1, end, l, r);
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int i, j, type, c, t, u, v;
	cin >> n >> m;
	graph.resize(n+1);
	for(i= 1; i <= n; ++i){
		cin >> color[i];
	}
	for(i =1 ; i < n; ++i){
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	ttime = 1;
	etour(1, -1);

	build_tree(1, 1, n<<1);
	for(i = 1; i <= 4000000; ++i)
		lazy[i] = 0;
	for(i = 1; i <= m; ++i){
		cin >> type;
		if(type == 1){
			cin >> u >> c;
			update(1, 1, n<<1, first[u], last[u], c);
		}else{
			cin >> u;
			lli ans = query(1, 1, n<<1, first[u], last[u]);
			bitset <64> a = ans;
			cout <<  __builtin_popcountll(ans) << "\n";
		}
	}
}
