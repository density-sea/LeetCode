#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>

using namespace std;

/*
给你一个下标从 0 开始的字符串 text 和另一个下标从 0 开始且长度为 2 的字符串 pattern ，
两者都只包含小写英文字母。

你可以在 text 中任意位置插入 一个 字符，这个插入的字符必须是 pattern[0] 或者 pattern[1] 。
注意，这个字符可以插入在 text 开头或者结尾的位置。

请你返回插入一个字符后，text 中最多包含多少个等于 pattern 的 子序列 。

子序列 指的是将一个字符串删除若干个字符后（也可以不删除），剩余字符保持原本顺序得到的字符串。
*/

// 可以注意到将pattern[0]插入到最左侧,将pattern[1]插入到最右侧,
// 此时得到的等于pattern的子序列最多。
long long maximumSubsequenceCount(string text, string pattern) {
    char x = pattern[0], y = pattern[1];
    int cntx = 0, cnty = 0;
    long long res = 0;
    for (char ch : text) {
        // 注意到没有单独判断x=y,故需要先更新答案,再更新cntx
        if (ch == y) {
            res += cntx;
            cnty++;
        }
        if (ch == x) {
            cntx++;
        }
    }
    return res + max(cntx, cnty);
}