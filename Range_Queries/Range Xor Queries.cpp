// This code is given by - bentonite_02
 
#pragma GCC optimize("O3,unroll-loops")
 
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <deque>
#include <climits>
#include <functional>
#include <climits>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
 
#define ll long long int
#define ull unsigned long long
#define ld long double
#define god 1000000007
#define god1 998244353
#define INF 1e18
#define pi 3.141592653589793238462
#define siz(x) ((ll)(x).size())
#define all(x) (x).begin(), (x).end()
 
#define gcd(a, b) __gcd((a), (b))
#define F first
#define S second
#define endl '\n'
 
#define vec vector<int>
#define ap map<ll, ll>
#define sap map<char, ll>
#define uap unordered_map<ll, ll>
#define suap unordered_map<string, ll>
 
#define input(v)      \
    for (auto &x : v) \
    {                 \
        cin >> x;     \
    }
#define repn(i, n) for (ll i = 0; i < n; i++)        // Loop from 1 to n
#define rep(i, a, b) for (ll i = a; i < b; i++)      // Loop in a given range
#define rep_rev(i, a, b) for (ll i = a; i >= b; i--) // Reverse for loop
#define access(v) for (auto &x : v)                  // Access elements of container
#define print(a) cout << a << endl;
#define display(v)        \
    for (auto x : v)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << endl;
#define pr pair<ll, ll>
#define debug(x) cout << #x << " " << x << endl;
#define sort(v) sort(v.begin(), v.end())                         // Sort a container
#define reverse_sort(v) sort(v.begin(), v.end(), greater<int>()) // Reverse container in sorted order
#define sumv(v, a)   \
    for (auto x : v) \
    {                \
        a += x;      \
    }
#define maxim(v) *max_element(v.begin(), v.end())
#define minim(v) *min_element(v.begin(), v.end())
#define count(v, n) count(v.begin(), v.end())  // Count no of elements of a container
#define reverse(v) reverse(v.begin(), v.end()) // Reverse a container
#define ax(a, b) max(a, b)
#define in(a, b) min(a, b)
 
#define lc(a, b) a / gcd(a, b) * b
#define square(x) x *x
#define cube(x) x *x *x
#define setbits(x) __builtin_popcount(x) // Count Set Bits
 
using namespace std;
 
vec seg(8e5 + 7);
 
void build(ll node, ll st, ll end, vec &v)
{
    if (st == end)
    {
        seg[node] = v[st];
        return;
    }
    ll mid = (st + end) / 2;
    build(2 * node, st, mid, v);
    build(2 * node + 1, mid + 1, end, v);
    seg[node] = seg[2 * node] ^ seg[2 * node + 1];
}
 
void update(ll node, ll st, ll end, vec &v, ll i, ll val)
{
    if (st == end)
    {
        v[st] = val;
        seg[node] = val;
        return;
    }
    ll mid = (st + end) / 2;
    if (i <= mid)
    {
        update(2 * node, st, mid, v, i, val);
    }
    else
    {
        update(2 * node + 1, mid + 1, end, v, i, val);
    }
    seg[node] = min(seg[2 * node], seg[2 * node + 1]);
}
ll query(ll node, ll st, ll end, vec &v, ll p, ll q)
{
    if (st > q || p > end)
    {
        return 0;
    }
    if (p <= st && q >= end)
    {
        return seg[node];
    }
    ll mid = (st + end) / 2;
    ll q1 = query(2 * node, st, mid, v, p, q);
    ll q2 = query(2 * node + 1, 1 + mid, end, v, p, q);
    return q1 ^ q2;
}
 
ll binary_expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
 
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
 
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
 
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
 
ll modFact(ll n, ll p)
{
    if (n >= p)
        return 0;
    ll result = 1;
    for (ll i = 1; i <= n; i++)
    {
        result = (result * i) % p;
    }
    return result;
}
 
bool valid(ll x, ll y, ll n, ll m) { return (x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1); }
 
ll dist(ll i, ll j, ll sx, ll sy)
{
    return abs(sx - i) + abs(sy - j);
}
 
// Code begins here-->
 
void solve()
{
    ll n, a;
    cin >> n >> a;
    vec v(n);
    input(v);
    build(1, 0, n - 1, v);
    while (a--)
    {
        ll p, q;
        cin >> p >> q;
        cout << query(1, 0, n - 1, v, p - 1, q - 1) << endl;
    }
}
 
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
    // g++ filename.cpp -o a.exe
    // .\a.exe
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll _ = 1, p = 1;
    // cin >> _;
    while (_--)
    {
        // cout << "Case #" << p << ": "; Used for Google and Facebook competitions only
        solve();
        p++;
    }
 
    return 0;
}
