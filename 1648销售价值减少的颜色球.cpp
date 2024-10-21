#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <ranges>
#include <algorithm>

using namespace std;

/*
你有一些球的库存 inventory ，里面包含着不同颜色的球。一个顾客想要 任意颜色 总数为 orders 的球。

这位顾客有一种特殊的方式衡量球的价值：每个球的价值是目前剩下的 同色球 的数目。
比方说还剩下 6 个黄球，那么顾客买第一个黄球的时候该黄球的价值为 6 。
这笔交易以后，只剩下 5 个黄球了，所以下一个黄球的价值为5 （也就是球的价值随着顾客购买同色球是递减的）

给你整数数组 inventory ，其中 inventory[i] 表示第 i 种颜色球一开始的数目。
同时给你整数 orders ，表示顾客总共想买的球数目。你可以按照 任意顺序 卖球。

请你返回卖了 orders 个球以后 最大 总价值之和。由于答案可能会很大，
请你返回答案对 109 + 7 取余数 的结果。
*/
const int mod = 1'000'000'007;

// 二分查找的思想
int maxProfit(vector<int>& inventory, int orders) {
    int n = inventory.size();

    // 判断大于limit的球数是否大于orders
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

    // 找到符合题意的最小边界
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        (check(mid) ? left : right) = mid;
    }

    long long res = 0;
    for (int x : inventory) {
        if (x > right) {
            // 等差数列求和
            res += (long long)((x + right + 1) * (x - right) / 2);
            orders -= (x - right);
        }
    }

    res += (long long)right * orders;
    res %= mod;

    return res;
}