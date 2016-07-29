#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <cctype>
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

class SymbolFrequency {
public:
	double language(vector <string> frequencies, vector <string> text);
};

double SymbolFrequency::language(vector <string> frequencies, vector <string> texts)
{
	string text = "";
	for (string s : texts)
		text += s;
	int num_letter = 0;
	for (char c : text)
		if (isalpha(c))
			num_letter ++;
	unordered_map<char, int> text_freq;
	for (char c :text)
		text_freq[c] ++;

	double ans = 1e40;
	for (string freq_s : frequencies)
	{
		unordered_map<char, int> dict_freq;
		double diff = 0;
		for (int i = 0; i < freq_s.size() / 3; i ++)
			dict_freq[freq_s[i * 3]] = (freq_s[i * 3 + 1] - 48) * 10 + freq_s[i * 3 + 2] - 48;
		for (char c = 'a'; c <= 'z'; c ++)
			diff += sqr(dict_freq[c] / 100.0 * num_letter - text_freq[c]);
		ans = min(ans, diff);
	}
	return ans;
}


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
