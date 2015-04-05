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
	
class SquareScores {
public:
	double calcexpectation(vector <int> p, string s);
};

double opt[2][1010][30];
double pro[2][1010][30];
char a[1010];
int n;

double SquareScores::calcexpectation(vector <int> p, string s) 
{
	int n = s.size();
	p.resize(26);
	
	for (int i = 1; i <= n; i ++)
		a[i] = s[i - 1];
	
	for (int i = 1; i <= n; i ++)
	{
		int cur = (i % 2);
		memset(opt[cur], 0, sizeof(opt[cur]));	
		memset(pro[cur], 0, sizeof(pro[cur]));

		for (int j = 1; j <= i; j ++)
			for (int c = 0; c < 26; c ++)
			{
				if (a[i] != '?' && a[i] != c + 97)
					continue;

				double w = (a[i] == '?' ? p[c] / 100.0 : 1.0);
				//p
				if (i == 1)
					pro[cur][j][c] = w;
				else if (j == 1)
				{
					for (int x = 0; x < i; x ++)
						for (int y = 0; y < 26; y ++)
							if (y != c)
								pro[cur][j][c] += pro[1 - cur][x][y] * w;
				}
				else
					pro[cur][j][c] = pro[1 - cur][j - 1][c] * w;
				
				//opt
				if (i == 1)
					opt[cur][j][c] = w;
				else if (j == 1)
				{
					for (int x = 0; x < i; x ++)
						for (int y = 0; y < 26; y ++)
							if (y != c)
								opt[cur][j][c] += (opt[1 - cur][x][y] + pro[1 - cur][x][y]) * w;
				}
				else 
					opt[cur][j][c] = (opt[1 - cur][j - 1][c] + j * pro[1 - cur][j - 1][c]) * w;
			}
	}

	double ans = 0.0;
	for (int j = 1; j <= n; j ++)
		for (int c = 0; c < 26; c ++)
			ans += opt[n % 2][j][c];
	return ans;
}
