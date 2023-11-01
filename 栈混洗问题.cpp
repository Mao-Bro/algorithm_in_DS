/* ջ��ϴ�Ƕ�ջ��һ���ǳ����õĹ��ܣ�
������������1, 2, ��, n��
1. 1��n����һ����a1,a2,��,an�Ƿ�Ϊ�Ϸ��ĳ�ջ���У��ⱻ��Ϊջ��ϴ���������
2. �ж����ֿ��ܵĳ�ջ���У��ⱻ��Ϊջ��ϴ���������� */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Stack_shuffle {
public:
	int n;	//��ջ����1��2��...��n

	bool screening_violent(vector<int> poped) {		//(�����㷨)���poped�����Ƿ���һ���Ϸ��ĳ�ջ����
		/* �ڳ�ջ���е��У�һ���������һ�������
		...Ai...Aj...Ak.... , Ai > Ak > Aj , ����һ�ֽ���
		һ�����������ֽ��򣬳�ջ���о��ǷǷ��� */

		/* �����㷨����ͨ�������ķ�ʽ�жϳ�ջ���е����Ƿ���ڽ��� */
		for (int i = 0; i < this->n; i++)
			for (int j = i + 1; j < this->n; j++) 
				for (int k = j + 1; k < this->n; k++) 
					if (poped[i] > poped[k] && poped[k] > poped[j]) return false;
		return true;
	}

	bool screening_On(vector<int> poped) {		//(O(n)�㷨)���poped�����Ƿ���һ���Ϸ��ĳ�ջ����
		/* ���ǿ���ͨ��ջģ��ķ�ʽ����ԭ�жϳ�ջ�����Ƿ�Ϸ� */
		stack<int> st;
		int i = 1, j = 0;
		for (i = 1; i <= this->n; i++) {
			st.push(i);
			while (!st.empty() && st.top() == poped[j]) {
				st.pop();
				j++;
			}
		}
		return st.size() == 0;
	}

	void dfs(int number_push, int number_pop, string str) {
		//�����ȼ��һ�µ�ǰ������û��Υ������������
		if (number_push < number_pop) return;
		if (number_push > n) return;

		if (number_pop == this->n && number_push == this->n) {	
			//�����Ѿ��������һ���Ϸ��ĳ�ջ���У����ǽ�����ӡ��������ؼ���
			stack<int> st;
			int j = 1;
			for (int i = 0; i < 2 * n; i++) {
				if (str[i] == '(') st.push(j++);
				else {
					cout << st.top();
					st.pop();
				}
			}
			cout << endl;
			return;
		}

		dfs(number_push + 1, number_pop, str + '(');
		dfs(number_push, number_pop + 1, str + ')');

		return;
	}

	void print_all_popped() {		//��ӡ�������кϷ���ջ��ϴ��ջ����

		/* ������ջ������ȷ���ģ���������Ҫ��ӡ������кϷ��ĳ�ջ���У�
		���ʾ��Ƕ�push��pop�������������⣬����˵��ջ���г���Ϊn��
		��ô����ͽ�ת���ɶ�n��push��n��pop��������������ȫ������ȳ������������⣬
		���ǿ��Խ�push���� ( ��pop���� ) �� */

		/* ��������ķ��������ǿ���֪�����кϷ���ջ��ϴ��ջ���е���ĿΪ����������
		Ҫ���������еĺϷ����У�����ֻ��Ҫ�������㣺
		��1��push�����������ϸ�С��pop������ 
		��2��push�����������ϸ񲻴���n        
		Ȼ�����ǽ������������������  */

		cout << "�������Ϊ1..." << this->n << "ʱ������ջ��ϴ�����кϷ��ĳ�ջ����Ϊ��" << endl;
		dfs(0, 0, "");
	}
};

int main(void) {
    /* �ڴ˴�������Ĳ��Գ��� */
	return 0;
}