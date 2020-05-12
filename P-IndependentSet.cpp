// VERY STANDARD DP ON TREES QUESTION.



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
VL adj[sz];
VLL dp(sz);

void dfs(ll v, ll p) {
    if (adj[v].size() == 1 && adj[v][0] == p) {
        dp[v].ff = 1;
        dp[v].ss = 1;
        return;
    }
    for (ll w : adj[v]) {
        if (w != p) {
            dfs(w, v);
            dp[v].ss *= (dp[w].ff);
            dp[v].ss %= mod;
            dp[v].ff *= (dp[w].ff + dp[w].ss);
            dp[v].ff %= mod;

        }
    }
}

void solver() {
    ll n; cin >> n;

    forn(i, n - 1) {
        ll x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }


    forn1(i, n + 1) {
        dp[i].ff = 1;
        dp[i].ss = 1;
    }


    dfs(1, -1);

    // forn1(i, n + 1) {
    //     cout << dp[i].ff << " " << dp[i].ss << endl;
    // }


    cout << (dp[1].ff + dp[1].ss) % mod << endl;

}


int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    IOS;
    ll T = 1; // cin >> T;
    forn1(i, T + 1) {
        clock_t z = clock();
        solver();
        debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
