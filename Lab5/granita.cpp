#include <fstream>
#include <algorithm>
using namespace std;
 
ifstream in("granita.in");
ofstream out("granita.out");
 
struct nod
{
    int A,B;
}v[16005];
 
struct comp
{
    inline bool operator () (const nod &x,const nod &y) const
    {
        if(x.A == y.A)
            return x.B > y.B;
        return x.A < y.A;
    }
};
 
int main()
{
    int i,n;
    in >> n;
    for(i=1;i<=n;++i)
        in >> v[i].A >> v[i].B;
    sort(v+1,v+n+1,comp());
    int lo,hi,useless=0;
    lo = v[1].A;
    hi = v[1].B;
    for(i=2;i<=n;++i)
    {
        if(lo < v[i].A && v[i].B < hi)
            ++useless;
        else
        {
            lo = v[i].A;
            hi = v[i].B;
        }
    }
    out << useless << "\n";
    return 0;
}
