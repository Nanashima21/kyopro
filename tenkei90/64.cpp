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
    int n,q;
    cin >> n >> q;
    vector<ll> a(n),x;
    ll sum=0;
    rep(i,n) {
        cin >> a[i];
        if(i!=0) {
			sum+=abs(a[i]-a[i-1]);
          	x.push_back(a[i]-a[i-1]);
        }
    }
    rep(i,q) {
        ll l,r,v;
        cin >> l >> r >> v;
        l--; r--;
        if(l!=0) {
			sum-=abs(x[l-1]);
          	x[l-1]+=v;
          	sum+=abs(x[l-1]);
        }
        if(r!=n-1) {
			sum-=abs(x[r]);
          	x[r]-=v;
          	sum+=abs(x[r]);
        }
        cout << sum << endl;
    }
    return 0;
}