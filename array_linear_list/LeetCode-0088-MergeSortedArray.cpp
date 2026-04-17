#include <iostream>
#include <vector>
using namespace std;

/*
* LeetCode 88 合并两个有序数组
* 解法1：辅助数组 + 正向双指针
* 思路：
* 1. 创建一个大小为 m+n 的辅助数组
* 2. 双指针分别从 nums1、nums2 头部开始，从小到大合并到辅助数组
* 3. 将辅助数组的结果覆盖回 nums1
*
* 时间复杂度：O(m + n)
* 空间复杂度：O(m + n)
*/
//class Solution
//{
//public:
//	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
//	{
//		int ptr1 = 0, ptr2 = 0;
//		int ptr = 0;
//		vector<int> nums(m + n);
//		while (ptr1 != m && ptr2 != n)
//		{
//			if (nums1[ptr1] <= nums2[ptr2])
//			{
//				nums[ptr] = nums1[ptr1];
//				ptr1++;
//				ptr++;
//			}
//			else
//			{
//				nums[ptr] = nums2[ptr2];
//				ptr2++;
//				ptr++;
//			}
//		}
//		if (ptr1 == m)
//		{
//			for (; ptr2 < n; ptr2++)
//			{
//				nums[ptr] = nums2[ptr2];
//				ptr++;
//			}
//		}
//		else
//		{
//			for (; ptr1 < m; ptr1++)
//			{
//				nums[ptr] = nums1[ptr1];
//				ptr++;
//			}
//		}
//		for (int i = 0; i < m + n; i++)
//		{
//			nums1[i] = nums[i];
//		}
//	}
//};

/*
* LeetCode 88 合并两个有序数组
* 解法2：从后往前双指针（最优解）
* 思路：
* 1. 题目要求合并到 nums1 且原地修改，从尾部填充避免元素覆盖
* 2. 三个指针：ptr1(nums1有效元素尾)、ptr2(nums2尾)、ptr(合并位置)
* 3. 比较两指针元素，将较大的放入当前位置，指针前移
* 4. 若 nums2 仍有剩余，直接复制到 nums1 头部
*
* 时间复杂度：O(m + n)
* 空间复杂度：O(1)
*/

class Solution
{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		int ptr1, ptr2, ptr;
		ptr1 = m - 1;
		ptr2 = n - 1;
		ptr = m + n - 1;
		
		// 从后往前比较，将较大元素放入目标位置
		while (ptr1 >= 0 && ptr2 >= 0)
		{
			if (nums1[ptr1] >= nums2[ptr2])
			{
				nums1[ptr] = nums1[ptr1];
				ptr1--;
				ptr--;
			}
			else
			{
				nums1[ptr] = nums2[ptr2];
				ptr2--;
				ptr--;
			}
		}
		
		// 处理 nums2 剩余元素
		while (ptr2 >= 0)
			nums1[ptr--] = nums2[ptr2--];
	}
};

int main()
{
	vector<int> nums1 = {1, 3, 5, 7, 7, 8, 11, 13};
	nums1.resize(14);
	vector<int> nums2 = {2, 3, 4, 5, 5, 10};
	
	Solution().merge(nums1, 8, nums2, 6);
	
	for (int i = 0; i < 14; i++)
	{
		cout << nums1[i] << " ";
	}
	cout << endl;
	
	return 0;
}
