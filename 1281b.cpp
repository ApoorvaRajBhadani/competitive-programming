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

void solve(ll caseno)
{
    ll i, j, ns, nc, swaps = 0;
    string s, c;
    cin >> s >> c;
    ns = s.size();
    nc = c.size();
    if (s < c)
    {
        cout << s << endl;
        return;
    }
    for (i = 0; i < min(nc, ns); i++)
    {
       // cout<<s[i]<<" "<<c[i]<<endl;
        if (s[i] < c[i])
        {
            cout << s << endl;
            return;
        }
        else
        {
            fo(j, i + 1, ns)
            {
                if (s[j] < c[i])
                {
                    swap(s[i], s[j]);
                    cout << s << endl;
                    return;
                }
            }
            if(s[i]==c[i]) continue;
            fo(j, i + 1, ns)
            {
                if (s[j] <= c[i])
                {
                    swap(s[i], s[j]);
                    if (s<c)
                    {
                        cout << s << endl;
                        return;
                    }else{
                       cout << "---" << endl;
                       return;
                    }
                }
            }
            if(s[i]!=c[i]) break;
        }
    }
    cout << "---" << endl;
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
