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
	
class EmoticonsDiv1 {
public:
	int printSmiles(int smiles);
};

const int base = 200000;

int u[2100][2100], d[2110][2110];
pair<int, int> q[base + 10];
int f, r;

int EmoticonsDiv1::printSmiles(int smiles) 
{
	memset(u, 0, sizeof(u));
	u[1][0] = 1, d[1][0] = 0;
	f = 0, r = 1;
	q[r] = make_pair(1, 0);
	
	int ans = 1 << 30;
	while (f != r)
	{
		f = (f + 1) % base;
		
		int x = q[f].first, y = q[f].second;
		if (x == smiles)
			ans = min(ans, d[x][y]);
		//copy
		if (! u[x][x])
		{
			u[x][x] = 1;
			r = (r + 1) % base;
			q[r] = make_pair(x, x);
			d[x][x] = d[x][y] + 1;
		}
		
		//paste
		if (x + y <= 2048 && ! u[x + y][y])
		{
			u[x + y][y] = 1;
			r = (r + 1) % base;
			q[r] = make_pair(x + y, y);
			d[x + y][y] = d[x][y] + 1;
		}
		
		//delete
		if (x && ! u[x - 1][y])
		{
			u[x - 1][y] = 1;
			r = (r + 1) % base;
			q[r] = make_pair(x - 1, y);
			d[x - 1][y] = d[x][y] + 1;
		}
	}
	return ans;
}
			


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	EmoticonsDiv1 *obj;
	int answer;
	obj = new EmoticonsDiv1();
	clock_t startTime = clock();
	answer = obj->printSmiles(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	
	{
	// ----- test 0 -----
	p0 = 2;
	p1 = 2;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 4;
	p1 = 4;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 6;
	p1 = 5;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 18;
	p1 = 8;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 11;
	p1 = 8;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
