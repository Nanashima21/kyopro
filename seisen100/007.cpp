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
    vector<pair<int,int>> p(n);
    rep(i,n) cin >> p[i].first >> p[i].second;
    sort(all(p));
    int ans=0;
    rep(i,n) {
        for(int j=i+1;j<n;j++) {
            int qx,qy,rx,ry;
            qx=p[j].first-p[j].second+p[i].second;
            qy=p[j].second+p[j].first-p[i].first;
            rx=p[i].first-p[j].second+p[i].second;
            ry=p[i].second+p[j].first-p[i].first;
            bool flag1=false,flag2=false;
            flag1=binary_search(all(p),make_pair(qx,qy));
            flag2=binary_search(all(p),make_pair(rx,ry));
            if(flag1&&flag2) {
                int area=pow(p[i].first-p[j].first,2);
                area+=pow(p[i].second-p[j].second,2);
                ans=max(ans,area);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
