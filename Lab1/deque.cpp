#include <fstream>
#include <deque>
using namespace std;
 
#define rm_front() while(!Q.empty() && Q.front() < i-k+1)Q.pop_front()
#define rm_back() while(!Q.empty() && v[i] <= v[Q.back()])Q.pop_back()
#define pb push_back
ifstream in("deque.in");
ofstream out("deque.out");
typedef long long LL;
const int maxn = 5000100;
int v[maxn];
LL S;
 
deque<int> Q;
 
 
 
int main(){
  int n,k,i;
  in >> n >> k;
  for(i = 1 ; i <= n ;++ i)
    in >> v[i];
  for(i = 1 ; i <= k ;++ i){
    rm_back();
    Q.pb(i);
  }
  S = v[Q.front()];
  for(; i <= n ; ++ i){
    rm_back();
    rm_front();
    Q.pb(i);
    S += v[Q.front()];
  }
  out << S << "\n";
}
