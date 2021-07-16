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

const ll inf=1000000000000000000;

int main()
{
    ll a,b;
    cin >> a >> b;
    ll gc=gcd(a,b);
    ll lc=gc;
    if(lc<=inf/(a/gc)) lc*=a/gc;
    else {
        cout << "Large" << endl;
        return 0;
    }
    if(lc<=inf/(b/gc)) lc*=b/gc;
    else {
        cout << "Large" << endl;
        return 0;
    }
    cout << lc << endl;
    return 0;
}