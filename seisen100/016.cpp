#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n),q(n),v;
    rep(i,n) cin >> p[i];
    rep(i,n) cin >> q[i];
    rep(i,n) v.push_back(i+1);
    int x,y,cnt=0;
    do {
        cnt++;
        bool flag=true;
        rep(i,n) if(v[i]!=p[i]) flag=false;
        if(flag) x=cnt;
        flag=true;
        rep(i,n) if(v[i]!=q[i]) flag=false;
        if(flag) y=cnt;
    } while(next_permutation(all(v)));
    cout << abs(x-y) << endl;
    return 0;
}
