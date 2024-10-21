#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <ranges>
#include <algorithm>

using namespace std;

/*
����һЩ��Ŀ�� inventory ����������Ų�ͬ��ɫ����һ���˿���Ҫ ������ɫ ����Ϊ orders ����

��λ�˿���һ������ķ�ʽ������ļ�ֵ��ÿ����ļ�ֵ��Ŀǰʣ�µ� ͬɫ�� ����Ŀ��
�ȷ�˵��ʣ�� 6 ��������ô�˿����һ�������ʱ��û���ļ�ֵΪ 6 ��
��ʽ����Ժ�ֻʣ�� 5 �������ˣ�������һ������ļ�ֵΪ5 ��Ҳ������ļ�ֵ���Ź˿͹���ͬɫ���ǵݼ��ģ�

������������ inventory ������ inventory[i] ��ʾ�� i ����ɫ��һ��ʼ����Ŀ��
ͬʱ�������� orders ����ʾ�˿��ܹ����������Ŀ������԰��� ����˳�� ����

���㷵������ orders �����Ժ� ��� �ܼ�ֵ֮�͡����ڴ𰸿��ܻ�ܴ�
���㷵�ش𰸶� 109 + 7 ȡ���� �Ľ����
*/
const int mod = 1'000'000'007;

// ���ֲ��ҵ�˼��
int maxProfit(vector<int>& inventory, int orders) {
    int n = inventory.size();

    // �жϴ���limit�������Ƿ����orders
    auto check = [&](int limit) -> bool {
        int sum = 0;
        for (int x : inventory) {
            sum += max(x - limit, 0);
            if (sum > orders) return true;
        }
        return false;
    };

    int left = -1;
    int right = *max_element(inventory.begin(), inventory.end());

    // �ҵ������������С�߽�
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        (check(mid) ? left : right) = mid;
    }

    long long res = 0;
    for (int x : inventory) {
        if (x > right) {
            // �Ȳ��������
            res += (long long)((x + right + 1) * (x - right) / 2);
            orders -= (x - right);
        }
    }

    res += (long long)right * orders;
    res %= mod;

    return res;
}