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
    vector<ll> h(n),s(n);
    rep(i,n) cin >> h[i] >> s[i];
    ll l=0,r=INF;
    while(r-l>1) {
        ll mid=(l+r)/2;
        bool flag=true;
        vector<ll> t(n);
        rep(i,n) {
            if(h[i]>mid) flag=false;
            else t[i]=(mid-h[i])/s[i]; 
        }
        sort(all(t));
        rep(i,n) if(t[i]<i) flag=false;
        if(flag) r=mid;
        else l=mid;
    }
    cout << r << endl;
    return 0;
}