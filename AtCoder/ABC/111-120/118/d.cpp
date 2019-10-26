#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define REP(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, a, b) for(int i=(a); i<(b); ++i)
#define FORR(i, a, b) for(int i=(b)-1; i>=(a); --i)

#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
#define DEBUG_VEC(v) cout<<#v<<":";REP(i, v.size())cout<<' '<<v[i];cout<<'\n'
#define ALL(a) (a).begin(), (a).end()

#define CHMIN(a, b) a=min((a), (b))
#define CHMAX(a, b) a=max((a), (b))

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int num[9]={2, 5, 5, 4, 5, 6, 3, 7, 6};
bool used[10];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, a[10];
  cin>>n>>m;
  REP(i, m){
    cin>>a[i];
    used[a[i]]=true;
  }
  int five;
  bool five_flag=false;
  if(used[5]){
    five=5;
    five_flag=true;
  }
  else if(used[3]){
    five=3;
    five_flag=true;
  }
  else if(used[2]){
    five=2;
    five_flag=true;
  }
  int six;
  bool six_flag=false;
  if(used[9]){
    six=9;
    six_flag=true;
  }
  else if(used[6]){
    six=6;
    six_flag=true;
  }
  if(used[1]){
    if(~n&1){
      REP(i, n/2){
        cout<<1;
      }
      return 0;
    }
    if(used[7]){
      cout<<7;
      n-=3;
      REP(i, n/2){
        cout<<1;
      }
      return 0;
    }
    if(five_flag){
      cout<<five;
      n-=5;
      REP(i, n/2){
        cout<<1;
      }
      return 0;
    }
    else{
      cout<<8;
      n-=7;
      REP(i, n/2){
        cout<<1;
      }
      return 0;
    }
  }
  if(used[7]){
    if(n%3==0){
      REP(i, n/3){
        cout<<7;
      }
      return 0;
    }
    if(n%3==1){
      if(used[4]){
        n-=4;
        REP(i, n/3){
          cout<<7;
        }
        cout<<4;
        return 0;
      }
      if(used[8]){
        cout<<8;
        n-=7;
        REP(i, n/3){
          cout<<7;
        }
        return 0;
      }
      else{
        n-=10;
        REP(i, n/3){
          cout<<7;
        }
        cout<<five<<five;
        return 0;
      }
    }
    else{
      if(five_flag){
        n-=5;
        REP(i, n/3){
          cout<<7;
        }
        cout<<five;
        return 0;
      }
      if(used[4]){
        n-=8;
        REP(i, n/3){
          cout<<7;
        }
        cout<<44;
        return 0;
      }
      else{
        cout<<88;
        n-=14;
        REP(i, n/3){
          cout<<7;
        }
        return 0;
      }
    }
  }
  if(used[4]){
    if(n%4==0){
      REP(i, n/4){
        cout<<4;
      }
      return 0;
    }
    if(n%4==1){
      if(five_flag){
        if(five==5){
          cout<<five;
          n-=5;
          REP(i, n/4){
            cout<<4;
          }
          return 0;
        }
        else{
          n-=5;
          REP(i, n/4){
            cout<<4;
          }
          cout<<five;
          return 0;
        }
      }
      if(six_flag){
        if(six==9){
          cout<<six<<8;
        }
        else{
          cout<<8<<six;
        }
        n-=13;
        REP(i, n/4){
          cout<<4;
        }
        return 0;
      }
      else{
        cout<<888;
        n-=21;
        REP(i, n/4){
          cout<<4;
        }
        return 0;
      }
    }
    if(n%4==2){
      if(six_flag){
        cout<<six;
        n-=6;
        REP(i, n/4){
          cout<<4;
        }
        return 0;
      }
      if(five_flag){
        if(five==5){
          cout<<five<<five;
          n-=10;
          REP(i, n/4){
            cout<<4;
          }
          return 0;
        }
        else{
          n-=10;
          REP(i, n/4){
            cout<<4;
          }
          cout<<five<<five;
          return 0;
        }
      }
      else{
        cout<<88;
        n-=14;
        REP(i, n/4){
          cout<<4;
        }
        return 0;
      }
    }
    else{
      if(six_flag && six==9 && five_flag){
        cout<<six;
        n-=11;
        if(five==5){
          cout<<five;
          REP(i, n/4){
            cout<<4;
          }
          return 0;
        }
        else{
          REP(i, n/4){
            cout<<4;
          }
          cout<<five;
          return 0;
        }
      }
      if(used[8]){
        cout<<8;
        n-=7;
        REP(i, n/4){
          cout<<4;
        }
        return 0;
      }
      if(six_flag){
        cout<<six;
        n-=11;
        if(five==5){
          cout<<five;
          REP(i, n/4){
            cout<<4;
          }
          return 0;
        }
        else{
          REP(i, n/4){
            cout<<4;
          }
          cout<<five;
          return 0;
        }
      }
      else{
        if(five==5){
          cout<<five<<five<<five;
          n-=15;
          REP(i, n/4){
            cout<<4;
          }
          return 0;
        }
        else{
          n-=15;
          REP(i, n/4){
            cout<<4;
          }
          cout<<five<<five<<five;
          return 0;
        }
      }
    }
  }
  if(five_flag){
    if(n%5==0){
      REP(i, n/5){
        cout<<five;
      }
      return 0;
    }
    if(n%5==1){
      if(six_flag){
        cout<<six;
        n-=6;
        REP(i, n/5){
          cout<<five;
        }
        return 0;
      }
      else{
        cout<<888;
        n-=21;
        REP(i, n/5){
          cout<<five;
        }
        return 0;
      }
    }
    if(n%5==2){
      if(six_flag && six==9){
        cout<<six<<six;
        n-=12;
        REP(i, n/5){
          cout<<five;
        }
        return 0;
      }
      if(used[8]){
        cout<<8;
        n-=7;
        REP(i, n/5){
          cout<<five;
        }
        return 0;
      }
      else{
        cout<<six<<six;
        n-=12;
        REP(i, n/5){
          cout<<five;
        }
        return 0;
      }
    }
    if(n%5==3){
      if(six_flag && six==9){
        cout<<six<<six<<six;
        n-=18;
        REP(i, n/5){
          cout<<five;
        }
        return 0;
      }
      if(six_flag && used[8]){
        if(six==9){
          cout<<six<<8;
        }
        else{
          cout<<8<<six;
        }
        n-=13;
        REP(i, n/5){
          cout<<five;
        }
        return 0;
      }
      if(six_flag){
        cout<<six<<six<<six;
        n-=18;
        REP(i, n/5){
          cout<<five;
        }
        return 0;
      }
      else{
        cout<<8888;
        n-=28;
        REP(i, n/5){
          cout<<five;
        }
        return 0;
      }
    }
    else{
      if(six_flag && six==9){
        cout<<six<<six<<six<<six;
        n-=24;
        REP(i, n/5){
          cout<<five;
        }
        return 0;
      }
      if(used[8]){
        cout<<88;
        n-=14;
        REP(i, n/5){
          cout<<five;
        }
        return 0;
      }
      else{
        cout<<six<<six<<six<<six;
        n-=24;
        REP(i, n/5){
          cout<<five;
        }
        return 0;
      }
    }
  }
  if(six_flag){
    if(six==9){
      int tmp=n%6;
      n-=(n%6)*7;
      REP(i, n/6){
        cout<<six;
      }
      REP(i, tmp){
        cout<<8;
      }
    }
    else{
      REP(i, n%6){
        cout<<8;
      }
      n-=(n%6)*7;
      REP(i, n/6){
        cout<<six;
      }
      return 0;
    }
  }
  else{
    REP(i, n/7){
      cout<<8;
    }
    return 0;
  }
  return 0;
}
