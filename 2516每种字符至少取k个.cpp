#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <unordered_set>

using namespace std;

/*
给你一个由字符 'a'、'b'、'c' 组成的字符串 s 和一个非负整数 k 。
每分钟，你可以选择取走 s 最左侧 还是 最右侧 的那个字符。
你必须取走每种字符 至少 k 个，返回需要的 最少 分钟数；如果无法取到，则返回 - 1 。
*/

// 滑动窗口的思想
// 逆思维,求解左侧和右侧至少有k个字符等价于求中间连续的字符串至多有a-k,b-k,c-k的最大分钟数，
// 进一步可以考虑记录字符串的每个字符出现的字符数,窗口内的表示移除的字符，最后统计移除字符的最大分钟数。
int takeCharacters(string s, int k) {
    int n = s.size();
    vector<int> map(3);
    // int map[3];
    // 统计a,b,c每个字符出现的次数
    for (auto ch : s) {
        map[ch - 'a']++;
    }
    if (map[0] < k || map[1] < k || map[2] < k) {
        return -1;
    }
    int mx = 0;
    int left = 0, right = 0;
    while (right < n) {
        map[s[right] - 'a']--;
        // 收缩窗口
        while (map[s[right] - 'a'] < k) {
            map[s[left] - 'a']++;
            left++;
        }
        mx = max(mx, right - left + 1);
        // 扩大窗口
        right++;
    }
    return n - mx;
}