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
	
class BearPasswordLexic {
private:
	string encode(unordered_map<int, int>, int);
public:
	string findPassword(vector <int> x);
};

string BearPasswordLexic::encode(unordered_map<int, int> m, int max_len)
{
	string ans = "";
	for (int i = 1; i <= max_len; i ++)
		if (m.count(i) && m[i])
			ans += to_string(i) + "#" + to_string(m[i]) + "#";
	return ans;
}

string BearPasswordLexic::findPassword(vector <int> x) 
{
	int N = x.size();
	int half_n = N / 2 + N % 2;

	//build hash map
	unordered_map<string, int> M[2][51];
	vector<int> a(half_n + 1);
	for (int s = 0; s < (1 << half_n) - 1; s ++)
	{
		//extract bits
		for (int j = 1; j <= half_n; j ++)
			a[j] = ((s & (1 << (half_n - j))) ? 1 : 0);
		//calculate map
		int cur = -1, tot = 0;
		unordered_map<int, int> cur_map;
		for (int j = 1; j <= half_n; j ++)
		{
			if (a[j] == cur)
				tot ++;
			else
				cur = a[j], tot = 1;
			for (int k = 1; k <= tot; k ++)
				cur_map[k] ++;
		}
		//insert
		string hash_map = encode(cur_map, half_n);
		int first = a[1];
		int strike = 1;
		for (int j = 2; j <= half_n; j ++)
			if (a[j] == first)
				strike ++;
			else
				break;
		if (! M[first][strike].count(hash_map) ||
			s < M[first][strike][hash_map])
			M[first][strike][hash_map] = s;
	}
	
	//answer
	LL ans = 1LL << 60LL;
	int new_half_n = N / 2;
	for (int s = 0; s < (1 << new_half_n) - 1; s ++)
	{
		//extract bits
		for (int j = 1; j <= new_half_n; j ++)
			a[j] = ((s & (1 << (new_half_n - j))) ? 1 : 0);
		//make map
		int cur = -1, tot = 0;
		unordered_map<int, int> cur_map;
		for (int j = 1; j <= new_half_n; j ++)
		{
			if (a[j] == cur)
				tot ++;
			else
				cur = a[j], tot = 1;
			for (int k = 1; k <= tot; k ++)
				cur_map[k] ++;
		}
		//early termination
		bool terminate = false;
		for (int i = 1; i <= new_half_n; i ++)
			if (cur_map[i] > x[i - 1])
				terminate = true;
		if (terminate)
			continue;
		//calculate strike
		int last = a[new_half_n];
		int strike = 1;
		for (int j = new_half_n - 1; j >= 1; j --)
			if (a[j] == last)
				strike ++;
			else
				break;
		//enumerate
		for (int first = 0; first < 2; first ++)
			for (int _strike = 1; _strike <= half_n; _strike ++)
			{
				unordered_map<int, int> expected = cur_map;
				int min_strike = min(strike, _strike);
				int max_strike = max(strike, _strike);
				//middle
				if (first == last)
					for (int len = 2; len <= strike + _strike; len ++)
					{
						int st = max(1, len - max_strike);
						int en = min(min_strike, len - 1);
						expected[len] += en - st + 1;
					}
				//update
				for (int len = 1; len <= N; len ++)
					expected[len] = x[len - 1] - expected[len];
				//check
				string hash_map = encode(expected, N);
				if (s == 0 && first == 0 && _strike == 2)
					cout << hash_map << " " << M[first][_strike].count(hash_map) << endl;
				if (M[first][_strike].count(hash_map))
					ans = min(ans, ((LL) s << half_n) + M[first][_strike][hash_map]);
			}
	}
	string ans_string = "";
	if (ans > (1LL << 50LL))
		return ans_string;
	for (int i = 1; i <= N; i ++)
		if (ans & (1 << (N - i)))
			ans_string += "b";
		else 
			ans_string += "a";
	return ans_string;
}



//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
