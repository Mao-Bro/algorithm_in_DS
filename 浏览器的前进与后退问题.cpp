///* ����ʵ�������������������ʮ�ֳ���������ܣ�
//��1�����û�������ʵ���ҳ���С�ǰ������
//��2�����û�������ʵ���ҳ���С����ˡ���*/
//
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//class _WEB {
//private:
//	stack<string> backward;
//	stack<string> forward;
//	string web_now;			//���ַ����洢���û���ǰ���ʵ���ҳ
//
//public:
//	_WEB() {
//		this->web_now = "��ʼҳ";
//		cout << "��ӭʹ��_WEB" << endl;
//		this->SHOW();
//	}
//
//	//�������ṩһ����ʾ��ǰ�û����ڷ���ҳ��Ľӿڣ�
//	void SHOW() {
//		cout << endl;
//		cout << "��ǰ�û����ڷ��ʵ�ҳ��Ϊ https:// " << this->web_now << endl;
//	}
//
//	//�����ṩһ�����û����ص���һ������ҳ��Ľӿڣ�
//	void BACK() {
//		if (this->backward.empty()) {
//			this->SHOW();
//		}
//		else {
//			this->forward.push(this->web_now);
//			this->web_now = this->backward.top();
//			this->backward.pop();
//			this->SHOW();
//		}
//	}
//
//	//�����ṩһ�����û�ǰ������һ������Ľӿڣ�
//	void FORWARD() {
//		if (this->forward.empty()) {
//			this->SHOW();
//		}
//		else {
//			this->backward.push(this->web_now);
//			this->web_now = this->forward.top();
//			this->forward.pop();
//			this->SHOW();
//		}
//	}
//
//	//�����ṩһ�����û�������ҳ��Ľӿ�;
//	void VISIT(string new_web) {
//		this->backward.push(this->web_now);
//		this->web_now = new_web;
//		while (!this->forward.empty()) {
//			this->forward.pop();
//		}
//		this->SHOW();
//	}
//};
//
//int main(void) {
//	//���Գ��������ȴ������
//	//����bilibili
//	//����leetcode
//	//�������ű�����
//	//���˵�leetcode
//	//���˵�bilibili
//	//���˵���ʼҳ
//	//��Ч����
//	//ǰ����bilibili
//	//ǰ����leetcode
//	//����jlu.edu.cn
//	//��Чǰ��
//	//�˻ص�leetcode
//	class _WEB test = _WEB();
//	test.VISIT("bilibili.com");
//	test.VISIT("leetcode.com");
//	test.VISIT("lanqiaoCUP.com");
//	test.BACK();
//	test.BACK();
//	test.BACK();
//	test.BACK();
//	test.FORWARD();
//	test.FORWARD();
//	test.VISIT("jlu.edu.cn");
//	test.FORWARD();
//	test.BACK();
//	return 0;
//}