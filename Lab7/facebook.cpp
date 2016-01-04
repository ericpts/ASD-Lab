#include <cstdio>
#include <vector>
 
using namespace std;
unsigned v[(1<<17)+5];
unsigned fit[(1<<17)+5];
unsigned pos = 1;
const int mod = 666013;
struct c
{
    int n,ap;
};
vector<c> a[mod];
inline int min(int a,int b)
{
    if(a<b)
        return a;
    return b;
}
 
int n,k;
 
bool insert(int numar)
{
    int cop = numar;
    numar = numar % mod;
    vector<c> :: iterator it;
    for(it = a[numar].begin();it != a[numar].end();++it)
    {
        if(it -> n == cop)
        {
            ++(it -> ap);
            if(it -> ap == k)
                return 1;
            return 0;
        }
    }
    a[numar].push_back((c){cop,1});
    return 0;
}
 
unsigned int cost(int pr)
{
    int i = k+1;
    int j;
    for(j=1;j<=k;++j)
    {
        if(v[j] != pr)
        {
            while(v[i] != pr && i <= n)
                ++i;
            ++i;
        }
    }
    return (i-k-1);
}
int main()
{
    freopen("facebook.in","r",stdin);
    freopen("facebook.out","w",stdout);
    scanf("%d%d",&n,&k);
    int i;
    for(i=1;i<=n;++i)
    {
        scanf("%d",&v[i]);
        if(insert(v[i]))
        {
            fit[pos] = v[i];
            ++pos;
        }
    }
    if(pos == 1)
        printf("-1\n");
    else
    {
        unsigned m = 1<<30;
        for(i=1;i<pos;++i)
            m = min(m,cost(fit[i]));
        printf("%d\n",m);
    }
    return 0;
}
