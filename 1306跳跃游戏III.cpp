#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>

using namespace std;

/* 题目描述
这里有一个非负整数数组 arr，你最开始位于该数组的起始下标 start 处。
当你位于下标 i 处时，你可以跳到 i + arr[i] 或者 i - arr[i]。

请你判断自己是否能够跳到对应元素值为 0 的 任一 下标处。

注意，不管是什么情况下，你都无法跳到数组之外。
*/

/*
示例 1：

输入：arr = [4, 2, 3, 0, 3, 1, 2], start = 5
输出：true
解释：
到达值为 0 的下标 3 有以下可能方案：
下标 5->下标 4->下标 1->下标 3
下标 5->下标 6->下标 4->下标 1->下标 3
示例 2：

输入：arr = [4, 2, 3, 0, 3, 1, 2], start = 0
输出：true
解释：
到达值为 0 的下标 3 有以下可能方案：
下标 0->下标 4->下标 1->下标 3
示例 3：

输入：arr = [3, 0, 2, 1, 2], start = 2
输出：false
解释：无法到达值为 0 的下标 1 处。
*/

// dfs的思想
//bool canReach(vector<int>& arr, int start) {
//	int n = arr.size();
//	vector<bool> visited(n, false);
//	auto dfs = [&](auto && dfs,int idx) {
//		if (idx >= n || idx < 0) return false;
//		if (visited[idx]) return false;
//
//		if (arr[idx] == 0) return true;
//
//		visited[idx] = true;
//		return dfs(dfs, idx - arr[idx]) || dfs(dfs, idx + arr[idx]);
//	};
//	return dfs(dfs, start);
//}

// bfs的思想
bool canReach(vector<int>& arr, int start) {
	int n = arr.size();
	vector<bool> visited(n, false);
	queue<int> que;
	que.push(start);

	while (!que.empty()) {
		int idx = que.front();
		que.pop();

		if (idx >= n || idx < 0) continue;
	    if (visited[idx]) continue;
		
		if (arr[idx] == 0) return true;

		visited[idx] = true;

		que.push(idx + arr[idx]);
		que.push(idx - arr[idx]);
	}

	return false;
}

//int main() {
//	vector<int> arr = {3, 0, 3, 1, 2};
//	int start = 2;
//	cout << canReach(arr, start) << endl;
//
//	return 0;
//}