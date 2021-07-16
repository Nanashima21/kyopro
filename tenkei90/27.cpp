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
    map<string,int> m;
    rep(i,n) {
        string s;
        cin >> s;
        if(m[s]>0) continue;
        m[s]++;
        cout << i+1 << endl;
    }
    return 0;
}