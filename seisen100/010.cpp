#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    int n,q;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    cin >> q;
    vector<int> m(q),v;
    rep(i,q) cin >> m[i];
    for(int bit=0;bit<(1<<n);bit++) {
        int sum=0;
        rep(i,n) {
            if(1<<i&bit) sum+=a[i];
        }
        v.push_back(sum);
    }
    rep(i,q) {
        bool flag=false;
        rep(j,v.size()) {
            if(v[j]==m[i]) {
                flag=true;
                cout << "yes" << endl;
                break;
            }
        }
        if(!flag) cout << "no" << endl;
    }
    return 0;
}
