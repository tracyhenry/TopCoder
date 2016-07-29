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
	
class LineMST {
public:
	int count(int N, int L);
};

const int base = 1000000000 + 7;

int F[300][300], sum[300][300];
int Pow[300][40000];

void makeSum(int x, int L)
{
	sum[x][0] = F[x][0];
	for (int i = 1; i <= L; i ++)
		sum[x][i] = (sum[x][i - 1] + F[x][i]) % base;
	return ;
}

int LineMST::count(int N, int L) 
{
	memset(F, 0, sizeof(F));
	memset(sum, 0, sizeof(sum));
	
	//make pow[][]
	for (int i = 1; i <= L; i ++)
		for (int j = 0; j <= N * (N - 1); j ++)
			Pow[i][j] = (! j ? 1 : (int) ((LL) Pow[i][j - 1] * (LL) i % (LL) base));

	//init F[][], sum[][]
	F[1][0] = 1; makeSum(1, L);
	for (int i = 1; i <= L; i ++)
		F[2][i] = 1;
	makeSum(2, L);

	for (int i = 3; i <= N; i ++)
	{
		for (int j = 1; j <= L; j ++)
		{
			for (int mid = 1; mid < i; mid ++)
			{
				int cost = Pow[L - j + 1][mid * (i - mid) - 1];
				cost = (int) ((LL) cost * (LL) sum[mid][j - 1] % (LL) base);
				cost = (int) ((LL) cost * (LL) sum[i - mid][j] % (LL) base);
				F[i][j] += cost;
				F[i][j] %= base;
			}
		}
		makeSum(i, L);
	}
	int ans = sum[N][L];
	for (int i = 3; i <= N; i ++)
		ans = (int) ((LL) ans * (LL) i % (LL) base);
	return ans;
}		
		


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	LineMST *obj;
	int answer;
	obj = new LineMST();
	clock_t startTime = clock();
	answer = obj->count(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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
	int p2;
	
	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 2;
	p2 = 15;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 2;
	p1 = 10;
	p2 = 10;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 3;
	p1 = 1;
	p2 = 3;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 8;
	p1 = 41;
	p2 = 655468587;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 200;
	p1 = 200;
	p2 = 152699064;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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