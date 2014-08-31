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
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))
using namespace std;

vector<int> getSplitNumbers(string s)
{
	for (int i = 0; i < s.size(); i ++)
		if (! isdigit(s[i])) s[i] = ' ';
	vector<int> ans;
	ans.clear();
	if (! s.size()) return ans;
	for ( ; ; )
	{
		int j = s.find(" ");
		if (j == string::npos)
		{
			ans.push_back(atoi(s.c_str()));
			return ans;
		}
		int x;
		sscanf(s.c_str(), "%d", &x);
		ans.push_back(x);
		s.erase(0, j + 1);
	}
	return ans;
}
	
class CompositeSmash {
public:
	string thePossible(int N, int target);
};

int can[1010100];

string CompositeSmash::thePossible(int N, int target) 
{
	memset(can, 0, sizeof(can));
	for (int i = 2; i <= N; i ++)
	{
		if (i == target)
		{
			can[i] = 1; continue;
		}
		int yes = 0, no = 0;
		for (int j = 2; j <= (int) sqrt(i); j ++)
			if (i % j == 0)
			{
				int x = j, y = i / j;
				if (! can[x] && ! can[y])
					no = 1;
				if (can[x] || can[y]) yes = 1;
			}
		if (no) can[i] = 0;
			else if (yes) can[i] = 1; else can[i] = 0;
	}
	if (can[N]) return "Yes"; else return "No";
}
	

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	CompositeSmash *obj;
	string answer;
	obj = new CompositeSmash();
	clock_t startTime = clock();
	answer = obj->thePossible(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	
	int p0;
	int p1;
	string p2;
	
	{
	// ----- test 0 -----
	p0 = 517;
	p1 = 47;
	p2 = "Yes";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 8;
	p1 = 4;
	p2 = "Yes";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 12;
	p1 = 6;
	p2 = "No";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 5;
	p1 = 8;
	p2 = "No";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 100000;
	p1 = 100000;
	p2 = "Yes";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 5858;
	p1 = 2;
	p2 = "Yes";
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = 81461;
	p1 = 2809;
	p2 = "No";
	all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 7 -----
	p0 = 65536;
	p1 = 256;
	p2 = "No";
	all_right = KawigiEdit_RunTest(7, p0, p1, true, p2) && all_right;
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
