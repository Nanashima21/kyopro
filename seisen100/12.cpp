#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(n,vector<int> (n));
    rep(i,m) {
        int x,y;
        cin >> x >> y;
        x--; y--;
        v[x][y]=1;
        v[y][x]=1;
    }
    int ans=0;
    for(int bit=0;bit<(1<<n);bit++) {
        vector<int> x;
        rep(i,n) if(1<<i&bit) x.push_back(i);
        int y=x.size();
        bool flag=true;
        rep(i,y) for(int j=i+1;j<y;j++) {
            if(v[x[i]][x[j]]!=1) flag=false;
        } 
        if(flag) ans=max(ans,y);
    }
    cout << ans << endl;
    return 0;
}