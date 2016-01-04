#include <algorithm>
#include <fstream>
#include <tr1/unordered_map>
using namespace std;
ifstream in("loto.in");
ofstream out("loto.out");
struct triplu
{
    int x,y,z;
};
tr1::unordered_map<int,triplu> hsh;
int main()
{
    int v[101],n,S;
    int i,j,k;
    triplu x;
    in >> n >> S;
    for(i=1;i<=n;++i)
        in >> v[i];
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            for(k=1;k<=n;++k)
            {
                hsh[v[i]+v[j]+v[k]] = (triplu){i,j,k};
                if(S - v[i]-v[j]-v[k] > 0)
                    if(hsh.count(S-v[i]-v[j]-v[k]))
                {
                    out << v[i] << " " << v[j] << " " << v[k] << " ";
                    x = hsh[S-v[i]-v[j]-v[k]];
                    out << v[x.x] << " " << v[x.y] << " " << v[x.z] << "\n";
                    return 0;
                }
            }
    out << "-1\n";
}
