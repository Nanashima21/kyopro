#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll sum=2*c*max(x,y);
    ll ma=max(x,y),mi=min(x,y),ans=sum;
    rep(i,ma) {
        sum-=2*c;
        if(ma-mi>i) {
            if(ma==x) sum+=a;
            else sum+=b;
        } else sum+=(a+b);
        ans=min(ans,sum);
    }
    cout << ans << endl;
    return 0;
}