///* 问题是这样的：给定一个实数a和一个整数n(保证两者不会同时为零)，要求计算出a^n，相当于实现一个pow( )函数 */
//#include <iostream>
//
//using namespace std;
//
//int a, n;
//
//double myPow(double a, int n) {
//	if (n == 0) return 1.0;
//
//	if (n % 2 == 0) return myPow(a * a, n / 2);
//	else return myPow(a * a, n / 2) * a;
//}
//
//int main(void) {
//	cin >> a >> n;
//
//	if (n < 0) cout << a << "的" << n << "次方为：" <<  1.0 / myPow(a, n);
//	else cout << a << "的" << n << "次方为：" << myPow(a, n);
//		 
//	return 0;
//}