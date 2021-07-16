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

ll gcd(ll x,ll y){
    if (y==0) return x;
    else return gcd(y,x%y);
}

int main()
{
    ll a,b,c;
    cin >> a >> b >> c;
    ll gc=gcd(a,gcd(b,c));
    a/=gc; b/=gc; c/=gc;
    ll ans=a+b+c-3;
    cout << ans << endl;
    return 0;
}