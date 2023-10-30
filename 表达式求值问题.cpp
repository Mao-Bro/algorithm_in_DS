///* 给你一个中缀表达式(我们规定表达式当中只包含小于十的正整数，加减乘除运算符，和小括号)，
//例如3*(5+7) ，请你输出该表达式求解的结果 */
//
///* 这个问题应该分为两部分解决，
//首先我们知道计算机是无法直接处理中缀表达式的，
//但是计算机可以处理后缀表达式，
//因此，我们首先要将给定的中缀表达式转换成后缀表达式，
//然后求解后缀表达式的数值 */
//
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//string nifix_expression;
//string postfix_expression;
//
//stack<char> s;
//stack<double> ds;
//
///*
//中缀表达式转后缀表达式算法：
//设置一个栈，存放运算符
//从左到右依次读入中缀表达式的每一个元素：
//➢ 操作数规则：直接放入后缀表达式
//➢ 运算符规则：
//(1) 栈空或栈顶是左括号：运算符压栈
//(2) 当前运算符优先级  > 栈顶运算符：压栈
//(3) 当前运算符优先级 <= 栈顶运算符：弹栈直至当前运算符优先级大于栈顶或栈空或栈顶为左括号，再压栈
//➢ 括号规则：
//(1) 遇到左括号：压栈
//(2) 遇到右括号：弹栈直至左括号
//➢ 结束符规则：弹栈至栈空
//*/
//string nifix_to_postfix(string str) {	//将中缀表达式转换成后缀表达式
//	string ans;
//	for (int i = 0; i < str.length(); i++) {
//		char ch = str[i];
//		if ('0' <= ch && ch <= '9') {	//操作数
//			ans += ch;	//操作数直接放到后缀表达式当中
//		}
//		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {	//运算符
//			if (s.empty() || s.top() == '(') {	//栈空或者栈顶为‘(’，直接压栈
//				s.push(ch);
//			}
//			else if ((ch == '*' || ch == '/') && (s.top() == '+' || s.top() == '-')) {	
//				s.push(ch);	//当前运算符优先级大于栈顶运算符优先级，直接压栈
//			}
//			else {	//
//				while (!(s.empty() || s.top() == '(' || ((ch == '*' || ch == '/') && (s.top() == '+' || s.top() == '-')))) {
//					ans += s.top();		//弹栈直至当前运算符优先级大于栈顶或栈空或栈顶为左括号，再压栈
//					s.pop();
//				}
//				s.push(ch);
//			}
//		}
//		else {	//括号
//			if (ch == '(') {	//左括号直接压栈
//				s.push(ch);
//			}
//			else {
//				while (s.top() != '(') {	//右括号一直弹栈直至遇到左括号
//					ans += s.top();
//					s.pop();
//				}
//				s.pop();	//左右括号完成匹配
//			}
//		}
//	}
//	//中缀表达式读取结束后，将堆栈当中的所有字符全部弹栈到后缀表达式当中
//	while (!s.empty()) {
//		ans += s.top();
//		s.pop();
//	}
//
//	return ans;
//}
//
//
///*
//后缀表达式求值的算法:
//设置一个栈，存放操作数
//从左到右依次读入后缀表达式的每一个操作数/运算符/结束符：
//①若读到的是操作数，将它压入堆栈。
//②若读到的是运算符，就从操作数栈中连续弹出两个元素（操作数），进行相应的运算，并将结果压入栈中。
//③读入结束符时，栈顶元素就是计算结果。
//*/
//double postfix_to_number(string str) {
//	for (int i = 0; i < str.length(); i++) {
//		char ch = str[i];
//		if ('0' <= ch && ch <= '9') {	//读到操作数直接压栈
//			ds.push((double)(ch - '0'));
//		}
//		else {	//读到运算符就将堆栈顶部两个元素进行相应运算，将运算结果在压栈
//			double num2 = ds.top();
//			ds.pop();
//			double num1 = ds.top();
//			ds.pop();
//
//			if (ch == '+') ds.push(num1 + num2);
//			else if (ch == '-') ds.push(num1 - num2);
//			else if (ch == '*') ds.push(num1 * num2);
//			else ds.push(num1 / num2);
//		}
//	}
//	return ds.top();
//}
//
//int main(void) {
//	cout << "请输入要计算的中缀表达式：" << endl;
//	cin >> nifix_expression;
//
//	postfix_expression = nifix_to_postfix(nifix_expression);
//
//	cout << endl;
//	cout << "转换后的后缀表达式为：" << postfix_expression << endl;;
//
//	cout << endl;
//	cout << "---------------------------------------------" << endl;
//	cout << "表达式运算结果为：" << postfix_to_number(postfix_expression) << endl;
//	cout << "---------------------------------------------" << endl;
//
//	return 0;
//}