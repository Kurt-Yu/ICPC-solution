#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric> 
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1e9 + 5;
typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////

map<char, map<double, int>> values;

int main(){
    string input;
    char name;
    double index;
    int value;
    char op;

    while (cin >> input) {
        name = input[0];
        index = stod(input.substr(2, input.find(']') - 2));
        for (int i = 0; i < 2; ++i) {
            cin >> input;
            if (i == 0) {
                continue;
            } else {
                value = stoi(input);
            }
        }

        auto search = values.find(name);
        if (search != values.end()) {
            auto search2 = (search->second).find(index);
            if (search2 != search->second.end()) {
                search2->second += value;
            } else {
                search->second.insert({index, value});
            }
        } else {
            map<double, int> temp;
            temp.insert({index, value});
            values.insert({name, temp});
        }
    }

    for (auto& name : values) {
        cout << name.first << endl;
        for (auto& val : values[name.first]) {
            if (val.second != 0) cout << val.second << endl;
        }
    }

}