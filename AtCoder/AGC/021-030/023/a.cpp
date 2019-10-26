#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define REP(i, n) for(int i=0; i<n; ++i)
#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define FORR(i, a, b) for(int i=b-1; i>=a; --i)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, a;
  cin>>n;
  ll s[210000];
  s[0]=0;
  REP(i, n){
    cin>>a;
    s[i+1]=s[i]+a;
  }
  sort(s, s+n+1);
  ll ans=0;
  REP(i, n){
    ll cnt=1;
    while(i+1<n+1 && s[i]==s[i+1]){
      ++i;
      ++cnt;
    }
    if(cnt>=2) ans+=cnt*(cnt-1)/2;
  }
  cout<<ans<<'\n';
  return 0;
}
