#include <fstream>
#include <string>

using namespace std;

typedef unsigned long long uLL;

const int MAX_N = 6000 + 1;

const uLL P = 666013;

uLL hsh[MAX_N];
uLL pwr[MAX_N];

string s;

int n, k;

void buildHash() {
    pwr[0] = 1;
    for(int i = 1; i <= n; ++i) {
        hsh[i] = hsh[i - 1] * P + s[i];
        pwr[i] = pwr[i - 1] * P;
    }
}

uLL range(const int i, const int j) {
    const uLL ret = hsh[j] - pwr[j - i + 1] * hsh[i - 1];
    return ret;
}

bool check(int i, int j) {
    const int D = j - i + 1;
    const int T = D / k;

    return range(i, j - T) == range(i + T, j);
}

int main() {
    ifstream in("per.in");
    in >> n >> k;
    in >> s;
    in.close();
    s = (char)(0) + s;

    buildHash();

    int cnt = 0;

    for(int i = 1; i <= n; ++i) {
        for(int j = i + k - 1; j <= n; j += k) {
            cnt += check(i, j);
        }
    }

    ofstream out("per.out");
    out << cnt << "\n";
    return 0;
}
