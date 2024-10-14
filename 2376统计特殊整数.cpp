#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

// 数位dp的思想
int countSpecialNumbers(int n) {
	string s = to_string(n);
	int m = s.size();
	vector<vector<int>> memo(m + 1, vector<int>(1 << 10, -1));
	// mask表示前面选过的数字集合
	// islimit表示前面的选择是否收到n的约束
	// isnum表示i之前的数位是否填写数字
	auto dfs = [&](auto&& dfs, int i, int mask,
		bool islimit, bool isnum) -> int {
			if (i == m) return isnum;
			if (!islimit && isnum && memo[i][mask] != -1) {
				return memo[i][mask];
			}
			int res = 0;
			// 跳过当前数位
			if (!isnum) {
				res = dfs(dfs, i + 1, mask, false, false);
			}
			int up = islimit ? s[i] - '0' : 9;
			// 若是前面跳过则当前数位必须从1开始
			for (int d = isnum ? 0 : 1; d <= up; d++) {
				// 当前数字未填写
				if ((mask >> d & 1) == 0) {
					res += dfs(dfs, i + 1, mask | (1 << d), islimit && d == up, true);
				}
			}
			// 记忆化搜索
			if (!islimit && isnum) {
				memo[i][mask] = res;
			}
			return res;
		};
	return dfs(dfs, 0, 0, true, false);
}
//int main() {
//	int n;
//	cin >> n;
//	cout << countSpecialNumbers(n) << endl;
//	return 0;
//}