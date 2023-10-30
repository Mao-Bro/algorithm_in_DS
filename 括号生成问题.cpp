///* 只考虑一种括号，n对括号共有多少种可能的合法匹配序列？ */
//
///* 这个问题的答案显然是一个卡特兰数，我们今天要解决的是如何将所有合法的情况全部生成出来 */
//
///* 对于这个问题，我们可以采用回溯算法去生成一颗二叉树，将所有可能的情况遍历出来，
//但是这样的话太过于暴力，我们可以加上剪枝的策略，
//在什么情况下，我们可以直接放弃下面的生成呢，只需要把握住两点：
//（1）右括号的数量绝对不能超过左括号；
//（2）左括号的数量不能超过n */
//
//#include <iostream>
//
//using namespace std;
//
//int n;
//
//void dfs(string str, int left, int right) {
//	if (right > left) return;	//右括号数量大于左括号，直接回退
//	if (left > n) return;		//左括号数量大于n，直接回退
//	
//	if (str.length() == 2 * n) {	//成功找到一个答案
//		cout << str << endl;
//		return;
//	}
//
//	dfs(str + '(', left + 1, right);
//	dfs(str + ')', left, right + 1);
//
//	return;
//}
//
//int main(void) {
//	cin >> n;
//	cout << n << "对括号所有可能的合法匹配序列为:" << endl;
//	dfs("", 0, 0);
//	return 0;
//}