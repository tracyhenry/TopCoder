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
	
class TheArray {
public:
	int find(int n, int d, int first, int last);
};

int TheArray::find(int n, int d, int first, int last) 
{
	int cur = first, ans = max(first, last);
	for (int i = 2; i <= n - 1; i ++)
	{
		cur += d;
		if (fabs(cur - last) <= (n - i) * d) continue;
		cur -= d;
		break;
	}
	ans = max(ans, cur);
	cur = last;
	for (int i = n - 1; i >= 2; i --)
	{
		cur += d;
		if (fabs(cur - first) <= (i - 1) * d) continue;
		cur -= d;
		break;
	}
	ans = max(ans, cur);
	return ans;
}
	







// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
	cout << "]" << endl;
	TheArray *obj;
	int answer;
	obj = new TheArray();
	clock_t startTime = clock();
	answer = obj->find(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	int p2;
	int p3;
	int p4;
	
	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 5;
	p2 = 2;
	p3 = 4;
	p4 = 7;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 10;
	p1 = 100;
	p2 = 999;
	p3 = 100;
	p4 = 999;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 1000000;
	p1 = 0;
	p2 = 474;
	p3 = 474;
	p4 = 474;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 97;
	p1 = 53;
	p2 = -92;
	p3 = 441;
	p4 = 2717;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 99;
	p1 = 3;
	p2 = -743;
	p3 = -619;
	p4 = -535;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
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
