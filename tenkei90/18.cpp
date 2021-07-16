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
    ll t,l,x,y;
    cin >> t >> l >> x >> y;
    int q;
    cin >> q;
    double theta=360/(t*1.0);
    rep(i,q) {
        ll e;
        cin >> e;
        double ny,nz;
        double rad=theta*e*M_PI/180.0;
        ny=-l/2.0*sin(rad);
        nz=l/2.0-l/2.0*cos(rad);
        double dist=sqrt(x*x+pow(y-ny,2));
        double ans=atan(nz/dist)*180.0/M_PI;
        printf("%.10f\n",fabs(ans));
    }
    return 0;
}