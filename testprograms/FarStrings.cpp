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
	
class FarStrings {
public:
	vector <string> find(string t);
};

string opt[30][30][30];
int u[30][30][30];
char c[30];
int n;

void dp(int i, int j, int d)
{
	if (u[i][j][d]) return ;
	u[i][j][d] = 1;
	
	string &r = opt[i][j][d];
	r = "impossible";
	
	if (d == 0)
	{
		if (i != j)
			opt[i][j][d] = "impossible";
		else
		{
			opt[i][j][d] = "";
			for (int k = 1; k <= j; k ++)
				opt[i][j][d] += c[k];
		}
		return ;
	}
			
	if (i)
	{
		dp(i - 1, j, d - 1);
		if (opt[i - 1][j][d - 1] != "impossible")
			r = min(r, opt[i - 1][j][d - 1] + "a");
	}
	if (j)
	{
		dp(i, j - 1, d - 1);
		if (opt[i][j - 1][d - 1] != "impossible")
			r = min(r, opt[i][j - 1][d - 1]);
	}
	if (i && j)
	{
		dp(i - 1, j - 1, d - 1);
		dp(i - 1, j - 1, d);
		if (opt[i - 1][j - 1][d - 1] != "impossible")
		{
			char next = 'a';
			if (c[j] == 'a')
				next = 'b';
			r = min(r, opt[i - 1][j - 1][d - 1] + next);
		}
		if (opt[i - 1][j - 1][d] != "impossible")
			r = min(r, opt[i - 1][j - 1][d] + c[j]);
	}
}
		

vector <string> FarStrings::find(string t) 
{
	n = t.size();
	for (int i = 1; i <= n; i ++)
		c[i] = t[i - 1];
	
	memset(u, 0, sizeof(u));
	vector<string> ans;
	ans.clear();
	
	for (int i = 0; i < n; i ++)
	{
		dp(n, n, i + 1);
		ans.push_back(opt[n][n][i + 1]);
	}
	return ans;
}
	


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, vector <string> p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	FarStrings *obj;
	vector <string> answer;
	obj = new FarStrings();
	clock_t startTime = clock();
	answer = obj->find(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p1.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << "\"" << p1[i] << "\"";
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << answer[i] << "\"";
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p1.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p1[i]) {
					res = false;
				}
			}
		}
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	string p0;
	vector <string> p1;
	
	{
	// ----- test 0 -----
	p0 = "aaa";
	string t1[] = {"aab","abb","bbb"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING





//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!