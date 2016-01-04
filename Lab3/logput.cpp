#include <iostream>
#include <fstream>
 
using namespace std;
 
long long unsigned int n;
 
#define modulo 1999999973
 
long long unsigned int power(int p)
{
    if(p == 1)
        return n;
    if(p == 0)
        return 1;
    if(p%2 == 0)
    {
        long long unsigned int a = power(p/2);
        a = a % modulo;
        return ((a*a)%modulo);
    }
    return ((n * power(p-1)) % modulo);
 
}
 
int main()
{
    long long unsigned int p;
    ifstream in("lgput.in");
    in >> n >> p;
    ofstream out("lgput.out");
    out << power(p) << "\n";
    return 0;
}
