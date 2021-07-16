#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

vector<int> cnt;
vector<bool> flag;

void dfs(vector<vector<int>> &v,int p,int x) {
    flag[p]=true;
    cnt[p]+=x;
    x=cnt[p];
    for(auto next_p:v[p]) {
        if(flag[next_p]) continue;
        dfs(v,next_p,x); 
    }
}

int main()
{
    int n,q;
    cin >> n >> q;
    vector<vector<int>> v(n,vector<int> ());
    rep(i,n-1) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cnt.assign(n,0);
    rep(i,q) {
        int p,x;
        cin >> p >> x;
        p--;
        cnt[p]+=x;
    }
    flag.assign(n,false);
    dfs(v,0,0);
    rep(i,n) {
        if(i==0) cout << cnt[i];
        else cout << " " << cnt[i];
    }
    cout << endl;
    return 0;
}