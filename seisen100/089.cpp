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
    int n;
    cin >> n;
    vector<int> v(n+1,0);
    int j=0,b=-1;
    rep(i,n) {
        int a;
        cin >> a;
        if(a!=b) v[j]++; 
        else {
            j++;
            v[j]++;
        }
        b=a;
    }
    int ans=0;
    for(int i=2;i<=n;i++) ans=max(ans,v[i-2]+v[i-1]+v[i]);
    cout << ans << endl;
    return 0;
}
