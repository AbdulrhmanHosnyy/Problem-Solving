#include <iostream>
#include <cstring>
#include <set>
#include <deque>
#include <queue>
#include <vector>
#include <stack>
#include <math.h>
#include <map>

using namespace std;
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		map<int, int> e;
		for (int i = 0; i < s.size(); i++)
		{
			e[s[i]]++;
		}
		if (e.size() == 4 || e.size() == 3) cout << 4 << endl;
		else if (e.size() == 2)
		{
			bool flag = false;
			for (auto i : e)
			{
				if (i.second == 1) flag = true;
			}
			if (flag)
				cout << 6 << endl;
			else cout << 4 << endl;
		}
		else cout << -1 << endl;
	}
}

