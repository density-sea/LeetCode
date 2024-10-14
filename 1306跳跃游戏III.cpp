#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>

using namespace std;

/* ��Ŀ����
������һ���Ǹ��������� arr�����ʼλ�ڸ��������ʼ�±� start ����
����λ���±� i ��ʱ����������� i + arr[i] ���� i - arr[i]��

�����ж��Լ��Ƿ��ܹ�������ӦԪ��ֵΪ 0 �� ��һ �±괦��

ע�⣬������ʲô����£��㶼�޷���������֮�⡣
*/

/*
ʾ�� 1��

���룺arr = [4, 2, 3, 0, 3, 1, 2], start = 5
�����true
���ͣ�
����ֵΪ 0 ���±� 3 �����¿��ܷ�����
�±� 5->�±� 4->�±� 1->�±� 3
�±� 5->�±� 6->�±� 4->�±� 1->�±� 3
ʾ�� 2��

���룺arr = [4, 2, 3, 0, 3, 1, 2], start = 0
�����true
���ͣ�
����ֵΪ 0 ���±� 3 �����¿��ܷ�����
�±� 0->�±� 4->�±� 1->�±� 3
ʾ�� 3��

���룺arr = [3, 0, 2, 1, 2], start = 2
�����false
���ͣ��޷�����ֵΪ 0 ���±� 1 ����
*/

// dfs��˼��
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

// bfs��˼��
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