#include <vector>
#include <map>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))
using namespace std;
	
class Byteland {
public:
	int CountDifferentMaps(int n, int k);
};

const int base = 1000000000 + 7;


pair<int, int> extend_Eulid(int a,int b)
 {
     if(b == 0)
     	return make_pair(1, 0);
     else
     {
         pair<int, int> cur = extend_Eulid(b, a % b);
         int x = cur.first, y = cur.second;
         int temp = x;
         x = y;
         y = temp - a / b * y;
         return make_pair(x, y);
     }
}

int Byteland::CountDifferentMaps(int n, int k)
{

//	C(n - 2, k - 1) / k ! * n !


	int Ans = 1;
	for (int i = 1; i <= k - 1; i ++)
		Ans = (int) ((LL) Ans * (LL) (extend_Eulid(i, base).first + base) % base % (LL) base);
	for (int i = n - 2 - (k - 1) + 1; i <= n - 2; i ++)
		Ans = (int) ((LL) Ans * (LL) i % (LL) base);
	for (int i = k + 1; i <= n; i ++)
		Ans = (int) ((LL) Ans * (LL) i % (LL) base);
	if (k == 1)
		Ans = (int) ((LL) Ans * (LL) (extend_Eulid(2, base).first + base) % (LL) base % (LL) base);
	else if (k == 2)
		Ans = (int) ((LL) Ans * (LL) (extend_Eulid(n - 2, base).first + base) % (LL) base % (LL) base);
	
	return Ans; 
}

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
