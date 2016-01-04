#include <fstream>
#include <cstring>
using namespace std;
 
ifstream in("iepuri.in");
ofstream out("iepuri.out");
 
#define mod 666013
 
 
int mat[4][4];
int fin[4][4];
int X ,Y ,Z ,A, B, C, N;
 
 
void mat_mul(int a[4][4],const int b[4][4])
{
    int rez[4][4];
    memset(&rez[0][0],0,sizeof(rez));
    int i,j,k;
    for(i=1;i<=3;++i)
        for(j=1;j<=3;++j)
        {
            for(k=1;k<=3;++k)
                rez[i][j] = (1LL * rez[i][j] + 1LL * a[i][k] * b[k][j])%mod;
        }
    for(i=1;i<=3;++i)
        for(j=1;j<=3;++j)
            a[i][j] = rez[i][j];
}
 
void log_put(int put)
{
    for(;put;put>>=1)
    {
        if(put&1)
            mat_mul(fin,mat);
        mat_mul(mat,mat);
    }
}
void comp()
{
    memset(&fin[0][0],0,sizeof(fin));
    memset(&mat[0][0],0,sizeof(mat));
    mat[1][1] = X;
    mat[1][2] = Y;
    mat[1][3] = Z;
    mat[2][1] = 1;
    mat[3][2] = 1;
    fin[1][1]=1;
    fin[2][2]=1;
    fin[3][3]=1;
    log_put(N);
 
}
 
int main()
{
    int T;
    int i,j;
    in >> T;
    int show;
    while(T--)
    {
        in >> A >> B >> C;
        in >> X >> Y >> Z;
        in >> N;
        N-=2;
        comp();
        show = (1LL * fin[1][1] * C) % mod + (1LL * fin[1][2] * B) % mod + (1LL * fin[1][3] * A) % mod;
        show %= mod;
        out << show << "\n";
    }
    return 0;
}
