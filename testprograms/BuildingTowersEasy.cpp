#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))
using namespace std;
	
class BuildingTowersEasy {
public:
	int maxHeight(int N, vector <int> x, vector <int> t);
};

int a[100];
int BuildingTowersEasy::maxHeight(int N, vector <int> x, vector <int> t) 
{
	int n = x.size();
	if (n == 0)
		return N - 1;
	for (int i = n - 2; i >= 0; i --)
		if (t[i] > t[i + 1])
			t[i] = min(t[i], t[i + 1] + x[i + 1] - x[i]);
			
	int ans = 0;
	for (int i = 0; i < n; i ++)
	{
		int X = t[i] - (i ? a[i - 1] : 0);
		int Y = x[i] - (i ? x[i - 1] : 1);
		if (X == Y)
			a[i] = t[i];
		else if (X > Y)
			a[i] = Y + (i ? a[i - 1] : 0);
		else if (X < Y)
		{
			a[i] = t[i];
			ans = max(ans, X + (Y - X) / 2 + (i ? a[i - 1] : 0));
		}
		ans = max(ans, a[i]);
	}
	ans = max(ans, a[n - 1] + N - x[n - 1]);
	return ans;
}

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
