#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>

using namespace std;

/*
给定一个长度为4的整数数组 cards 。你有 4 张卡片，每张卡片上都包含一个范围在[1, 9] 的数字。
您应该使用运算符['+', '-', '*', '/'] 和括号 '(' 和 ')' 
将这些卡片上的数字排列成数学表达式，以获得值24。

你须遵守以下规则 :
除法运算符 '/' 表示实数除法，而不是整数除法。
例如， 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12 。
每个运算都在两个数字之间。特别是，不能使用 “ - ” 作为一元运算符。
例如，如果 cards = [1, 1, 1, 1] ，则表达式 “ - 1 - 1 - 1 - 1” 是 不允许 的。
你不能把数字串在一起
例如，如果 cards = [1, 2, 1, 2] ，则表达式 “12 + 12” 无效。
如果可以得到这样的表达式，其计算结果为 24 ，则返回 true ，否则返回 false 。
*/

const double eps = 1e-6;
vector<double> cards;
const vector<char> operators = { '+', '-','*','/' };

bool dfs(vector<double>& cards) {
    int n = cards.size();
    if (n == 1) {
        return abs(cards[0] - 24) < eps;
    }

    // 从中挑选两个数字
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;

            // 生成除去 i 和 j 的新数组
            vector<double> newCards;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    newCards.push_back(cards[k]);
                }
            }

            for (int k = 0; k < 4; k++) {
                if ((k == 0 || k == 2) && i > j) {
                    // 对于加法和乘法，可以跳过交换顺序
                    continue;
                }
                switch (operators[k]) {
                case '+':
                    newCards.push_back(cards[i] + cards[j]);
                    break;
                case '-':
                    newCards.push_back(cards[i] - cards[j]);
                    break;
                case '*':
                    newCards.push_back(cards[i] * cards[j]);
                    break;
                case '/':
                    if (cards[j] == 0)
                        continue;
                    newCards.push_back(cards[i] / cards[j]);
                    break;
                }
                if (dfs(newCards))
                    return true;
                newCards.pop_back();
            }
        }
    }
    return false;
}

bool judgePoint24(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        cards.push_back(nums[i] * 1.0);
    }
    return dfs(cards);
}

//int main(){
//    vector<int> nums = {4,1,8,7};
//    cout << judgePoint24(nums) << endl;
//    return 0;
//}