#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

double p;

double f(double x) {
    return x+p*pow(2,-x/1.5);
}

int main()
{
    cin >> p;
    double l=0,r=p;
    while(r-l>1e-8) {
        double m1=(l*2+r)/3.0;
        double m2=(l+r*2)/3.0;
        if(f(m1)<f(m2)) r=m2;
        else l=m1; 
    } 
    printf("%.10f\n",f(l));
    return 0;
}
