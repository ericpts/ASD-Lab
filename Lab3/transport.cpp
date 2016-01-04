#include <fstream>
#include <vector>
#include <iostream>
 
using namespace std;
 
int n, k;
int sum;
 
vector<int> v;
 
bool good(int mx, int now, int k, int at){
 
    if(k <= 0)
        return false;
    if(at == n + 1)
        return true;
 
    if(now + v[at] <= mx)
        return good(mx, now + v[at], k, at + 1);
    else if(v[at] <= mx)
        return good(mx, v[at], k - 1, at + 1);
    else
        return false;
}
 
bool good(int wgt) {
    return good(wgt, 0, k, 1);
}
 
int bsearch() {
    int i, step;
    for(step = 1; step < sum; step *= 2);
    for(i = sum; step; step /= 2) {
        if(i - step >= 0 && good(i - step))
            i -= step;
    }
    return i;
}
 
int main() {
    ifstream in("transport.in");
    in >> n >> k;
 
    v.resize(n + 1);
 
 
    for(int i = 1; i <= n; ++i) {
        in >> v[i];
        sum += v[i];
    }
 
    ofstream out("transport.out");
 
    out << bsearch() << "\n";
 
    return 0;
}
