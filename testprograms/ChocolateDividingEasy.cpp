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
	
class ChocolateDividingEasy {
public:
	int findBest(vector <string> chocolate);
};

int a[100][100], s[100][100];
int n, m;

int ChocolateDividingEasy::findBest(vector <string> chocolate) 
{
	int n = chocolate.size();
	int m = chocolate[0].size();
	
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			a[i + 1][j + 1] = chocolate[i][j] - 48;
	
	memset(s, 0, sizeof(s));
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
	
	int ans = 0;
	for (int i = 1; i < n; i ++)
		for (int j = i + 1; j < n; j ++)
			for (int p = 1; p < m; p ++)
				for (int q = p + 1; q < m; q ++)
				{
					int Min = 1 << 30;
					for (int x = 0; x < 3; x ++)
						for (int y = 0; y < 3; y ++)
						{
							int l, r, u, d;
							if (x == 0)
								u = 1, d = i;
							else if (x == 1)
								u = i + 1, d = j;
							else 
								u = j + 1, d = n;
							
							if (y == 0)
								l = 1, r = p;
							else if (y == 1)
								l = p + 1, r = q;
							else 
								l = q + 1, r = m;
							
							Min = min(Min, s[d][r] - s[d][l - 1] - s[u - 1][r] + s[u - 1][l - 1]);
						}
					ans = max(ans, Min);
				}
	return ans;
}

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
