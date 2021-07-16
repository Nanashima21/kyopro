#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    ll x,y,ans=INF;
    rep(i,n) {
        x=a[i];
        rep(j,n) {
            y=b[j];
            ll sum=0;
            rep(k,n) {
                sum+=abs(x-y);
                if(a[k]<x) sum+=2*abs(x-a[k]);
                if(b[k]>y) sum+=2*abs(b[k]-y);
            }
            ans=min(ans,sum);
        }
    }
    cout << ans << endl;
    return 0;
}