/* 通过计算机当中一个非常经典的Hanoi塔问题，我们来感受一下如何利用堆栈来模拟递归过程，进而消除递归
这也是计算机当中，堆栈的一个常见应用，下面我将使用递归和堆栈模拟两种方法实现Hanoi塔问题 */

#include <iostream>
#include <stack>

using namespace std;

class Hanoi_recursion {		//递归方法
public:
	//借助于b号柱子，将a号柱子上的1~n个盘子移动到c号柱子上去
	void Hanoi(int n, char a, char b, char c) {
		if (n == 0) return;	
		Hanoi(n - 1, a, c, b);
		Move(a, c);
		Hanoi(n - 1, b, a, c);
	}

	//将a号柱子上的一个盘子移动到c号柱子上面去
	void Move(char a, char c) {
		cout << a << "->" << c << endl;
	}
};

struct Node {		//我们定义四元组结构体(n,a,b,c)表示借助b柱，将a柱上的n个盘子移动到c柱上
	int n;
	char a, b, c;
	struct Node() :n(0), a(' '), b(' '), c(' ') { }
	struct Node(int _n, char _a, char _b, char _c) :
		n(_n),
		a(_a),
		b(_b),
		c(_c) {

	}
};

/* 采用栈模拟递归过程中子任务的产生和处理过程：
➢ 产生新的子任务对应入栈操作；
➢ 处理子任务对应出栈操作；
➢ 未来先处理的子任务后入栈；
➢ 未来后处理的子任务先入栈。 */

class Hanoi_stack {		//堆栈消除递归
public:
	stack<struct Node*> s;

	void Hanoi(int n, char a, char b, char c) {
		s.push(new Node(n, a, b, c));

		while (!s.empty()) {
			struct Node* top = s.top();
			s.pop();

			if (top->n == 1) Move(top->a, top->c);
			else {
				s.push(new Node(top->n - 1, top->b, top->a, top->c));
				s.push(new Node(1, top->a, top->b, top->c));
				s.push(new Node(top->n - 1, top->a, top->c, top->b));
			}
		}
	}

	void Move(char a, char c) {
		cout << a << "->" << c << endl;
	}
};

int main(void) {
	Hanoi_recursion test_recursion;
	Hanoi_stack test_stack;

	int n = 0;
	cout << "请输入开始时，a柱上有多少个盘子：" << endl;
	cin >> n;

	cout << "递归方法计算出，盘子的移动方式为：" << endl;
	test_recursion.Hanoi(n, 'a', 'b', 'c');

	cout << "堆栈消除递归方法计算出，盘子的移动方式为：" << endl;
	test_stack.Hanoi(n, 'a', 'b', 'c');
}