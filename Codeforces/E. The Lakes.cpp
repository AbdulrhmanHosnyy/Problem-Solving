#include <iostream>
#include <cstring>
#include <set>
#include <deque>
#include <queue>
#include <vector>
#include <stack>
#include <math.h>
#include <map>
#include <algorithm>
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
//
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
//  Sieve theory:
//  ---------------
//vector<bool> Sieve(int n) // O(n * log(log(n))),Backward thinking
//{
//    vector<bool> isPrime(n + 1, true);
//    isPrime[0] = isPrime[1] = false;
//    for(int i = 2; i * i <= n; i++)
//    {
//        if(isPrime[i])
//        {
//            for(int j = i * 2; j <= n; j += i)
//                isPrime[j] = false;
//        }
//    }
//    return isPrime;
//}
//___________________________________________________________________________________________________________
//  Divisors of a number :
//  ------------------------
//vector<ll> DivisorsOfANumber(ll n)
//{
//    vector<ll> v;
//    for(ll i = 1 ;i * i <= n; i++) {
//        if (n % i == 0) {
//            v.push_back(i);
//            if ((i * i) != n)
//                v.push_back(ll(n / i));
//        }
//    }
//    return v;
//}
//  ___________________________________________________________________________________________________________
//  Perfect Square:
//  ---------------
//bool isPerfectSquare(long double x)
//{
//    if (x >= 0) {
//        long long sr = sqrt(x);
//        return (sr * sr == x);
//    }
//    return false;
//}
//  ___________________________________________________________________________________________________________
// GCD:
// ----
//int gcd(int a, int b)
//{
//  if (a == 0)
//    return b;
//  return gcd(b % a, a);
//}
//int findGCD(int arr[], int n)
//{
//  int result = arr[0];
//  for (int i = 1; i < n; i++)
//  {
//    result = gcd(arr[i], result);
//
//    if(result == 1)
//    {
//    return 1;
//    }
//  }
//  return result;
//}
// -----------------------------------------------------------------------------------------------------------
//
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
// 
//bool isPalindrome(string S)
//{
//    // Iterate over the range [0, N/2]
//    for (int i = 0; i < S.length() / 2; i++) {
//
//        // If S[i] is not equal to
//        // the S[N-i-1]
//        if (S[i] != S[S.length() - i - 1]) {
//            // Return No
//            return false;
//        }
//    }
//    // Return "Yes"
//    return true;
//}
//
//___________________________________________________________________________________________________________
//

//bool solvePerm(int* arr, int n)
//{
//    for (int i = 0; i < n; i++)
//    {
//        int sum = arr[i];
//        for (int j = i + 1; j < n; j++)
//        {
//            sum += arr[j];
//            if (sum % (j - i + 1) == 0) return false;
//        }
//    }
//    return true;
//}
//
//void permutations(int n)
//{
//    int *arr = new int[n];
//    for (int i = 0; i < n; i++) arr[i] = i + 1;
//   
//    do 
//    {
//        if(solvePerm(arr, n))
//        {
//            for (int i = 0; i < n; i++) cout << arr[i] << " ";
//            cout << "\n";
//        }
//    } while (next_permutation(arr, arr + n));
//}
//___________________________________________________________________________________________________________
//
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> v[i][j];
            }
        }
        set<pair<int, int>> e;
        ll maxi = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (e.find(make_pair(i, j)) == e.end() && v[i][j] != 0)
                {
                    stack<pair<int, int>> s;
                    s.push(make_pair(i, j));
                    e.insert(make_pair(i, j));
                    ll sum = 0;
                    while (!s.empty())
                    {
                        pair<int, int> p = s.top();
                        sum += v[p.first][p.second];
                        s.pop();
                        if (p.first - 1 >= 0 && v[p.first - 1][p.second] != 0 && e.find(make_pair(p.first - 1, p.second)) == e.end())
                        {
                            s.push(make_pair(p.first - 1, p.second));
                            e.insert(make_pair(p.first - 1, p.second));
                        }
                        if (p.first + 1 < n && v[p.first + 1][p.second] != 0 && e.find(make_pair(p.first + 1, p.second)) == e.end())
                        {
                            s.push(make_pair(p.first + 1, p.second));
                            e.insert(make_pair(p.first + 1, p.second));
                        }
                        if (p.second - 1 >= 0 && v[p.first][p.second - 1] != 0 && e.find(make_pair(p.first, p.second - 1)) == e.end())
                        {
                            s.push(make_pair(p.first, p.second - 1));
                            e.insert(make_pair(p.first, p.second - 1));
                        }
                        if (p.second + 1 < m && v[p.first][p.second + 1] != 0 && e.find(make_pair(p.first, p.second + 1)) == e.end())
                        {
                            s.push(make_pair(p.first, p.second + 1));
                            e.insert(make_pair(p.first, p.second + 1));
                        }
                    }
                    maxi = max(maxi, sum);
                }
            }
        }
        cout << maxi << endl;
        

    }
    return 0;
}
