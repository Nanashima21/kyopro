#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
typedef pair<ll,ll> pl;
typedef tuple<ll,ll,ll> tupl;

#define M 100001

bool isprime(ll x) {
    if(x<2) return 0;
    else if(x==2) return 1;
    if(x%2==0) return 0;
    for(ll i=3;i*i<=x;i+=2) if(x%i==0) return 0;
    return 1;
}

int main()
{
    int q;
    cin >> q;
    vector<ll> v(M,0);
    for(int i=1;i<M;i++) {
        v[i]=v[i-1];
        if(isprime(i)&&isprime((i+1)/2)) v[i]++;
    }
    rep(i,q) {
        int l,r;
        cin >> l >> r;
        cout << v[r]-v[l-1] << endl;
    }
    return 0;
}
