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
    ll n;
    cin >> n;
    vector<ll> c1(n+1,0),c2(n+1,0); 
    for(int i=1;i<=n;i++) {
        int c,p;
        cin >> c >> p;
        c1[i]+=c1[i-1];
        c2[i]+=c2[i-1];
        if(c==1) c1[i]+=p;
        else c2[i]+=p;
    }
    ll q;
    cin >> q;
    rep(i,q) {
        ll l,r;
        cin >> l >> r;
        l--;
        cout << c1[r]-c1[l] << " " << c2[r]-c2[l] << endl;
    }
    return 0;
}