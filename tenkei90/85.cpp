#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;
typedef tuple<ll,ll,ll> tupl;

int main()
{
    ll n;
    cin >> n;
    vector<ll> res;
    for(ll i=1;i*i<=n;i++) {
        if(n%i==0) {
            res.push_back(i);
            if(n/i!=i) res.push_back(n/i);
        }
    }
    sort(all(res));
    ll ans=0,x=res.size();
    for(int i=0;i<x;i++) {
        for(int j=i;j<x;j++) {
            if((n/res[i])<res[j]) continue;
            if(n%(res[i]*res[j])!=0LL) continue;
            if(res[j]<=n/(res[i]*res[j])) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}