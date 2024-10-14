#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <unordered_set>

using namespace std;

/*
给你一个字符串数组 ideas 表示在公司命名过程中使用的名字列表。公司命名流程如下：

从 ideas 中选择 2 个 不同 名字，称为 ideaA 和 ideaB 。
交换 ideaA 和 ideaB 的首字母。
如果得到的两个新名字 都 不在 ideas 中，那么 ideaA ideaB（串联 ideaA 和 ideaB ，中间用一个空格分隔）
是一个有效的公司名字。
否则，不是一个有效的名字。
返回 不同 且有效的公司名字的数目。
*/

long long distinctNames(vector<string>& ideas) {
	unordered_set<string> groups[26];
	for (auto& s : ideas) {
		groups[s[0] - 'a'].insert(s.substr(1));
	}
	long long res = 0;
	for (int a = 1; a < 26; a++) {
		for (int b = 0; b < a; b++) {
			int m = 0;
			for (auto& s : groups[a]) {
				m += groups[b].count(s);
			}
			res += (long long)(groups[a].size() - m) * (groups[b].size() - m) * 2;
		}
	}
	return res;
}