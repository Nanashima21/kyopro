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
    int k=0;
    for(int i=1;i<=n;i++) {
        if(n==i*(i+1)/2) {
            k=i;
            break;
        }
    }
    if(k==0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        cout << k+1 << endl;
        vector<vector<int>> v(k+1);
        int sum=1;
        rep(i,k+1) for(int j=i+1;j<k+1;j++) {
            v[i].push_back(sum);
            v[j].push_back(sum);
            sum++;
        }
        rep(i,k+1) {
            cout << k;
            rep(j,k) cout << " " << v[i][j];
            cout << endl;
        }
    }
    return 0;
}