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

//  bool isprime3(ll n)    // O(sqrt(n))
//    {
//        if(n == 2) return true;
//        if(n < 2 || n % 2 == 0) return false;
//        for(int i = 3; i * i <= n; i += 2)
//            if(n % i == 0)
//                return false;
//        return true;
//    }
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
    std::cin.tie(nullptr);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        if(n % 2 == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            cout << "YES" << endl;
            vector<int> v(2 * n);
            for (int i = 1; i <= 2 * n; ++i) {
                v[i - 1] = i;
            }
            vector<int> v1;
            for (int i = 0; i < n / 2; ++i) {
                v1.push_back(v[i]);
                v1.push_back(v[(n / 2) + i + 1]);
            }
            v1.push_back(v[n / 2]);
            vector<int> v2;
            v2.push_back(v[n + (n / 2)]);
            for (int i = 0; i < n / 2; ++i) {
                v2.push_back(v[n + i]);
                v2.push_back(v[n + (n / 2) + i + 1]);
            }
            for (int i = 0; i < v2.size(); ++i) {
                cout << v1[i] << " " << v2[i] << endl;
            }
        }

    }

    return 0;
}

