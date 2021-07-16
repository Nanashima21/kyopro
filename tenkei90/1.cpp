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
    ll n,l,k;
    cin >> n >> l >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ac=0,wa=l+1;
    while(wa-ac>1) {
        ll mid=(ac+wa)/2;
        ll cnt=0,pre=0;
        rep(i,n) {
            if(a[i]-pre>=mid&&l-a[i]>=mid) {
                cnt++;
                pre=a[i];
            }
        }
        if(cnt>=k) ac=mid;
        else wa=mid;
    }
    cout << ac << endl;
    return 0;
}