#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
typedef pair<ll,ll> pl;
typedef tuple<ll,ll,ll> tupl;

const int mod=1e5;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<ll> s(n);
    for(int i=1;i<n;i++) {
        cin >> s[i];
        s[i]+=s[i-1];
    }
    ll sum=0,cp=0;
    rep(i,m) {
        int a;
        cin >> a;
        sum+=abs(s[a+cp]-s[cp]);
        cp+=a;
        sum%=mod;
    }
    cout << sum << endl;
    return 0;
}
