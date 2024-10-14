#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>

using namespace std;

/*
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，
原地 对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
必须在不使用库内置的 sort 函数的情况下解决这个问题。

示例 1：
输入：nums = [2, 0, 2, 1, 1, 0]
输出：[0, 0, 1, 1, 2, 2]
示例 2：
输入：nums = [2, 0, 1]
输出：[0, 1, 2]
*/

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int zero = 0, two = n - 1;
    int i = 0;
    // [0, zero] = 0
    // (zero, i) = 1
    // [two, n - 1] = 2
    while (i <= two) {
        if (nums[i] == 0) {
            swap(nums[zero++], nums[i]);
            i++;
        }
        else if (nums[i] == 1) {
            i++;
        }
        else {
            swap(nums[i], nums[two--]);
        }
    }
}