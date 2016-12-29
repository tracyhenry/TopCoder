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
	
class CircuitsConstruction {
public:
	int maximizeResistance(string circuit, vector <int> conductors);
};

vector<int> st; 

int CircuitsConstruction::maximizeResistance(string circuit, vector <int> conductors) 
{
	st.clear();
	
	for (int i = circuit.size() - 1; i >= 0; i --)
		if (circuit[i] == 'X')
			st.push_back(1);
		else if (circuit[i] == 'A')
		{
			int a = st[st.size() - 1];
			int b = st[st.size() - 2];
			st.pop_back();
			st[st.size() - 1] = a + b;
		}
		else 
		{
			int a = st[st.size() - 1];
			int b = st[st.size() - 2];
			st.pop_back();
			st[st.size() - 1] = max(a, b);
		}
	
	for (int i = 0; i < conductors.size(); i ++)
		conductors[i] *= -1;
	sort(conductors.begin(), conductors.end());
	
	int ans = 0;
	for (int i = 0; i < st[0]; i ++)
		ans = ans - conductors[i];
	return ans;
}
		
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
