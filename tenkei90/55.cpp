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
    ll n,p,q;
    cin >> n >> p >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans=0;
    for(int i1=0;i1<n;i1++) {
        for(int i2=i1+1;i2<n;i2++) {
            for(int i3=i2+1;i3<n;i3++) {
                for(int i4=i3+1;i4<n;i4++) {
                    for(int i5=i4+1;i5<n;i5++) {
                        ll tot=1;
                        tot*=a[i1];
                        tot%=p;
                        tot*=a[i2];
                        tot%=p;
                        tot*=a[i3];
                        tot%=p;
                        tot*=a[i4];
                        tot%=p;
                        tot*=a[i5];
                        tot%=p;
                        if(tot==q) ans++;
                    }
                } 
            }
        }
    }
    cout << ans << endl;
    return 0;
}