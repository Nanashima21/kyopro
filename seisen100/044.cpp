#include <bits/stdc++.h>
using namespace std;
//using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    int m=1e6+1;
    vector<ll> dp1(m,INF),dp2(m,INF);
    dp1[0]=dp2[0]=0;
    for(int i=1;;i++) {
        ll a=(i*(i+1)*(i+2))/6;
        if(a>=m) break;
        for(int j=a;j<m;j++) {
            dp1[j]=min(dp1[j],dp1[j-a]+1);
            if(a&1) dp2[j]=min(dp2[j],dp2[j-a]+1);
        } 
    }
    while(true) {
        int n;
        cin >> n;
        if(n==0) break;
        cout << dp1[n] << " " << dp2[n] << endl;
    }
    return 0;
}
