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
    vector<double> x(n),y(n);
    rep(i,n) cin >> x[i] >> y[i];
    vector<int> v;
    rep(i,n) v.push_back(i);
    double sum=0;
    int cnt=0;
    do {
        cnt++;
        rep(i,n-1) {
            sum+=sqrt(pow(x[v[i+1]]-x[v[i]],2)+pow(y[v[i+1]]-y[v[i]],2));
        }
    } while(next_permutation(all(v)));
    printf("%.10f\n",(double)sum/cnt);
    return 0;
}