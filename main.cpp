#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    in >> n;
    vector<long long int> seq(n);
    vector<long long int> lis;

    for (int i = 0; i < n; i++) {
        in >> seq[i];
    }

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), seq[i]);
        if (it == lis.end()) {
            lis.push_back(seq[i]);
        } else {
            *it = seq[i];
        }
    }

    int max_len = lis.size();

    out << max_len << endl;
    for(int i = 0; i < n; i++)
    {
        cout<<lis[i]<<" ";
    }

    return 0;
}
