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
	
class BuildingRoutes {
public:
	int build(vector <string> dist, int T);
};

int f[100][100], g[100][100];

int BuildingRoutes::build(vector <string> dist, int T) 
{
	int n = dist.size();
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			f[i][j] = g[i][j] = dist[i][j] - 48;
	
	//floyd
	for (int k = 0; k < n; k ++)
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++)
				if (k - i && k - j && i - j)
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	
	//
	int ans = 0;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			if (i - j)
			{
				int tot = 0;
				for (int x = 0; x < n; x ++)
					for (int y = 0; y < n; y ++)
						if (f[x][i] + g[i][j] + f[j][y] == f[x][y])
							tot ++;
				if (tot >= T)
					ans += g[i][j];
			}
	return ans;
}

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
