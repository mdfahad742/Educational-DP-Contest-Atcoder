// fahadmd16(IIEST Shibpur)
#include<bits/stdc++.h>
using namespace std;

#define ll                                      long long
#define pb                                      push_back
#define pf                                      push_front
#define eb                                      emplace_back
#define mp                                      make_pair
#define ff                                      first
#define ss                                      second
#define db                                      double
#define pll                                     pair<ll, ll>
#define ALL(a)                                  (a).begin(),(a).end()
#define endl                                    "\n"

#define forn(i, n) for (ll i = 0; i < n; i++)
#define forn1(i, n) for (ll i = 1; i < n; i++)
#define ford(i, n) for (ll i = n - 1; i >= 0; i--)
#define ford1(i, n) for (ll i = n - 1; i >= 1; i--)
#define forab(i, a, b) for(ll i = a; i < b; i++)
#define forabd(i, a, b) for(ll i = a; i >= b; i--)
#define eps 1e-10

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)


#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define trace1(x)                cout<<#x<<": "<<x<<endl
#define trace2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define tracen( x , n ){ cout<<(#x)<<":";for(int i=0;i<n;i++)cout<<(#x)<<"["<<i<<"]:"<< x[i] << "    "; cout<<endl;}
#define tracenm( x , n , m ){ cout<<(#x)<<endl;for(int i=0;i<n;i++){ cout<<"Row #"<<i<<":"; for(int j=0;j<m;j++) cout<<x[i][j]<<"     "; cout << endl;}}
#define trace(v){ cout<<#v<<": ";for(auto it=v.begin();it!=v.end();it++)cout<<*it<<" ";cout<<endl;}
using namespace std;



const ll sz = 1e5 + 2;
const ll mod = 1e9 + 7;
const db PI = acos(-1);



typedef vector<ll> VL;
typedef vector<pll > VLL;
typedef vector<vector<ll> > VVL;



ll power(ll n, ll k, ll m) {
    ll ans = 1;
    while (k) {
        if (k & 1)ans = (ans * n) % m;
        k /= 2;
        n = (n * n) % m;
    }
    return ans;
}

// Topological order

stack<ll> order;
void dfs(ll v, VL adj[], vector<bool>& vis) {
    vis[v] = 1;
    for (auto w : adj[v]) {
        if (!vis[w]) {
            dfs(w, adj, vis);
        }
    }
    order.push(v);
}

void solver() {
    ll n, m; cin >> n >> m;
    VL adj[n + 1];
    forn(i, m) {
        ll v, w; cin >> v >> w;
        adj[v].pb(w);
    }
    forn1(i, n + 1) {
        if (adj[i].size())
            adj[0].pb(i);
    }
    vector<bool> vis(n + 1, 0);
    dfs(0, adj, vis);

    VL disTo(n + 1, INT_MAX);
    disTo[0] = 0;
    
    // iterated through the topological order
    
    while (!order.empty()) {
        ll v = order.top();
        order.pop();
        for (auto w : adj[v]) {
            if (disTo[w] > disTo[v] - 1) {
                disTo[w] = disTo[v] - 1;
            }
        }
    }
    ll ans = 0;
    forn1(i, n + 1)ans = max(ans, -disTo[i]);
    cout << ans - 1 << endl;
}


int main() {

    IOS;
    ll T = 1; //cin >> T;
    forn1(i, T + 1) {
        clock_t z = clock();
        solver();
        debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
