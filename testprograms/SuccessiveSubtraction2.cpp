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
	
class SuccessiveSubtraction2 {
public:
	vector <int> calc(vector <int> a, vector <int> p, vector <int> v);
};

int a[2020];
int f[2020][2], g[2020][2];
int F[2020], G[2020];
const int inf = 1000000000;

vector <int> SuccessiveSubtraction2::calc(vector <int> a, vector <int> p, vector <int> v) 
{
	int n = a.size();
	vector<int> Ans; Ans.clear();

	for (int i = 0; i < p.size(); i ++)
	{
		a[p[i]] = v[i];
		
		if (n <= 2)
		{
			if (n == 2)
				Ans.push_back(a[0] - a[1]);
			else Ans.push_back(a[0]);
			continue;
		}
		
		//dp f
		for (int j = 2; j < n; j ++)
			f[j][0] = f[j][1] = -inf;
		
		f[2][0] = 0, f[2][1] = a[2];
		F[2] = max(f[2][0], f[2][1]);
		for (int j = 3; j < n; j ++)
		{
			f[j][0] = max(f[j - 1][0], f[j - 1][1]);
			f[j][1] = max(a[j], f[j - 1][1] + a[j]);
			F[j] = max(f[j][0], f[j][1]);
		}
		
		//dp g
		for (int j = n - 1; j > 1; j --)
			g[j][0] = g[j][1] = -inf;
		
		g[n - 1][0] = 0, g[n - 1][1] = a[n - 1];
		G[n - 1] = max(g[n - 1][0], g[n - 1][1]);
		for (int j = n - 2; j > 1; j --)
		{
			g[j][0] = max(g[j + 1][0], g[j + 1][1]);
			g[j][1] = max(a[j], g[j + 1][1] + a[j]);
			G[j] = max(g[j][0], g[j][1]);
		}
		
		int o = a[0] - a[1];
		for (int i = 2; i < n; i ++)
			o -= a[i];
		
		//0 pair
		int ans = o;

		//1 pair
		ans = max(ans, o + F[n - 1] * 2);
		
		//2 pair
		for (int i = 2; i < n; i ++)
			ans = max(ans, o + (F[i] + G[i + 1]) * 2);
		
		Ans.push_back(ans);
	}
	return Ans;
}
