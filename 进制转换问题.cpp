///* 编写一个程序，将十进制数转换成base进制数 */
//
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//char digit[] = { '0','1', '2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
//
//int number;		//number表示我们要转换的十进制数
//int base;		//base表示我们要将number转换成base进制数
//
//stack<int> s;
//
//int main(void) {
//	cin >> number >> base;
//
//	//由于进制转换的过程符合“先进后出”的规则，因此我们可以借助堆栈实现
//	int temp = number;
//	while (temp) {
//		s.push(temp % base);
//		temp /= base;
//	}
//
//	string ans;
//	while (!s.empty()) {
//		ans += digit[s.top()];
//		s.pop();
//	}
//
//	if (base == 2) ans += 'B';
//	if (base == 16) ans += 'H';
//
//	cout << number << "转换为" << base << "进制数为" << ans;
//
//	return 0;
//}