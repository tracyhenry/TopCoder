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
#include <unordered_map>
#include <unordered_set>
#define LL long long
#define pi 3.1415926535897932384626433
#define sqr(a) ((a)*(a))
using namespace std;

class TroytownKeeper {
private:
	void dfs(int, int);
	vector<string> maze;
	vector<vector<bool>> visible;
	const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	int n, m;

public:
	int limeLiters(vector <string> maze);
};

void TroytownKeeper::dfs(int x, int y)
{
	if (visible[x][y]) return ;
	visible[x][y] = true;
	for (int D = 0; D < 4; D ++)
	{
		int nx = x + dir[D][0];
		int ny = y + dir[D][1];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == '.')
			dfs(nx, ny);
	}
}

int TroytownKeeper::limeLiters(vector <string> _maze)
{
	maze = _maze;
	n = maze.size();
	m = maze[0].size();

	visible.resize(n);
	for (int i = 0; i < n; i ++)
		visible[i].resize(m);

	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (maze[i][j] == '.')
				if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
					dfs(i, j);

	int ans = 0;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (maze[i][j] == '#')
				for (int D = 0; D < 4; D ++)
				{
					int ni = i + dir[D][0];
					int nj = j + dir[D][1];
					if (ni < 0 || ni >= n || nj < 0 || nj >= m || visible[ni][nj])
						ans ++;
				}
	return ans;
}


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
