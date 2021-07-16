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
    string s;
    cin >> s;
    int lo=0,lx=0;
    ll ans=0;
    rep(i,n) {
        if(s[i]=='o') {
            lo=i+1;
            if(lx!=0) ans+=lx;
        } else {
            lx=i+1;
            if(lo!=0) ans+=lo;
        }
    }
    cout << ans << endl;
    return 0;
}