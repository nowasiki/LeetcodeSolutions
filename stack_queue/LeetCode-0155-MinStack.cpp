#include <iostream>
#include <stack>
using namespace std;

/*
* LeetCode 155 最小栈
* 题目要求：push/pop/top/getMin 均为 O(1) 常数时间
* 解题思路：双栈法
* 1. 普通栈 S：存储所有原始数据
* 2. 最小栈 minS：同步保存历史最小值，栈顶永远是当前最小值
*/
class MinStack {
public:
	// 原始数据栈
	stack<int> S;
	// 最小栈：记录每一步最小值历史
	stack<int> minS;
	
	// 构造函数，栈默认空，无需初始化操作
	MinStack() {
		
	}
	
	// 元素入栈
	void push(int val) {
		// 原始栈正常入栈
		S.push(val);
		// 最小栈为空 或 新值更小/相等，同步入最小栈
		// 请注意，如果新的值和旧的最小值一样，那么也要入栈。因为一次出栈只会删掉一个元素，如果只存了一次那么实际上的最小值会变
		if (minS.empty() || minS.top() >= val)
		{
			minS.push(val);
		}
	}
	
	// 栈顶元素出栈
	void pop() {
		// 记录即将弹出的元素
		int val = S.top();
		// 原始栈弹出
		S.pop();
		// 如果弹出的是当前最小值，最小栈同步弹出
		if (val == minS.top())
			minS.pop();
		
	}
	
	// 获取栈顶元素
	int top() {
		return S.top();
	}
	
	// 常数时间获取最小值
	int getMin() {
		return minS.top();
	}
};

// 题目官方测试用例
int main()
{
	MinStack* obj = new MinStack();
	
	obj->push(-2);
	obj->push(0);
	obj->push(-3);
	
	cout << obj->getMin() << endl;   // 输出 -3
	
	obj->pop();
	cout << obj->top() << endl;      // 输出 0
	cout << obj->getMin() << endl;   // 输出 -2
	
	delete obj;
	return 0;
}
