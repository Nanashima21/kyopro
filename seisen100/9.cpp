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
    cin >> n;
    vector<pair<int,int>> p(n); 
    rep(i,n) {
        int x,y;
        cin >> x >> y;
        p[i]=make_pair(x,y);
    }
    cin >> m;
    vector<pair<int,int>> q(m);
    rep(i,m) {
        int x,y;
        cin >> x >> y;
        q[i]=make_pair(x,y);
    }
    sort(all(p));
    sort(all(q));
    rep(i,m) {
        int x,y;
        x=q[i].first-p[0].first;
        y=q[i].second-p[0].second;
        bool flag=true;
        for(int j=1;j<n;j++) {
            int nx,ny;
            nx=p[j].first+x;
            ny=p[j].second+y;
            if(!binary_search(all(q),make_pair(nx,ny))) {
                flag=false;
                break;
            }
        }
        if(flag) {
            cout << x << " " << y << endl;
            return 0;  
        }
    }
    return 0;
}