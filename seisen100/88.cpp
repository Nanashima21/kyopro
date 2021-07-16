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
    int n;
    cin >> n;
    vector<pair<int,int>> p;
    rep(i,n) {
        int a;
        cin >> a;
        if(p.size()>0&&p.back().first==a) {
            p.back().second++;
            continue;
        }
        if(i%2==0) {
            p.emplace_back(a,1);
            continue;
        } else {
            if(p.size()==1) {
                p.back().first=a;
                p.back().second++;
            } else {
                int t=p.back().second+1;
                p.pop_back();
                p.back().second+=t;
            }
        }
    }
    int ans=0;
    for(auto u:p) if(u.first==0) ans+=u.second;
    cout << ans << endl;
    return 0;
}