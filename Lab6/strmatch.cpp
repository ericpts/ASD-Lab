#include <cstdio>
#include <cstring>
 
using namespace std;
 
#define maxn 2000005
 
#define p 73
#define mod1 660123
#define mod2 609137
 
char A[maxn];
char B[maxn];
 
int NA,NB;
 
int match[1015];
 
int main()
{
    freopen("strmatch.in","r",stdin);
    freopen("strmatch.out","w",stdout);
 
    int i;
    int p1=1,p2=1;
    scanf("%s %s",A,B);
 
    NA = strlen(A);
    NB = strlen(B);
 
    int hashA1 = 0;
    int hashA2 = 0;
 
    if(NA > NB)
    {
        printf("0\n");
        return 0;
    }
 
    for(i=0;i<NA;++i)
    {
        hashA1 = (hashA1 * p + A[i]) % mod1;
        hashA2 = (hashA2 * p + A[i]) % mod2;
 
        if(i)
        {
            p1 = (p1 * p) % mod1;
            p2 = (p2 * p) % mod2;
        }
    }
 
    int hash1=0,hash2=0;
 
    for(i=0;i<NA;++i)
    {
        hash1 = (hash1 * p + B[i]) % mod1;
        hash2 = (hash2 * p + B[i]) % mod2;
    }
 
    if(hash1 == hashA1 && hash2 == hashA2)
        match[++match[0]]=0;
 
    for(; i < NB;++i)
    {
        hash1 = hash1 - ((B[i-NA] * p1)%mod1);
        hash1 += mod1;
        hash1 *= p;
        hash1 += B[i];
        hash1 %= mod1;
 
        hash2 = hash2 - ((B[i-NA] * p2)%mod2);
        hash2 += mod2;
        hash2 *= p;
        hash2 += B[i];
        hash2 %= mod2;
 
 
        if(hash1 == hashA1 && hash2 == hashA2)
        {
            ++match[0];
            if(match[0] <= 1005)
                match[match[0]] = i - NA+1;
        }
    }
    printf("%d\n",match[0]);
 
    for(i=1;i <= match[0] && i <= 1000; ++ i)
        printf("%d ",match[i]);
 
    printf("\n");
    return 0;
}
