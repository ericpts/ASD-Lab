#include <vector>
#include <cstdio>
using namespace std;
 
const int mod = 666013;
 
vector <int> v [666013];
 
void adauga(int x)
{
    int i,a;
    a = x % mod;
    for(i=0;i< v[a].size();++i)
        if( v[a].at(i) == x )
            return ;
    v[a].push_back(x);
}
 
void sterge(int x)
{
    int i,a;
    a = x % mod;
    for(i=0;i<v[a].size();++i)
        if(v[a].at(i) == x)
        {
            v[a][i] = v[a][v[a].size()-1];
            v[a].pop_back();
            return ;
        }
}
 
bool query(int x)
{
    int i,a;
    a = x % mod;
    for(i=0;i<v[a].size();++i)
        if(v[a].at(i) == x)
            return 1;
    return 0;
}
 
int main()
{
    freopen("hashuri.in","r",stdin);
    freopen("hashuri.out","w",stdout);
    int n;
    int t,x;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&t,&x);
        if(t == 1)
            adauga(x);
        else if(t == 2)
            sterge(x);
        else
            printf("%d\n",query(x));
    }
    return 0;
}
