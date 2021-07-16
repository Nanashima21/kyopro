#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> k(m),p(m);
    vector<vector<int>> s(m,vector<int> ());
    rep(i,m) {
        cin >> k[i];
        rep(j,k[i]) {
            int x;
            cin >> x;
            x--;
            s[i].push_back(x);
        }
    }
    int ans=0;
    rep(i,m) cin >> p[i];
    for(int bit=0;bit<(1<<n);bit++) {
        int ni;
        vector<int> v;
        rep(i,n) {
            if(1<<i&bit) ni=1;
            else ni=0;
            v.push_back(ni);
        }
        bool flag=true;
        rep(i,m) {
            int sum=0;
            rep(j,k[i]) sum+=v[s[i][j]];
            sum%=2;
            if(p[i]!=sum) flag=false;
        }
        if(flag) ans++;
    }
    cout << ans << endl;
    return 0;
}