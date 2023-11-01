/* 输入一段字符串，其中包含有各种字符以及小中大三种括号，请判断括号是否是匹配的 */

#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

string str;
stack<int> s;

int main(void) {
	cin >> str;

	/* 我们使用堆栈只存储左括号，
	也就是说，遇到左括号时我们就将其压栈，
	遇到右括号时我们就将其与栈顶的左括号匹配，
	当字符串读取结束时，
	若堆栈为空，则说明匹配成功*/

	for (int i = 0; i < str.length(); i++) {
		char ch = str[i];

		if (ch == '(' || ch == '[' || ch == '{') s.push(ch);	//遇到左括号直接压栈即可
		else if (ch == ')' || ch == ']' || ch == '}') {				//遇到右括号，我们需要将其与栈顶左括号进行匹配
			if (abs(ch - s.top()) <= 2) {		//这里是否匹配的判断方式是利用了ASCII码表
				s.pop();
			}
			else {
				cout << "匹配失败！！！";
				return;
			}
		}
	}

	if (s.empty()) cout << "匹配成功！！！";
	else cout << "匹配失败！！！";

	return 0;
}

/* 我们可以对该问题升级，我们要求括号的顺序符合写作的正常逻辑，即{[( )]}，才算做是匹配成功 */

/* 这样也很简单，我们只需要在遇到左括号压栈前，做一步判断就可以了，
我们判断一下当前栈顶左括号是否比它大即可，比它大就说明是符合写作逻辑的，
否则我们直接输出匹配失败 */
