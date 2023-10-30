///* 我们实现以下网络浏览器当中十分常见的两项功能：
//（1）对用户最近访问的网页进行“前进”；
//（2）对用户最近访问的网页进行“后退”；*/
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
//	string web_now;			//该字符串存储着用户当前访问的网页
//
//public:
//	_WEB() {
//		this->web_now = "起始页";
//		cout << "欢迎使用_WEB" << endl;
//		this->SHOW();
//	}
//
//	//我们先提供一个显示当前用户正在访问页面的接口：
//	void SHOW() {
//		cout << endl;
//		cout << "当前用户正在访问的页面为 https:// " << this->web_now << endl;
//	}
//
//	//我们提供一个供用户返回到上一个访问页面的接口：
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
//	//我们提供一个供用户前进到下一个界面的接口：
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
//	//我们提供一个供用户访问新页面的接口;
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
//	//测试程序：我们先打开浏览器
//	//访问bilibili
//	//访问leetcode
//	//访问蓝桥杯官网
//	//回退到leetcode
//	//回退到bilibili
//	//回退到起始页
//	//无效回退
//	//前进到bilibili
//	//前进到leetcode
//	//访问jlu.edu.cn
//	//无效前进
//	//退回到leetcode
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