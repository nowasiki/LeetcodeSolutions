#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
* LeetCode 844 比较含退格的字符串
* 方法1：双栈模拟（基础简单版）
* 遇到字母入栈，遇到 # 弹栈（退格）
* 最后比较两个栈内容是否相同
* 空间复杂度 O(n)
*
* 方法2：原地修改 + 双指针（进阶最优版，下方代码就是这个）
* 不使用额外栈空间，直接在原字符串上覆盖
* 空间复杂度 O(1)
*/
class Solution {
public:
	bool backspaceCompare(string s, string t) {
		int sp, tp;
		int ins_sp = 0, ins_tp = 0;
		sp = 0;
		tp = 0;
		int sizeS = s.size();
		int sizeT = t.size();
		
		// 处理字符串s：遍历指针sp，有效字符写入位置ins_sp
		while (sp < sizeS)
		{
			if (ins_sp < 0) ins_sp = 0;
			if (s[sp] != '#')
			{
				s[ins_sp] = s[sp];
				ins_sp++;
			}
			else
				ins_sp--;	// 遇到退格，有效位置回退
			sp++;
		}
		
		// 处理字符串t：遍历指针tp，有效字符写入位置ins_tp
		while (tp < sizeT)
		{
			if (ins_tp < 0) ins_tp = 0;
			if (t[tp] != '#')
			{
				t[ins_tp] = t[tp];
				ins_tp++;
			}	
			else
				ins_tp--;	// 遇到退格，有效位置回退
			tp++;
		}
		
		// 长度不同直接不等；长度相同逐位比较
		if (ins_sp == ins_tp)
		{
			for (sp = 0; sp < ins_sp; sp++)
			{
				if (s[sp] != t[sp])
					return false;
			}
			return true;
		}
		else 
			return false;
	}
};

// 测试用例
int main()
{
	string s1 = "ab##";
	string s2 = "c#d#";
	bool ret = Solution().backspaceCompare(s1, s2);
	cout << ret << endl; // 输出 1（true）
}
