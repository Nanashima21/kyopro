#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    ll d,n,m;
    cin >> d >> n >> m;
    vector<ll> v;
    v.push_back(0);
    rep(i,n-1) {
        int nd;
        cin >> nd;
        v.push_back(nd);
    } 
    v.push_back(d);
  	sort(all(v));
    ll sum=0;
    rep(i,m) {
        int k;
        cin >> k;
        auto iter=upper_bound(all(v),k);
        int x=iter-v.begin();
        int y=x-1;
        sum+=min(abs(v[x]-k),abs(v[y]-k));
    }
    cout << sum << endl;
    return 0;
}
