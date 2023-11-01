/* 单调栈是堆栈的又一个常见应用，下面我将使用几个例题介绍这种应用方法 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//=====================================================================================
/* ep1.“下一个更大元素”：给定一个长度为n的数组a，找出每个位置的下一个更大元素
（即对于位置i，找a[i]的右边第一个比a[i]大的元素），如果不存在，则输出-1。n不超过105。
【字节跳动面试题】*/

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

		/* 我们可以利用单调栈的思想解决上述问题，具体做法如下：
		我们准备一个堆栈st，然后遍历数组a，对于当前指向的数组a元素elem：
		（1）堆栈为空或者elem <= st.top()，直接将elem压入堆栈当中
		（2）elem > st.top()，我们弹栈直至堆栈为空，或者st.top() < elem，再将当前元素压入堆栈
		对于弹栈过程当中弹出的元素们，导致它们弹出堆栈的元素elem正是所求元素
		
		但是我们该如何将各个数组元素的所求元素快速填入到答案数组对应位置呢，
		这里有个技巧：我们将数组下标作为压入堆栈的元素即可 */

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
/* ep2.“每日温度”：给定每日气温列表 ，请计算在每一天需要等几天才会有更高的温度。
如果气温在这之后都不会升高，请在该位置用 0 来代替。列表长度不超过105. 
【字节跳动、华为、阿里、腾讯、谷歌、微软、苹果面试题】 */

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

		/* 显然这个问题与上面的ep1是非常类似的，我们只要采用类似的方法就可以解决 */
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
/* ep3.“柱状图中最大矩形”：给定n个非负整数，用来表示柱状图中各个柱子的高度。
每个柱子彼此相邻，且宽度为 1 。求在该柱状图中，能够勾勒出来的矩形的最大面积。
【腾讯、华为、字节跳动、微软、谷歌、苹果、百度、小米、网易面试题、CSP认证真题】
示例输入: 2 1 5 6 2 3 1 示例输出: 10 */

class LargestRectangle {
public:
	int n;
	vector<int> h;

	/* 对于这样一个问题，我们非常容易想到一个暴力方法：决定矩形面积的就是高和宽两个参数，
	我们只要固定其中一个参数，再去遍历另外一个参数，一定可以解决这个问题 
	下面我将依次固定矩形的高，再去遍历每一个高所能获得的最大宽度 */
	void solution_violent() {
		int max_S = 0;
		for (int i = 0; i < n; i++) {
			int height = h[i];		//固定住高

			int left = i, right = i;	//利用left和right去寻找最左侧和最右侧
			while (left >= 0 && h[left] >= height) left--;
			while (right < n && h[right] >= height) right++;

			//最终的宽度就是right - left - 1
			max_S = max(max_S, height * (right - left - 1));
		}
		cout << "使用暴力算法计算出矩形的最大面积为：" << max_S << endl;
	}
	/* 我们回头分析一下这样一个暴力做法，我们遍历固定了每一个高度h，
	并且对于每一个高度h都向两侧做了扩散寻找左右边界，扩散的最大范围就是遍历一遍数组，
	因此这样一个算法的时间复杂度为O(n^2)，我们没有额外开辟内存空间，因此空间复杂度为O(1) */

	/* 这样一个算法显然是不够好的，我们思考一下是否可以使用单调栈来对这个暴力的做法进行一些优化呢，
	当我们固定h时，对于每一个高度h，我们都要通过遍历数组的方式来寻找它左右边界的位置，这是暴力算法
	时间复杂度达到O(n^2)的直接原因，我们是否可以提前将每一个高度h的左右边界提前计算出来呢？？？*/

	/* 于是我们想到了ep1“下一个更大元素”，我们只需要模拟ep1的做法计算出每一个高度的“前一个更小元素”
	，和“下一个更小元素”，最后在遍历一次数组计算出最大面积即可，这样我们只需要遍历三次数组，
	即可解决整个问题，时间复杂度降到了O(n)，但是由于我们在堆栈上的开销，也将带来O(n)的空间复杂度，
	本质是一种空间换时间的算法 */

	vector<int> nextSmaller() {		//获取数组当中每一个元素的下一个更小元素下标
		//与ep1有所不同的是，我们在这里维护的是一个单调递增的单调栈
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

	vector<int> previousSmaller() {		//获取数组当中每一个元素的前一个更小元素下标
		//要获取数组元素前一个更小元素下标，不就是将数组颠倒过来，求解下一个更小元素下标问题吗，
		//因此我们只需要将数组反向扫描即可
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

		cout << "使用单调栈算法计算出的最大矩形面积为：" << max_S;
	}
};

int main(void) {
    /* 在这里添加你的测试程序 */
	return 0;
}
