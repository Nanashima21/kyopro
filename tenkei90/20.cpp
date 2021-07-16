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
    ll a,b,c;
    cin >> a >> b >> c;
    ll x=1;
    rep(i,b) x*=c;
    if(a<x) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}