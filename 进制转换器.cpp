///* ʵ��һ�����Դ��������ת����������ƵĽ���ת���� */
//
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//char digit[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d', 'e', 'f' };
//
//stack<int> s;
//
//int source_scale;		//Դ����
//int destination_scale;	//Ŀ�Ľ���
//
//string number;
//
//int main(void) {
//	cout << "��Ҫת��һ�����ٽ��Ƶ�����" << endl;
//	cin >> source_scale;
//	cout << "��Ҫ���������ת���ɶ��ٽ��ƣ�" << endl;
//	cin >> destination_scale;
//
//	cout << "��������Ҫת�������֣�" << endl;
//	cin >> number;
//
//	//������ȥ���û��ڶ����������е�B��׺����ʮ�������������H��׺
//	char last_ch = number[number.length() - 1];
//	if (last_ch == 'b' || last_ch == 'B' || last_ch == 'h' || last_ch == 'H') {
//		(void)number.erase(number.length() - 1);
//	}
//
//	//������Ҫ�Ƚ��������ת����ʮ���ƣ��ٽ�ʮ����ת����Ŀ����ƣ�
//	int ten_scale = 0;
//	int multi = 0;
//	for (int i = number.length() - 1; i >= 0; i--, multi++) {
//		char ch = number[i];
//		int last_num = 0;
//		if ('0' <= ch && ch <= '9') {
//			last_num = ch - '0';
//		}
//		else if ('a' <= ch && ch <= 'f') {
//			last_num = ch - 'a' + 10;
//		}
//		else if ('A' <= ch && ch <= 'F') {
//			last_num = ch - 'A' + 10;
//		}
//		else {
//			cout << "��������һ���Ƿ��ַ�������";
//			return 0;
//		}
//		ten_scale += last_num * (int)pow(source_scale, multi);
//	}
//
//	//��ʱten_scale�Ѿ���¼��ԭ���ֵ�ʮ������ʽ�������ٽ��������ת����Ŀ�Ľ��Ƽ���
//	while (ten_scale) {
//		s.push(ten_scale % destination_scale);
//		ten_scale /= destination_scale;
//	}
//
//	string ans;
//
//	while (!s.empty()) {
//		ans += digit[s.top()];
//		s.pop();
//	}
//
//	if (destination_scale == 16) ans += 'H';
//	if (destination_scale == 2) ans += 'B';
//
//	cout << endl;
//	cout << "----------------------------------------------------------------" << endl;
//	cout << source_scale << "������" << number << "ת����" << destination_scale << "������,���Ϊ" << ans << endl;
//	cout << "----------------------------------------------------------------" << endl;
//
//	return 0;
//}