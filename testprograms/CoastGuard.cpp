#include <vector>
#include <cstring>
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
#include <cmath>
#include <cstdlib>
#include <ctime>
#define LL long long

using namespace std;


class CoastGuard {
public:
	static const int mod = 1000000000 + 7;
	static const int N = 60;

	int count(vector <int> _d, vector <int> _x, vector <int> _y)
	{
		n = _d.size();
		d.resize(n);
		x.resize(n);
		y.resize(n);
		for (int i = 0; i < n; i ++)
		{
			d[i] = _d[i];
			x[i] = _x[i];
			y[i] = _y[i];
		}	
		sort(d.begin(), d.end());
			
		memset(f, 0, sizeof(f));
		memset(u, false, sizeof(u));
		dp(0, n - 1, n, n);

		return f[0][n - 1][n][n];
	}

	void dp(int l, int r, int lo, int hi)
	{
		if (u[l][r][lo][hi])
			return ;
		u[l][r][lo][hi] = true;

		int num_cannon = r - l + 1;
		int num_ship = 0;
		int highest = -1;
		int &o = f[l][r][lo][hi];
		for (int i = 0; i < n; i ++)
			if ((lo >= n || y[i] <= y[lo]) && (hi >= n || y[i] <= y[hi]))
			{
				if (i == lo || i == hi)
					continue;
				if (l > 0 && d[l - 1] >= (d[l - 1] - x[lo]) * y[i] / y[lo] + x[i])
					continue;
				if (r < n - 1 && (d[r + 1] - x[hi]) * y[i] / y[hi] + x[i] >= d[r + 1])
					continue;
				num_ship ++;
				if (highest == -1 || y[i] > y[highest])
					highest = i;
			}

		if (num_cannon != num_ship)
			return ;

		if (num_cannon == 1)
		{
			o = 1;
			return ;
		}

		//enumerate the match of the highest
		for (int k = l; k <= r; k ++)
		{
			int num_l = 1, num_r = 1;
			if (k > l)
			{
				dp(l, k - 1, lo, highest);
				num_l = f[l][k - 1][lo][highest];
			}
			if (k < r)
			{
				dp(k + 1, r, highest, hi);
				num_r = f[k + 1][r][highest][hi];
			}
			o += (int) (((LL) num_l * (LL) num_r) % (LL) mod);
			o %= mod;
		}
	}

private:
	vector<double> d, x, y;
	int n;
	int f[N][N][N][N];
	bool u[N][N][N][N];
};


//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
