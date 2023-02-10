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
    int n; cin >> n;
    int k; cin >> k;
    queue<int> q1, q2;
    for (int i = 0; i < k; ++i) {
        int a; cin >> a;
        q1.push(a);
    }
    int k2; cin >> k2;
    for (int i = 0; i < k2; ++i) {
        int a; cin >> a;
        q2.push(a);
    }
    int count = 0;
    short helper = 0;
    while(!q1.empty() && !q2.empty())
    {
        if(q1.front() > q2.front())
        {
            int tmp = q1.front();
            q1.pop();
            q1.push(q2.front());
            q2.pop();
            q1.push(tmp);
            count++;
        }
        else
        {
            int tmp = q2.front();
            q2.pop();
            q2.push(q1.front());
            q1.pop();
            q2.push(tmp);
            count++;
        }
        if(q1.empty())
        {
            helper = 2;
            break;
        }
        if(q2.empty())
        {
            helper = 1;
            break;
        }
        if(count > 104)
        {
            break;
        }
    }
    if(helper != 0)
        cout << count << " " << helper;
    else cout << -1;
    return 0;
}

