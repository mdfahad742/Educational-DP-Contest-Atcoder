// STANDARD LIS O(N*LogN) -- using segment tree


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



const ll sz = 2e5 + 2;
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

ll tree[4 * sz + 5];
map<ll, ll> mpx;

void build(ll l, ll r, ll Tidx) {
    if (l == r) {
        tree[Tidx] = mpx[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(l, mid, Tidx * 2);
    build(mid + 1, r, Tidx * 2 + 1);
    tree[Tidx] = max(tree[Tidx * 2], tree[Tidx * 2 + 1]);
}

void update(ll l, ll r, ll idx1, ll Tidx, ll val) {
    if (l == r) {
        tree[Tidx] = val;
        return;
    }

    ll mid = (l + r) / 2;
    if (idx1 <= mid)
        update(l, mid, idx1, Tidx * 2, val);
    else
        update(mid + 1, r, idx1, Tidx * 2 + 1, val);

    tree[Tidx] = max(tree[Tidx * 2], tree[Tidx * 2 + 1]);

}

ll query(ll l, ll r, ll Tidx, ll st, ll en) {
    if (r < st || l > en)return 0; // NO OVERLAP

    if (l >= st && r <= en) { // COMPLETE OVERLAP

        return tree[Tidx];
    }

    ll mid = (l + r) / 2;

    ll ans1 = query(l, mid, Tidx * 2, st, en);
    ll ans2 = query(mid + 1, r, Tidx * 2 + 1, st, en);

    return max(ans1, ans2);



}





void solver() {
    ll n; cin >> n;
    VLL a(n);
    forn(i, n)cin >> a[i].ff;
    forn(i, n) {cin >> a[i].ss; mpx[a[i].ff] = a[i].ss;}

    // build(1, n, 1);
    // update(1, n, 1, 1, 75);
    // cout << query(1, n, 1, 1, 1) << endl;


    forn1(i, 4 * n + 5) tree[i] = 0; //cout << tree[i] << " "; cout << endl;
    ll ans = 0;
    forn(i, n) {
        ll xx = query(1, n, 1, 1, a[i].ff);
        update(1, n, a[i].ff, 1, xx + a[i].ss);
        ans = max(ans, xx + a[i].ss);
    }
    cout << ans << endl;

    // tracen(dp, n);

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
