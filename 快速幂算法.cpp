///* �����������ģ�����һ��ʵ��a��һ������n(��֤���߲���ͬʱΪ��)��Ҫ������a^n���൱��ʵ��һ��pow( )���� */
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
//	if (n < 0) cout << a << "��" << n << "�η�Ϊ��" <<  1.0 / myPow(a, n);
//	else cout << a << "��" << n << "�η�Ϊ��" << myPow(a, n);
//		 
//	return 0;
//}