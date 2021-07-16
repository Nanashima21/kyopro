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
    vector<vector<int>> v(n,vector<int> ());
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        if(a>b) v[a].push_back(b);
        if(a<b) v[b].push_back(a);
    }
    int ans=0;
    rep(i,n) if(v[i].size()==1) ans++;
    cout << ans << endl;
    return 0;
}