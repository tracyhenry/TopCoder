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
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class GridSortMax {
public:
	string findMax(int n, int m, vector <int> grid)
	{
		string ans = "";
		vector<vector<int>> a(n, vector<int>(m, 0));
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < m; j ++)
				a[i][j] = grid[i * m + j] - 1;

		vector<bool> row_fixed(n, false);
		vector<bool> col_fixed(m, false);
		int dx = 0, dy = 0;
		for (int v = 0; v < n * m; v ++)
		{
			int x = -1, y = -1;
			for (int i = 0; i < n; i ++)
				for (int j = 0; j < m; j ++)
					if (a[i][j] == v)
						x = i, y = j;

			bool swappable = true;
			if (x != dx && (row_fixed[x] || row_fixed[dx]))
				swappable = false;
			if (y != dy && (col_fixed[y] || col_fixed[dy]))
				swappable = false;

			if (swappable)
			{
				ans += "1";
				//swap
				if (x != dx)
					for (int j = 0; j < m; j ++)
						swap(a[x][j], a[dx][j]);
				row_fixed[dx] = true;

				if (y != dy)
					for (int i = 0; i < n; i ++)
						swap(a[i][y], a[i][dy]);
				col_fixed[dy] = true;
			}
			else
				ans += "0";

			//increment (dx, dy)
			dy ++;
			if (dy >= m)
				dx ++, dy = 0;
		}

		return ans;
	}
};
