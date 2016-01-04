#include <stdio.h>
#define mod 666013
 
using namespace std;
 
struct matrice
{
    public:
    long long unsigned int Z[2][2];
    matrice()
    {
        Z = {{0,1},{1,1}};
    }
    matrice(int a,int b,int c,int d)
    {
        Z = {{a,b},{c,d}};
    }
};
 
matrice Z;
 
inline matrice multiplication(matrice a,matrice b)
{
    matrice c;
    c.Z[0][0] = (a.Z[0][0] * b.Z[0][0] + a.Z[0][1] * b.Z[1][0]) %mod;
    c.Z[0][1] = (a.Z[0][0] * b.Z[0][1] + a.Z[0][1] * b.Z[1][1]) %mod;
    c.Z[1][0] = (a.Z[1][0] * b.Z[0][0] + a.Z[1][1] * b.Z[1][0]) %mod;
    c.Z[1][1] = (a.Z[1][0] * b.Z[0][1] + a.Z[1][1] * b.Z[1][1]) %mod;
    return c;
}
 
matrice pwr(int power)
{
    if(power == 1)
    {
        return Z;
    }
    if(power == 2)
    {
        return multiplication(Z,Z);
    }
    if(power % 2 == 0)
    {
        matrice A = pwr(power/2);
        return multiplication(A,A);
    }
    else
    {
        matrice A = pwr((power-1)/2);
        A = multiplication(A,A);
        return multiplication(A,Z);
    }
}
 
int main()
{
    long long unsigned int n;
    freopen("kfib.in","r",stdin);
    freopen("kfib.out","w",stdout);
    scanf("%d",&n);
    printf("%d",pwr(n).Z[1][0]);
    return 0;
}
