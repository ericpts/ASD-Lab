#include <cstdio>
#include <ctype.h>
#include <algorithm>
using namespace std;
#define maxn 500000
int n;
int v[maxn];
int main()
{
    freopen("algsort.in","r",stdin);
    freopen("algsort.out","w",stdout);
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;++i)
        scanf("%d",v+i);
    sort(v+1,v+n+1);
    for(i=1;i<=n;++i)
        printf("%d ",v[i]);printf("\n");
    return 0;
}
