#include <fstream>
#include <deque>
#include <iostream>
 
using namespace std;
 
ifstream in("vila2.in");
ofstream out("vila2.out");
 
#define rm_front(D) while(!D.empty() && D.front() < i-k+1)D.pop_front()
#define rm_back(D,op) while(!D.empty() && v[D.back()] op v[i])D.pop_back()
#define pb push_back
#define max(a,b) ((a>b) ? a : b)
deque<int> q,Q;
 
const int maxn = 100100;
short v[maxn];
int n,k;
int best = -(1<<30);
 
int main()
{
    in >> n >> k;++k;
    int i,dif;for(i=1;i<=n;++i){
            in >> v[i];
            rm_front(Q);
            rm_front(q);
            rm_back(Q,<=);
            rm_back(q,>=);
            Q.pb(i);
            q.pb(i);
            dif = v[Q.front()] - v[q.front()];
            best = max(best,dif);
    }
    out << best << "\n";
    return 0;
}
