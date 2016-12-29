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
	
class BuildingHeights {
public:
	int minimum(vector <int> heights);
};

vector<int> build[5050];

int BuildingHeights::minimum(vector <int> heights) 
{
	int N = heights.size();
	for (int i = 0; i < N; i ++)
	{
		build[i].clear();
		for (int j = 0; j < N; j ++)
			if (heights[j] <= heights[i])
				build[i].push_back(heights[i] - heights[j]);
		sort(build[i].begin(), build[i].end());
		for (int j = 1; j < build[i].size(); j ++)
			build[i][j] += build[i][j - 1];
	}
	
	int ans = 0;
	for (int M = 1; M <= N; M ++)
	{
		int cur = 1 << 30; 
		for (int i = 0; i < N; i ++)
			if (build[i].size() >= M && build[i][M - 1] < cur)
				cur = build[i][M - 1];
		ans ^= cur;
	}
	return ans;
}

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
