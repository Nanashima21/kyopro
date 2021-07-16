#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    int n,q;
    cin >> n;
    vector<ll> s(n);
    rep(i,n) cin >> s[i];
    cin >> q;
    ll cnt=0;
    rep(i,q) {
        ll t;
        cin >> t;
        ll l=0,r=n;
        while(l<r) {
            ll mid=(l+r)/2;
            if(s[mid]==t) {
                cnt++;
                break;
            } else if(s[mid]<t) l=mid+1;
            else r=mid;
        }
    } 
    cout << cnt << endl; 
    return 0;
}
