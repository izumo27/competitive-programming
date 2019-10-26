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
  int t;
  string v[2]={"tokyo", "kyoto"};
  cin>>t;
  REP(i, t){
    string s;
    cin>>s;
    int a[25], len=s.size(), m=0;
    bool ok;
    REP(j, len-4){
      ok=true;
      REP(k, 5){
        if(s[j+k]!=v[0][k]){
          ok=false;
          break;
        }
      }
      if(ok){
        a[m]=j;
        ++m;
        j+=4;
      }
    }
    REP(j, len-4){
      ok=true;
      REP(k, 5){
        if(s[j+k]!=v[1][k]){
          ok=false;
          break;
        }
      }
      if(ok){
        a[m]=j;
        ++m;
        j+=4;
      }
    }
    sort(a, a+m);
    int t=0, ans=0;
    REP(j, m){
      if(t<=a[j]){
        ++ans;
        t=a[j]+5;
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}
