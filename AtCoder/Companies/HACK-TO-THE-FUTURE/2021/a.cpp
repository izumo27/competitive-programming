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

#define DEBUG(x) cout<<#x<<": "<<(x)<<'\n'
#define DEBUG_VEC(v) cout<<#v<<":";REP(i, v.size())cout<<' '<<v[i];cout<<'\n'
#define ALL(a) (a).begin(), (a).end()

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

constexpr ll MOD=1000000007ll;
// constexpr ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-9;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

constexpr int n=100, h=20, w=20;
int x[125], y[125];
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1, 0};
int mp[25][25];
// 回収したカード
stack<int> st;

string ans="";

// ひし形の内部か判定
bool inside(int a, int b){
  if(a<h/2){
    if(b<w/2){
      return (9-a)+(9-b)<=6;
    }
    else{
      return (9-a)+(b-10)<=6;
    }
  }
  else{
    if(b<w/2){
      return (a-10)+(9-b)<=6;
    }
    else{
      return (a-10)+(b-10)<=6;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  REP(i, h){
    REP(j, w){
      mp[i][j]=-1;
    }
  }
  REP(i, n){
    cin>>x[i]>>y[i];
    mp[x[i]][y[i]]=i;
  }
  // 方針：中央にすべてのカードを置いてから回収する
  int curx=0, cury=0, curd=0;

  // 1. 中央にないカードを集める
  // 上
  REP(i, 3){
    curd=(i&1 ? 2 : 0);
    REP(j, w){
      if(mp[curx][cury]!=-1){
        ans+='I';
        st.push(mp[curx][cury]);
      }
      int nxty=cury+dy[curd];
      if(nxty<0 || nxty>=w){
        ++curx;
        ans+='D';
      }
      else{
        ans+=(dy[curd]>0 ? 'R' : 'L');
        cury=nxty;
      }
    }
  }
  // 右上
  for(int i=7; i>=3; i-=2){
    REP(j, 2){
      curd=(j&1 ? 0 : 2);
      REP(k, i+1){
        if(mp[curx][cury+dy[curd]*k]!=-1){
          ans+='I';
          st.push(mp[curx][cury+dy[curd]*k]);
        }
        if(k==i){
          ans+='D';
          ++curx;
          cury=cury+dy[curd]*k;
        }
        else{
          ans+=(dy[curd]>0 ? "R" : "L");
        }
      }
    }
  }
  // 真ん中
  REP(j, 2){
    curd=(j&1 ? 0 : 2);
    REP(k, 2+1){
      if(mp[curx][cury+dy[curd]*k]!=-1){
        ans+='I';
        st.push(mp[curx][cury+dy[curd]*k]);
      }
      if(k==2){
        ans+='D';
        ++curx;
        cury=cury+dy[curd]*k;
      }
      else{
        ans+=(dy[curd]>0 ? "R" : "L");
      }
    }
  }
  // 右下
  for(int i=3; i<=7; i+=2){
    REP(j, 2){
      curd=(j&1 ? 0 : 2);
      REP(k, i+1){
        if(mp[curx][cury+dy[curd]*k]!=-1){
          ans+='I';
          st.push(mp[curx][cury+dy[curd]*k]);
        }
        if(k==i){
          ans+='D';
          ++curx;
          cury=cury+dy[curd]*k;
        }
        else{
          ans+=(dy[curd]>0 ? "R" : "L");
        }
      }
    }
  }
  // 下（右）
  REP(j, 3){
    curd=(j&1 ? 0 : 2);
    REP(k, w/2){
      if(mp[curx][cury+dy[curd]*k]!=-1){
        ans+='I';
        st.push(mp[curx][cury+dy[curd]*k]);
      }
      if(k==w/2-1){
        if(j==2){
          ans+='L';
          cury=cury+dy[curd]*(k+1);
        }
        else{
          ans+='D';
          ++curx;
          cury=cury+dy[curd]*k;
        }
      }
      else{
        ans+=(dy[curd]>0 ? "R" : "L");
      }
    }
  }
  // 下（左）
  REP(j, 2){
    curd=(j&1 ? 0 : 2);
    REP(k, w/2){
      if(mp[curx][cury+dy[curd]*k]!=-1){
        ans+='I';
        st.push(mp[curx][cury+dy[curd]*k]);
      }
      if(k==w/2-1){
        ans+='U';
        --curx;
        cury=cury+dy[curd]*k;
      }
      else{
        ans+=(dy[curd]>0 ? "R" : "L");
      }
    }
  }
  // 左下
  if(mp[curx][cury]!=-1){
    ans+='I';
    st.push(mp[curx][cury]);
  }
  ans+='L';
  --cury;
  for(int i=1; i<=7; i+=2){
    REP(j, 2){
      curd=(j&1 ? 1 : 3);
      REP(k, i+1){
        if(mp[curx+dx[curd]*k][cury]!=-1){
          ans+='I';
          st.push(mp[curx+dx[curd]*k][cury]);
        }
        if(k==i){
          ans+='L';
          --cury;
          curx=curx+dx[curd]*k;
        }
        else{
          ans+=(dx[curd]>0 ? "D" : "U");
        }
      }
    }
  }
  // 左
  REP(i, 7+1){
    if(mp[curx-i][cury]!=-1){
      ans+='I';
      st.push(mp[curx-i][cury]);
    }
    ans+='U';
  }
  curx-=8;
  // 左上
  for(int i=2; i<=6; i+=2){
    REP(j, 2){
      curd=(j&1 ? 2 : 0);
      REP(k, i+1){
        if(mp[curx][cury+dy[curd]*k]!=-1){
          ans+='I';
          st.push(mp[curx][cury+dy[curd]*k]);
        }
        if(k==i){
          ans+='U';
          --curx;
          cury=cury+dy[curd]*k;
        }
        else{
          ans+=(dy[curd]>0 ? "R" : "L");
        }
      }
    }
  }
  // 中央へ移動
  REP(i, 8+1){
    if(mp[curx][cury]!=-1){
      ans+='I';
      st.push(mp[curx][cury]);
    }
    ans+='R';
    ++cury;
  }

  // 2. 中央にカードを配置
  curd=0;
  for(int i=2; i<=12; i+=2){
    REP(j, i+1){
      if(inside(curx, cury+dy[curd]*j)){
        if(mp[curx][cury+dy[curd]*j]==-1){
          if(!st.empty()){
            int tmp=st.top();st.pop();
            mp[curx][cury+dy[curd]*j]=tmp;
            x[tmp]=curx;
            y[tmp]=cury+dy[curd]*j;
            ans+='O';
          }
        }
      }
      else{
        if(mp[curx][cury+dy[curd]*j]!=-1){
          st.push(mp[curx][cury+dy[curd]*j]);
          ans+='I';
        }
      }
      if(j==i){
        ++curx;
        cury+=dy[curd]*j;
        curd=(curd==0 ? 2 : 0);
        ans+='D';
      }
      else{
        ans+=(dy[curd]>0 ? 'R' : 'L');
      }
    }
  }
  REP(i, 2){
    curd=(i&1 ? 2 : 0);
    REP(j, 13+1){
      if(mp[curx][cury+dy[curd]*j]==-1){
        if(!st.empty()){
          int tmp=st.top();st.pop();
          mp[curx][cury+dy[curd]*j]=tmp;
          x[tmp]=curx;
          y[tmp]=cury+dy[curd]*j;
          ans+='O';
        }
      }
      if(j==13){
        ++curx;
        cury=cury+dy[curd]*j;
        ans+='D';
      }
      else{
        ans+=(dy[curd]>0 ? 'R' : 'L');
      }
    }
  }
  curd=0;
  for(int i=12; i>=2; i-=2){
    REP(j, i+1){
      if(inside(curx, cury+dy[curd]*j)){
        if(mp[curx][cury+dy[curd]*j]==-1){
          if(!st.empty()){
            int tmp=st.top();st.pop();
            mp[curx][cury+dy[curd]*j]=tmp;
            x[tmp]=curx;
            y[tmp]=cury+dy[curd]*j;
            ans+='O';
          }
        }
      }
      else{
        if(mp[curx][cury+dy[curd]*j]!=-1){
          st.push(mp[curx][cury+dy[curd]*j]);
          ans+='I';
        }
      }
      if(j==i){
        ++curx;
        cury+=dy[curd]*j;
        curd=(curd==0 ? 2 : 0);
        ans+='D';
      }
      else{
        ans+=(dy[curd]>0 ? 'R' : 'L');
      }
    }
  }
  // 念のためstackが空になるまでカードを置く
  while(!st.empty()){
    int tmp=st.top();st.pop();
    mp[curx][cury]=tmp;
    x[tmp]=curx;
    y[tmp]=cury;
    --cury;
    ans+='O';
    ans+='L';
  }

  // 3. カードを回収
  REP(i, n){
    while(curx<x[i]){
      ans+='D';
      ++curx;
    }
    while(curx>x[i]){
      ans+='U';
      --curx;
    }
    while(cury<y[i]){
      ans+='R';
      ++cury;
    }
    while(cury>y[i]){
      ans+='L';
      --cury;
    }
    ans+='I';
  }

  cout<<ans<<'\n';
  return 0;
}
