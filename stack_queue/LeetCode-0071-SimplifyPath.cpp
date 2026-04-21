#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
* LeetCode 71 简化路径
* 方法：栈 模拟
* 时间、空间复杂度：O(n)
* 思路：
* 1. 按 '/' 分割路径，提取每一段目录名
* 2. 遇到 ".." 则返回上一级（弹栈）
* 3. 遇到 "." 或 空 则忽略
* 4. 正常目录名入栈
* 5. 最后将栈中元素拼接成规范路径
*/
class Solution {
public:
	stack<string> S;
	
	string simplifyPath(string path) {
		int i = 0, j;
		int n = path.size();
		string dir;
		
		// 遍历整个路径字符串
		while (i < n)
		{
			// 跳过所有连续的 '/'
			while (path[i] == '/' && i < n)
				i++;
			
			// 定位当前目录名的结束位置 j
			j = i;
			while (path[j] != '/' && j < n)
				j++;
			
			// 截取 i 到 j 之间的目录名
			dir = path.substr(i, j - i);
			
			// 处理目录
			if (dir == "..") {
				// 上级目录，栈不空则弹栈
				if (!S.empty())
					S.pop();
			} else if (dir != "" && dir != ".") {
				// 有效目录，入栈
				S.push(dir);
			}
			
			// 移动指针，处理下一段
			i = j;
		}
		
		// 拼接最终结果
		n = S.size();
		// 栈空，说明在根目录
		if (n == 0) {
			return "/";
		}
		
		path = "";
		// 从栈顶依次取出，拼接成规范路径
		for (i = 0; i < n; i++) {
			path = "/" + S.top() + path;
			S.pop();
		}
		
		return path;
	}
};

int main() {
	string str = "/.../a/../b/c/../d/./";
	string path = Solution().simplifyPath(str);
	cout << path;
}
