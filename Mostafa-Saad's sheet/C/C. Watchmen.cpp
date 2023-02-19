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
long long findManhattanEuclidPair(pair<int, int> arr[], int n)
{
    // To store frequency of all distinct Xi
    map<int, int> X;

    // To store Frequency of all distinct Yi
    map<int, int> Y;

    // To store Frequency of all distinct
    // points (Xi, Yi);
    map<pair<int, int>, int> XY;

    for (int i = 0; i < n; i++) {
        int xi = arr[i].first;
        int yi = arr[i].second;

        // Hash xi coordinate
        X[xi]++;

        // Hash yi coordinate
        Y[yi]++;

        // Hash the point (xi, yi)
        XY[arr[i]]++;
    }

    long long xAns = 0, yAns = 0, xyAns = 0;

    // find pairs with same Xi
    for (auto xCoordinatePair : X) {
        long long xFrequency = xCoordinatePair.second;

        // calculate ((xFrequency) C2)
        long long sameXPairs
                = (xFrequency * (xFrequency - 1)) / 2;
        xAns += sameXPairs;
    }

    // find pairs with same Yi
    for (auto yCoordinatePair : Y) {
        long long yFrequency = yCoordinatePair.second;

        // calculate ((yFrequency) C2)
        long long sameYPairs
                = (yFrequency * (yFrequency - 1)) / 2;
        yAns += sameYPairs;
    }

    // find pairs with same (Xi, Yi)
    for (auto XYPair : XY) {
        long long xyFrequency = XYPair.second;

        // calculate ((xyFrequency) C2)
        long long samePointPairs
                = (xyFrequency * (xyFrequency - 1)) / 2;
        xyAns += samePointPairs;
    }

    return (xAns + yAns - (xyAns));
    /*    we are subtracting 2 * xyAns because we have counted
       let say A,B coinciding points two times in xAns and
       yAns which should not be add to the final answer so
       we are subtracting xyAns 2 times. */
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; cin >> n;
    pair<int, int> arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    cout << findManhattanEuclidPair(arr, n);
    return 0;
}

