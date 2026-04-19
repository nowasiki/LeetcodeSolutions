#include <iostream>
#include <queue>
using namespace std;

/*
* LeetCode 225 用队列实现栈
* 方法1：单队列实现
* 核心思路：每次 push 新元素，将队列中原有元素全部移动到队尾
* 保证新元素永远在队首，满足栈 后进先出 LIFO
*/
class MyStack
{
public:
	queue<int> Q;

	// 构造函数
	MyStack()
	{

	}

	// 入栈：新元素插入后，旧元素全部绕一圈到队尾
	void push(int x)
	{
		int size = Q.size();
		Q.push(x);
		// 循环将之前的所有元素移到队尾
		for (int i = 0; i < size; i++)
		{
			Q.push(Q.front());
			Q.pop();
		}
	}

	// 出栈：直接取队首
	int pop()
	{
		int num = Q.front();
		Q.pop();
		return num;
	}

	// 获取栈顶元素
	int top()
	{
		return Q.front();
	}

	// 判断栈是否为空
	bool empty()
	{
		return Q.empty();
	}
};

/*
* 方法2：双队列实现（思路：一个存数据，一个临时搬运）
* 核心规则：
* 1. push：往非空队列添加元素（都空则用Q1）
* 2. pop：将数据队列除最后一个元素外，全部搬到空队列，弹出最后一个
* 3. top：与pop逻辑一致，只是最后将元素放回，不删除
* 4. empty：两个队列都为空则栈为空
*/

// 测试用例
int main()
{
	MyStack myStack;
	myStack.push(1);
	myStack.push(2);

	cout << myStack.top() << endl;   // 输出 2
	cout << myStack.pop() << endl;   // 输出 2
	cout << myStack.empty() << endl; // 输出 0（false）
}
