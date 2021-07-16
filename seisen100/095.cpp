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
    ll a,b,k;
    cin >> a >> b >> k;
    a-=k;
    if(a>=0) {
        cout << a << " " << b << endl;
        return 0;
    }
    b+=a;
    if(b<=0) b=0;
    cout << 0 << " " << b << endl;
    return 0;
}
