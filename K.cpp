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

/* Haven't finished yet */

int n;
vector<ll> nums;

inline int num_of_digits(ll number) {
    int res = 0;
    while (number) {number /= 10, res++; }
    return res;
}

ll my_sum(ll a, ll b) {
    ll res = 0; 

    int base = 1, temp;
    while (a || b) { 
        temp = (a % 10) + (b % 10); 
        temp %= 10; 
        res += (temp * base);
        a /= 10; 
        b /= 10; 
        base *= 10; 
    } 
    return res; 
}

int main () {
    scanf("%d", &n);
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i) scanf("%d", &nums[i]);
    if (nums.size() == 2) {
        printf("%lld\n", my_sum(nums[0], nums[1]));
        return 0;
    }
    sort(nums.begin(), nums.end(), greater<ll>());

    int first = num_of_digits(nums[0]), second = num_of_digits(nums[1]), third = num_of_digits(nums[2]);
    if ((first != second && second != third) || (first == second && second != third)) {
        printf("%lld\n", my_sum(first, second));
        return 0;
    } else if () {
        // TODO
    }
    
    if (first > second) {
        int temp = pow(10, first);
        calc(first - temp);
    } else {
        auto it = nums.begin();
        for ( ; it != nums.end(); ++it) if (num_of_digits(*it) != first) break;
        nums.erase(it, nums.end());
    }
}