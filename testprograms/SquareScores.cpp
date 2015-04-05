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

double opt[1010][30], pro[1010][30];
char a[1010];
int n, m;

double SquareScores::calcexpectation(vector <int> p, string s) 
{
	int n = s.size();
	int m = p.size();
	for (int i = 1; i <= n; i ++)
		a[i] = s[i - 1];
	
	//pro
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j < m; j ++)
			if (a[i] == '?')
				pro[i][j] = p[j] / 100.0;
			else pro[i][j] = (a[i] == 97 + j ? 1.0 : 0.0);
	for (int j = 0; j < m; j ++)
		pro[0][j] = 1.0;

	double ans = 0;
	for (int i = 1; i <= n; i ++)
		for (int c = 0; c < m; c ++)
		{
			double pr = 1.0;
			for (int j = i; j <= n; j ++)
			{
				pr *= pro[j][c];
				ans += pr;
				if (pro[j][c] == 0)
					break;
			}
		}
	return ans;
}
