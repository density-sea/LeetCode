#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>

using namespace std;
/*
给你一个字符串 s 和两个整数 x 和 y 。你可以执行下面两种操作任意次。
删除子字符串 "ab" 并得到 x 分。
比方说，从 "cabxbae" 删除 ab ，得到 "cxbae" 。
删除子字符串"ba" 并得到 y 分。
比方说，从 "cabxbae" 删除 ba ，得到 "cabxe" 。
请返回对 s 字符串执行上面操作若干次能得到的最大得分。
*/
int maximumGain(string s, int x, int y) {
    int a_cnt = 0, b_cnt = 0;
    int right = 0;
    int n = s.size();
    int res = 0;
    // 统计当前的
    int cnt = 0;
    while (right < n) {
        char ch = s[right++];
        if (ch == 'b') b_cnt++;
        if (ch == 'a') a_cnt++;
        // 统计当前能够构成的x,y中较大值的字符序列个数cnt
        if ((ch == 'b' && a_cnt > 0 && x > y) || (ch == 'a' && b_cnt > 0 && x <= y)) {
            cnt++;
            a_cnt--;
            b_cnt--;
        }
        // 当前序列结束或是到达s的末尾
        if ((ch != 'a' && ch != 'b') || (right == n)) {
            int mn = min(b_cnt, a_cnt);
            res += y >= x ? cnt * y + mn * x : cnt * x + mn * y;
            a_cnt = 0;
            b_cnt = 0;
            cnt = 0;
        }
    }
    return res;
}