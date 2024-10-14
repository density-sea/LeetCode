#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

// ��λdp��˼��
int countSpecialNumbers(int n) {
	string s = to_string(n);
	int m = s.size();
	vector<vector<int>> memo(m + 1, vector<int>(1 << 10, -1));
	// mask��ʾǰ��ѡ�������ּ���
	// islimit��ʾǰ���ѡ���Ƿ��յ�n��Լ��
	// isnum��ʾi֮ǰ����λ�Ƿ���д����
	auto dfs = [&](auto&& dfs, int i, int mask,
		bool islimit, bool isnum) -> int {
			if (i == m) return isnum;
			if (!islimit && isnum && memo[i][mask] != -1) {
				return memo[i][mask];
			}
			int res = 0;
			// ������ǰ��λ
			if (!isnum) {
				res = dfs(dfs, i + 1, mask, false, false);
			}
			int up = islimit ? s[i] - '0' : 9;
			// ����ǰ��������ǰ��λ�����1��ʼ
			for (int d = isnum ? 0 : 1; d <= up; d++) {
				// ��ǰ����δ��д
				if ((mask >> d & 1) == 0) {
					res += dfs(dfs, i + 1, mask | (1 << d), islimit && d == up, true);
				}
			}
			// ���仯����
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