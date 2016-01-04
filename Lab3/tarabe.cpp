#include <fstream>
#include <algorithm>
 
#define maxn 200005
 
using namespace std;
 
ifstream in("tarabe.in");
ofstream out("tarabe.out");
#define IA
#ifndef IA
#include <iostream>
#define out cout
#endif
typedef long long LL;
int good[maxn];
int bad[maxn];
int n,k;
int i = 1;
LL fnd,S,x;
bool prod(long long cost,bool add)
{
    int i;
    fnd = 0;
    for(i=1;i<=n;++i)
    {
        if(cost >= good[i])
        {
            x = ((cost - good[i]) / bad[i]) + 1;
            fnd += x;
            if(add)
                S += x * good[i] + (x * (x-1) / 2) * bad[i];
        }
    }
    return fnd >= k;
}
 
long long bs()
{
    long long step = 1LL;
    while(!prod(step,0))
        step <<= 1;
    long long i;
 
    for(i=step;step;step>>=1LL)
    {
        if(i - step >= 1 && prod(i-step,0))
            i -= step;
    }
    return i;
}
 
void read()
{
    int i;
    in >> n >> k;
    for(i=1;i<=n;++i)
        in >> bad[i] >> good[i];
}
 
int main()
{
    read();
 
    long long best;
    best = bs();
    prod(best,1);
    if(fnd > k)
        S -= best * (fnd - k);
    out << S << "\n";
}
