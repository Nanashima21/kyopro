#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
typedef pair<ll,ll> pl;
typedef tuple<ll,ll,ll> tupl;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) a[i]+=a[i-1];
    for(int i=1;i<=n;i++) {
        ll m=0;
        rep(j,n-i+1) m=max(m,a[j+i]-a[j]);
        cout << m << endl;
    }
    return 0;
}
