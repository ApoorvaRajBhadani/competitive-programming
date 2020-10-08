#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
#define fo(i, s, e_ex) for (i = s; i < e_ex; i++)
#define Fo(i, k, n) for (i = k; k < n ? i <= n : i >= n; k < n ? i += 1 : i -= 1)
#define endl '\n'
#define MOD 1000000007 //998244353
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define mset(arr, val) memset(arr, val, sizeof(arr))
void swap(ll &a, ll &b)
{
    ll t = a;
    a = b;
    b = t;
}
void solve(ll caseno)
{
    ll i, j, a, b, n, m;
    cin >> a >> b >> n >> m;
    bool ans = 1;
    if (n + m > a + b)
    {
        cout << "No" << endl;
        return;
    }
    if (min(a,b) < m)
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        solve(i);
    }
    return 0;
}
