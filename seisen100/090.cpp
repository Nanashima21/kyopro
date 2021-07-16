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
    int n,m;
    cin >> n >> m;
    vector<int> x(n+m),y(n+m),r(n);
    rep(i,n) cin >> x[i] >> y[i] >> r[i];
    rep(i,m) cin >> x[i+n] >> y[i+n];
    double ans=500.0;
    rep(i,n+m) {
        rep(j,n+m) {
            if(i==j) continue;
            double dist=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
            if(i<n&&j<n) ans=min(ans,(double)min(r[i],r[j]));
            else if(i<n) {
                ans=min(ans,min(dist-(double)r[i],(double)r[i]));
            } else if(j<n) {
                ans=min(ans,min(dist-(double)r[j],(double)r[j]));
            } else {
                ans=min(ans,(double)dist/2.0);
            }
        }
    }   
    printf("%.15f\n",ans);
    return 0;
}
