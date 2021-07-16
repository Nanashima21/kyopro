#include <bits/stdc++.h>
using namespace std;
//using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;
//typedef tuple<ll,ll,ll> tupl;

int main()
{
    while(true) {
        int h;
        cin >> h;
        if(h==0) break;
        vector<vector<int> > v(h,vector<int> (5));
        rep(i,h) rep(j,5) cin >> v[i][j];
        int sum=0,tot=-1;
        while(sum!=tot) {
            tot=sum;
            bool flag=true;
            rep(i,h) {
                flag=true;
                int c=v[i][0];
                rep(j,4) if(v[i][j+1]!=c) flag=false;
                if(flag) {
                    for(int l=i;l>=0;l--) {
                        if(l==0) rep(k,5) v[l][k]=0;
                        else rep(k,5) v[l][k]=v[l-1][k];
                    } 
                    sum+=c*5;
                }
                rep(j,2) {
                    int c=v[i][j];
                    flag=true;
                    rep(k,3) if(v[i][j+k+1]!=c) flag=false;
                    if(flag) {
                        for(int l=i;l>=0;l--) {
                            if(l==0) rep(k,4) v[l][j+k]=0;
                            else rep(k,4) v[l][j+k]=v[l-1][j+k];
                        }
                        sum+=c*4;
                        break;
                    }
                }
                rep(j,3) {
                    int c=v[i][j];
                    flag=true;
                    rep(k,2) if(v[i][j+k+1]!=c) flag=false;
                    if(flag) {
                        for(int l=i;l>=0;l--) {
                            if(l==0) rep(k,3) v[l][j+k]=0;
                            else rep(k,3) v[l][j+k]=v[l-1][j+k];
                        }
                        sum+=c*3;
                        break;
                    }
                }
                //cout << i << " " << sum << endl;
            }
        }  
        cout << sum << endl;
    }
    return 0;
}
