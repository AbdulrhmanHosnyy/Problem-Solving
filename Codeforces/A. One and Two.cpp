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
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        if(n % 2 == 0) cout << n / 2 << " " << n / 2 << endl;
        else if((n % 10) == 1) cout << n / 2 << " " << (n / 2) + 1 << endl;
        else
        {
            int num1 = 0, num2 = 0;
            bool flag = false;
            while(n > 0)
            {
                int tmp = n % 10;
                if(tmp % 2 == 0)
                {
                    num1 = num1 * 10 + (tmp / 2);
                    num2 = num2 * 10 + (tmp / 2);
                }
                else
                {
                    if(flag)
                    {
                        num1 = num1 * 10 + (tmp / 2);
                        num2 = num2 * 10 + (tmp / 2) + 1;
                    }
                    else
                    {
                        num1 = num1 * 10 + (tmp / 2) + 1;
                        num2 = num2 * 10 + (tmp / 2);
                    }
                    flag = !flag;
                }
                n /= 10;
            }
            int res1 = 0, res2 = 0;
            while(num1 > 0)
            {
                res1 = res1 * 10 + num1 % 10;
                num1 /= 10;
            }
            while(num2 > 0)
            {
                res2 = res2 * 10 + num2 % 10;
                num2 /= 10;
            }
            go:;
            cout << res1 << " " << res2 << endl;
        }
    }
    return 0;
}

