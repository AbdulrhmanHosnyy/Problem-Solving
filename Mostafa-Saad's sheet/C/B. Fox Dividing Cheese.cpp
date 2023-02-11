#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
//___________________________________________________________________________________________________________
// Pair helper:
//__________________

//static bool compare(pair<int, int>& a,pair<int, int>& b)
//{
//    return a.second > b.second;
//}
//___________________________________________________________________________________________________________
// int128 functions:
//__________________

//__int128 read() {
//    __int128 x = 0, f = 1;
//    char ch = getchar();
//    while (ch < '0' || ch > '9') {
//        if (ch == '-') f = -1;
//        ch = getchar();
//    }
//    while (ch >= '0' && ch <= '9') {
//        x = x * 10 + ch - '0';
//        ch = getchar();
//    }
//    return x * f;
//}

//void print(__int128 x) {
//    if (x < 0) {
//        putchar('-');
//        x = -x;
//    }
//    if (x > 9) print(x / 10);
//    putchar(x % 10 + '0');
//}

//bool cmp(__int128 x, __int128 y) { return x > y; }

//___________________________________________________________________________________________________________

// Sum functions:
//__________________

//ll sum(ll n)
//{
//    return n * (n + 1) / 2;
//}

//ll sum_square(ll n)
//{
//    return n * (n - 1) * (2 * n - 1) / 6;
//}

//___________________________________________________________________________________________________________

//Prime numbers:
//_______________
bool isprime3(ll n)    // O(sqrt(n))
{
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}
//___________________________________________________________________________________________________________

// NOTES:
//__________________

// To get ceil (n + k - 1) / k;

// ^ to flip bit

// to sort priority queue in ascending order :
//  -->    priority_queue<int, vector<int>, greater<int> >q;
// to sort map in reverse
//  -->    map<int, int, greater<int>>
//___________________________________________________________________________________________________________

// Global:
//__________________

//ll mod= 1e9 + 7;
//___________________________________________________________________________________________________________

int main() {
    std::ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    if(a == b)
    {
        cout << 0;
        return 0;
    }
    bool flag = false;
    vector<int> v1(3, 0), v2(3, 0);
    while (a) {
        if (!(a % 2)) v1[0]++, a /= 2;
        else if (!(a % 3)) v1[1]++, a /= 3;
        else if (!(a % 5)) v1[2]++, a /= 5;
        else break;
    }
    while (b > 1) {
        if (!(b % 2)) v2[0]++,b /= 2;
        else if (!(b % 3)) v2[1]++, b /= 3;
        else if (!(b % 5)) v2[2]++, b /= 5;
        else break;
    }
    if(a != b) cout << -1;
    else
        cout << abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]) + abs(v1[2] - v2[2]);
    return 0;
}

