#include <iostream>
#include <string>
using namespace std;

/*
* LeetCode 1047 删除字符串中的所有相邻重复项
* 最优解法：string 模拟栈
* 不用 stack，直接用字符串本身实现栈操作
*/
class Solution
{
public:
	string removeDuplicates(string s)
	{
		string stk; // 用字符串模拟栈
		for (char c : s)
		{
			// 如果栈空 或 当前字符 != 栈顶 → 入栈
			if (stk.empty() || c != stk.back())
				stk.push_back(c);
			// 否则 → 重复，弹栈消除
			else
				stk.pop_back();
		}
		return stk; // 直接返回，不用拼接！
	}
};

int main()
{
	string str = "abbaca";
	cout << Solution().removeDuplicates(str);
}
