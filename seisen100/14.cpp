#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    int n,k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans=INF;
    for(int bit=0;bit<(1<<(n-1));bit++) {
        ll sum=0,cnt=1,x=a[0];
        rep(i,n) {
            if(1<<i&bit) {
                cnt++;
                if(x<a[i+1]) x=a[i+1];
                else {
                    x++;
                    sum+=x-a[i+1];
                }
            } else if(x<a[i+1]) x=a[i+1];
        }
        if(cnt>=k) ans=min(ans,sum);
    }
    cout << ans << endl;
    return 0;
}