#include <fstream>
#include <set>

using namespace std;

const int MAX_N = 1e6 + 1;

multiset<int> T;

int v[MAX_N];
int n, D;
int K;

template<typename T>
T abs(const T& x) {
    if(x < 0)
        return -x;
    else
        return x;
}


void check(const int &a, const int &b) {
    const int v = abs(a - b);
    if(v < K)
        K = v;
}

int main() {
    ifstream in("slidingwindow.in");
    in >> n >> D;
    for(int i = 1; i <= n; ++i)
        in >> v[i];
    in.close();

    K = abs(v[1] - v[2]);


    for(int i = 1; i <= n; ++i) {

        auto it = T.lower_bound(v[i]);
        if(it != T.end())
            check(v[i], *it);

        if(it != T.begin()) {
            it--;
            check(v[i], *it);
        }


        const int j = i - D;
        if(j >= 1)
            T.erase(T.find(v[j]));

        T.insert(v[i]);
    }


    ofstream out("slidingwindow.out");
    out << K << "\n";
    out.close();

    return 0;
}
