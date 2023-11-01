/* ����ջ�Ƕ�ջ����һ������Ӧ�ã������ҽ�ʹ�ü��������������Ӧ�÷��� */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//=====================================================================================
/* ep1.����һ������Ԫ�ء�������һ������Ϊn������a���ҳ�ÿ��λ�õ���һ������Ԫ��
��������λ��i����a[i]���ұߵ�һ����a[i]���Ԫ�أ�����������ڣ������-1��n������105��
���ֽ����������⡿*/

class Find_nextBiggerOne {
public:
	int n;
	vector<int> a;

	void solution() {
		cin >> this->n;
		for (int i = 0; i < this->n; i++) {
			int temp = 0;
			cin >> temp;
			a.push_back(temp);
		}

		/* ���ǿ������õ���ջ��˼�����������⣬�����������£�
		����׼��һ����ջst��Ȼ���������a�����ڵ�ǰָ�������aԪ��elem��
		��1����ջΪ�ջ���elem <= st.top()��ֱ�ӽ�elemѹ���ջ����
		��2��elem > st.top()�����ǵ�ջֱ����ջΪ�գ�����st.top() < elem���ٽ���ǰԪ��ѹ���ջ
		���ڵ�ջ���̵��е�����Ԫ���ǣ��������ǵ�����ջ��Ԫ��elem��������Ԫ��
		
		�������Ǹ���ν���������Ԫ�ص�����Ԫ�ؿ������뵽�������Ӧλ���أ�
		�����и����ɣ����ǽ������±���Ϊѹ���ջ��Ԫ�ؼ��� */

		vector<int> ans(this->n, 0);
		stack<int> st;
		for (int i = 0; i < this->n; i++) {
			if (st.empty() || a[i] <= a[st.top()]) {
				st.push(i);
			}
			else {
				while (!(st.empty() || a[i] <= a[st.top()])) {
					ans[st.top()] = a[i];
					st.pop();
				}
				st.push(i);
			}
		}
		ans[st.top()] = -1;

		for (int i = 0; i < this->n; i++) {
			cout << ans[i] << " ";
		}
	}
};
//=====================================================================================
/* ep2.��ÿ���¶ȡ�������ÿ�������б� ���������ÿһ����Ҫ�ȼ���Ż��и��ߵ��¶ȡ�
�����������֮�󶼲������ߣ����ڸ�λ���� 0 �����档�б��Ȳ�����105. 
���ֽ���������Ϊ�������Ѷ���ȸ衢΢��ƻ�������⡿ */

class DailyTemperature {
public:
	int n;
	vector<int> temperature;

	void solution() {
		cin >> this->n;
		for (int i = 0; i < this->n; i++) {
			int temp = 0;
			cin >> temp;
			temperature.push_back(temp);
		}

		/* ��Ȼ��������������ep1�Ƿǳ����Ƶģ�����ֻҪ�������Ƶķ����Ϳ��Խ�� */
		vector<int> ans(this->n, 0);
		stack<int> st;
		for (int i = 0; i < this->n; i++) {
			while (!st.empty() && temperature[i] > temperature[st.top()]) {
				int index = st.top();
				st.pop();
				ans[index] = i - index;
			}
			st.push(i);
		}

		for (int i = 0; i < this->n; i++) {
			cout << ans[i] << " ";
		}
	}
};
//=====================================================================================
/* ep3.����״ͼ�������Ρ�������n���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�
ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1 �����ڸ���״ͼ�У��ܹ����ճ����ľ��ε���������
����Ѷ����Ϊ���ֽ�������΢���ȸ衢ƻ�����ٶȡ�С�ס����������⡢CSP��֤���⡿
ʾ������: 2 1 5 6 2 3 1 ʾ�����: 10 */

class LargestRectangle {
public:
	int n;
	vector<int> h;

	/* ��������һ�����⣬���Ƿǳ������뵽һ������������������������ľ��ǸߺͿ�����������
	����ֻҪ�̶�����һ����������ȥ��������һ��������һ�����Խ��������� 
	�����ҽ����ι̶����εĸߣ���ȥ����ÿһ�������ܻ�õ������ */
	void solution_violent() {
		int max_S = 0;
		for (int i = 0; i < n; i++) {
			int height = h[i];		//�̶�ס��

			int left = i, right = i;	//����left��rightȥѰ�����������Ҳ�
			while (left >= 0 && h[left] >= height) left--;
			while (right < n && h[right] >= height) right++;

			//���յĿ�Ⱦ���right - left - 1
			max_S = max(max_S, height * (right - left - 1));
		}
		cout << "ʹ�ñ����㷨��������ε�������Ϊ��" << max_S << endl;
	}
	/* ���ǻ�ͷ����һ������һ���������������Ǳ����̶���ÿһ���߶�h��
	���Ҷ���ÿһ���߶�h��������������ɢѰ�����ұ߽磬��ɢ�����Χ���Ǳ���һ�����飬
	�������һ���㷨��ʱ�临�Ӷ�ΪO(n^2)������û�ж��⿪���ڴ�ռ䣬��˿ռ临�Ӷ�ΪO(1) */

	/* ����һ���㷨��Ȼ�ǲ����õģ�����˼��һ���Ƿ����ʹ�õ���ջ���������������������һЩ�Ż��أ�
	�����ǹ̶�hʱ������ÿһ���߶�h�����Ƕ�Ҫͨ����������ķ�ʽ��Ѱ�������ұ߽��λ�ã����Ǳ����㷨
	ʱ�临�ӶȴﵽO(n^2)��ֱ��ԭ�������Ƿ������ǰ��ÿһ���߶�h�����ұ߽���ǰ��������أ�����*/

	/* ���������뵽��ep1����һ������Ԫ�ء�������ֻ��Ҫģ��ep1�����������ÿһ���߶ȵġ�ǰһ����СԪ�ء�
	���͡���һ����СԪ�ء�������ڱ���һ�������������������ɣ���������ֻ��Ҫ�����������飬
	���ɽ���������⣬ʱ�临�ӶȽ�����O(n)���������������ڶ�ջ�ϵĿ�����Ҳ������O(n)�Ŀռ临�Ӷȣ�
	������һ�ֿռ任ʱ����㷨 */

	vector<int> nextSmaller() {		//��ȡ���鵱��ÿһ��Ԫ�ص���һ����СԪ���±�
		//��ep1������ͬ���ǣ�����������ά������һ�����������ĵ���ջ
		stack<int> st;
		vector<int> ans(this->n, 0);
		for (int i = 0; i < this->n; i++) {
			if (st.empty() || h[i] >= h[st.top()]) {
				st.push(i);
			}
			else {
				while (!st.empty() && h[i] < h[st.top()]) {
					ans[st.top()] = i;
					st.pop();
				}
				st.push(i);
			}
		}
		while (!st.empty()) {
			ans[st.top()] = this->n;
			st.pop();
		}
		return ans;
	}

	vector<int> previousSmaller() {		//��ȡ���鵱��ÿһ��Ԫ�ص�ǰһ����СԪ���±�
		//Ҫ��ȡ����Ԫ��ǰһ����СԪ���±꣬�����ǽ�����ߵ������������һ����СԪ���±�������
		//�������ֻ��Ҫ�����鷴��ɨ�輴��
		stack<int> st;
		vector<int> ans(this->n, 0);
		for (int i = this->n - 1; i >= 0; i--) {
			if (st.empty() || h[i] >= h[st.top()]) {
				st.push(i);
			}
			else {
				while (!st.empty() && h[i] < h[st.top()]) {
					ans[st.top()] = i;
					st.pop();
				}
				st.push(i);
			}
		}
		while (!st.empty()) {
			ans[st.top()] = -1;
			st.pop();
		}
		return ans;
	}

	void soluton_On() {
		vector<int> left = this->previousSmaller();
		vector<int> right = this->nextSmaller();

		int max_S = -1;
		for (int i = 0; i < this->n; i++) {
			max_S = max(max_S, this->h[i] * (right[i] - left[i] - 1));
		}

		cout << "ʹ�õ���ջ�㷨����������������Ϊ��" << max_S;
	}
};

int main(void) {
    /* �����������Ĳ��Գ��� */
	return 0;
}
