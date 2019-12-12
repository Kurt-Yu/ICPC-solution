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


/*
    Doesn't work
*/
int n, a, b;
const int N = (1 << 17) + 5;

vector<int> edges[N];
bool seen[N];

unordered_map<int, int> in_degree;
// unordered_map<int, int> occur;


void dfs(int u) {
    if (seen[u]) return;
    seen[u] = true;
    for (int v : edges[u]) dfs(v);
}

int main() {
    cin >> n;
    for (int i = 0; i < (1 << n) - 1; ++i) {
        cin >> a >> b;
        edges[a].push_back(b);
        in_degree[b]++;
    }

    fill(seen, seen + N, false);
    int once = 0;
    for (int i = 1; i <= (1 << n); ++i) if (in_degree[i] == 0) {
        once = i;
        break;
    }

    dfs(once);
    cout << "once: " << once << endl;

    for (int i = 1; i <= (1 << n); ++i) {
        if (!seen[i]) {
            printf("MISTAKE\n");
            cout << "i: " << i << endl;
            return 0;
        }
    }
    printf("OK\n");
    return 0;
    
    // for (auto& f : freq) {
    //     occur[f.second]++;  // 1 : 4, 2: 2, 3 : 2
    // }

    // for (auto& o : occur) {
    //     if (o.first == n) {
    //         if (o.second != 2) {
    //             printf("MISTAKE\n");
    //             return 0;
    //         }
    //     } else {
    //         if ((1 << (n - o.first)) != o.second) {
    //             printf("MISTAKE\n");
    //             return 0;
    //         }
    //     }
    // }

}