
#include "bits/stdc++.h"
#pragma GCC optimize "03"
using namespace std;

#define int long long int
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,a,b) for (int i = a; i < b; ++i)
#define IOS ios::sync_with_stdio(false); cin.tie(NULL);
#ifndef LOCAL
#define dbg(...) ;
#define endl '\n'
#endif

const int inf = 1e15;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

signed main(){
    IOS;
    int t;
    cin >> t;
    while (t--) {
    	int n, m;
    	cin >> n >> m;
    	map<vector<int>, int> dis;
    	map<pair<int, int>, int> found;
    	vector<int> p(n);
    	for (int i = 0; i < n; i++) {
    		cin >> p[i];
    		p[i]--;
    	}
    	for (int i = 0; i < m; i++) {
    		int x, y;
    		cin >> x >> y;
    		if (x > y) swap(x, y);
    		x--; y--;
    		found[{x, y}] = 1;
    	}

    	vector<int> temp(n);
    	for (int i = 0; i < n; i++)
    		temp[i] = i;

    	do {
    		dis[temp] = inf;
    	} while (next_permutation(temp.begin(), temp.end()));

    	deque<vector<int>> q;
    	dis[p] = 0;
    	q.push_front(p);

    	while(!q.empty()) {
    		vector<int> t = q.front();
    		q.pop_front();
    		for (int i = 0; i < n; i++) {
    			for (int j = i + 1; j < n; j++) {
		    		vector<int> temp = t;
    				if (found.find({i, j}) != found.end()) {
	    				swap(temp[i], temp[j]);
    					if (dis[temp] > dis[t] + 0) {
    						dis[temp] = dis[t] + 0;
    						q.push_front(temp);
    					}
    				}
    				else {
    					swap(temp[i], temp[j]);
    					if (dis[temp] > dis[t] + 1) {
    						dis[temp] = dis[t] + 1;
    						q.push_back(temp);
    					}
    				}
    			}

    		}
    	}
    	for (int i = 0; i < n; i++)
    		temp[i] = i;
    	cout << dis[temp] << endl;
    }
    return 0;
}
