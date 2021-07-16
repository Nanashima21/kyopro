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

int h,w,k,sum,cnt;

void fall(vector<vector<int>> &a) {
    vector<vector<int>> b;
    while(true) {
        if(a==b) return;
        b=a;
        rep(i,w) rep(j,h-1) {
            if(a[j+1][i]==0) {
                a[j+1][i]=a[j][i];
                a[j][i]=0;
            }
        }
    }
}

void erase(vector<vector<int>> &a) {
    rep(i,h) rep(j,w-1) {
        int tot=0;
        for(int l=j+1;l<w;l++) {
            if(a[i][j]==a[i][l]) tot++;
            else break;
        }
        if(tot+1>=k) {
            sum+=pow(2,cnt)*a[i][j]*(tot+1);
            rep(l,tot+1) a[i][j+l]=0;
        }
        j+=tot;
    }
}

int main()
{
    cin >> h >> w >> k;
    vector<vector<int>> c(h,vector<int> (w));
    rep(i,h) {
        string s; 
        cin >> s;
        rep(j,w) c[i][j] = s[j]- '0';
    }
    int ans=0;
    rep(i,h) rep(j,w) {
        vector<vector<int>> a=c;
        sum=0; cnt=0;
        a[i][j]=0;
        fall(a);
        while(true) {
            erase(a);
            vector<vector<int>> b=a;
            fall(a);
            if(a==b) break;
            cnt++;
        }
        ans=max(ans,sum);
    }
    cout << ans << endl;
    return 0;
}
