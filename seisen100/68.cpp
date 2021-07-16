#include <bits/stdc++.h>
using namespace std;
//using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
//typedef pair<ll,ll> pl;
//typedef tuple<ll,ll,ll> tupl;

vector<pair<ll,ll> > prime_factorize(ll N) {
   vector<pair<ll,ll> > res;
   for (ll a = 2; a * a <= N; ++a) {
       if (N % a != 0) continue;
       ll ex = 0;
       while (N % a == 0) {
           ++ex;
           N /= a;
       }
       res.push_back({a, ex});
   }
   if (N != 1) res.push_back({N, 1});
   return res;
   //const auto &res = prime_factorize(n);
}

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll,ll> > res = prime_factorize(n);
    cout << n << ":";
    int x=res.size();
    rep(i,x) {
        rep(j,res[i].second) {
            cout << " " << res[i].first;
        }
    }
    cout << endl;
    return 0;
}