#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

vector<ll> enum_div(ll n) {
    vector<ll> ret;
    for(ll i=1;i*i<=n;i++) {
        if(n%i==0) {
            ret.push_back(i);
            if(n/i!=i) ret.push_back(n/i);
        }
    }
    sort(ret.begin(),ret.end());
    return ret;
    //const auto &res = enum_div(n);
}

int main()
{
    int n;
    cin >> n;
    int cnt=0;
    for(int i=1;i<=n;i++) {
        const auto &res = enum_div(i);
        if(i%2==1&&res.size()==8) cnt++;
    }
    cout << cnt << endl;
    return 0;
}