/* 栈混洗是堆栈的一个非常常用的功能，
对于输入序列1, 2, …, n：
1. 1…n的任一排列a1,a2,…,an是否为合法的出栈序列？这被称为栈混洗的甄别问题
2. 有多少种可能的出栈序列？这被称为栈混洗的总数问题 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Stack_shuffle {
public:
	int n;	//入栈序列1，2，...，n

	bool screening_violent(vector<int> poped) {		//(暴力算法)甄别poped序列是否是一个合法的出栈序列
		/* 在出栈序列当中，一定不会存在一种情况：
		...Ai...Aj...Ak.... , Ai > Ak > Aj , 这是一种禁序，
		一旦出现了这种禁序，出栈序列就是非法的 */

		/* 暴力算法就是通过遍历的方式判断出栈序列当中是否存在禁序 */
		for (int i = 0; i < this->n; i++)
			for (int j = i + 1; j < this->n; j++) 
				for (int k = j + 1; k < this->n; k++) 
					if (poped[i] > poped[k] && poped[k] > poped[j]) return false;
		return true;
	}

	bool screening_On(vector<int> poped) {		//(O(n)算法)甄别poped序列是否是一个合法的出栈序列
		/* 我们可以通过栈模拟的方式来还原判断出栈序列是否合法 */
		stack<int> st;
		int i = 1, j = 0;
		for (i = 1; i <= this->n; i++) {
			st.push(i);
			while (!st.empty() && st.top() == poped[j]) {
				st.pop();
				j++;
			}
		}
		return st.size() == 0;
	}

	void dfs(int number_push, int number_pop, string str) {
		//我们先检测一下当前序列有没有违背两点条件：
		if (number_push < number_pop) return;
		if (number_push > n) return;

		if (number_pop == this->n && number_push == this->n) {	
			//我们已经构造出了一个合法的出栈序列，我们将他打印输出并返回即可
			stack<int> st;
			int j = 1;
			for (int i = 0; i < 2 * n; i++) {
				if (str[i] == '(') st.push(j++);
				else {
					cout << st.top();
					st.pop();
				}
			}
			cout << endl;
			return;
		}

		dfs(number_push + 1, number_pop, str + '(');
		dfs(number_push, number_pop + 1, str + ')');

		return;
	}

	void print_all_popped() {		//打印生成所有合法的栈混洗出栈序列

		/* 由于入栈序列是确定的，所以我们要打印输出所有合法的出栈序列，
		本质就是对push和pop操作的排序问题，假设说入栈序列长度为n，
		那么问题就将转换成对n个push和n个pop操作的排序，这完全可以类比成括号生成问题，
		我们可以将push看作 ( ，pop看作 ) ； */

		/* 根据上面的分析，我们可以知道所有合法的栈混洗出栈序列的数目为卡特兰数，
		要想生成所有的合法序列，我们只需要把握两点：
		（1）push的数量必须严格不小于pop的数量 
		（2）push的数量必须严格不大于n        
		然后我们进行深度优先搜索即可  */

		cout << "入队序列为1..." << this->n << "时，经过栈混洗后所有合法的出栈序列为：" << endl;
		dfs(0, 0, "");
	}
};

int main(void) {
    /* 在此处添加您的测试程序 */
	return 0;
}