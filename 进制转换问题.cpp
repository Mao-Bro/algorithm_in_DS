///* ��дһ�����򣬽�ʮ������ת����base������ */
//
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//char digit[] = { '0','1', '2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
//
//int number;		//number��ʾ����Ҫת����ʮ������
//int base;		//base��ʾ����Ҫ��numberת����base������
//
//stack<int> s;
//
//int main(void) {
//	cin >> number >> base;
//
//	//���ڽ���ת���Ĺ��̷��ϡ��Ƚ�������Ĺ���������ǿ��Խ�����ջʵ��
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
//	cout << number << "ת��Ϊ" << base << "������Ϊ" << ans;
//
//	return 0;
//}