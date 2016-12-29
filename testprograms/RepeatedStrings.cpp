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


class RepeatedStrings {
public:
	string findKth(string s, int k)
	{
		rep.clear();
		tot = 0;
		dfs();

		sort(good_strings.begin(), good_strings.end());
		int pointer = 0;
		for (int i = 0; i < (int) good_strings.size(); i ++)
		{
			string cur = good_strings[i];
			int v = -1;
			for (int j = 0; j < (int) cur.size(); j ++)
			{
				v ++;
				while (v < s.size() && s[v] != cur[j])
					v ++;
				if (v == s.size())
					break;
			}
			if (v < s.size())
				pointer ++;
			if (pointer == k)
				return cur;
		}
		return "";
	}

private:
	const int maxl = 150;
	vector<int> rep;
	int tot;
	vector<string> good_strings;


	void dfs()
	{
		tot ++;
		string cur = "()";
		for (int i = 0; i < (int) rep.size(); i ++)
		{
			string x = cur;
			for (int j = 1; j < rep[i]; j ++)
				cur += x;
			cur = "(" + cur + ")";
		}
/*		for (int i = 0; i < (int) rep.size(); i ++)
			cout << rep[i] << " ";
		cout << endl;
		cout << cur.size() << " : " << cur << endl;
*/
		good_strings.push_back(cur);

		for (int i = 1; ; i ++)
		{
			rep.push_back(i);
			//
			int l = 0;
			for (int j = 0; j < (int) rep.size(); j ++)
			{
				int m = 1;
				for (int k = j; k < (int) rep.size(); k ++)
					m *= rep[k];
				l += m * 2;
			}
			if (l > maxl)
			{
				rep.pop_back();
				break;
			}
			dfs();
			rep.pop_back();
		}
	}
};
