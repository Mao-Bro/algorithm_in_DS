/* 实现一个可以从任意进制转换成任意进制的进制转换器 */

#include <iostream>
#include <stack>

using namespace std;

char digit[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d', 'e', 'f' };

stack<int> s;

int source_scale;		//源进制
int destination_scale;	//目的进制

string number;

int main(void) {
	cout << "你要转换一个多少进制的数：" << endl;
	cin >> source_scale;
	cout << "你要将这个数字转换成多少进制：" << endl;
	cin >> destination_scale;

	cout << "请输入你要转换的数字：" << endl;
	cin >> number;

	//我们先去除用户在二进制数当中的B后缀，和十六进制数后面的H后缀
	char last_ch = number[number.length() - 1];
	if (last_ch == 'b' || last_ch == 'B' || last_ch == 'h' || last_ch == 'H') {
		(void)number.erase(number.length() - 1);
	}

	//我们需要先将这个数字转换成十进制，再将十进制转换成目标进制：
	int ten_scale = 0;
	int multi = 0;
	for (int i = number.length() - 1; i >= 0; i--, multi++) {
		char ch = number[i];
		int last_num = 0;
		if ('0' <= ch && ch <= '9') {
			last_num = ch - '0';
		}
		else if ('a' <= ch && ch <= 'f') {
			last_num = ch - 'a' + 10;
		}
		else if ('A' <= ch && ch <= 'F') {
			last_num = ch - 'A' + 10;
		}
		else {
			cout << "你输入了一个非法字符！！！";
			return 0;
		}
		ten_scale += last_num * (int)pow(source_scale, multi);
	}

	//此时ten_scale已经记录了原数字的十进制形式，我们再将这个数字转换成目的进制即可
	while (ten_scale) {
		s.push(ten_scale % destination_scale);
		ten_scale /= destination_scale;
	}

	string ans;

	while (!s.empty()) {
		ans += digit[s.top()];
		s.pop();
	}

	if (destination_scale == 16) ans += 'H';
	if (destination_scale == 2) ans += 'B';

	cout << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << source_scale << "进制数" << number << "转换成" << destination_scale << "进制数,结果为" << ans << endl;
	cout << "----------------------------------------------------------------" << endl;

	return 0;
}
