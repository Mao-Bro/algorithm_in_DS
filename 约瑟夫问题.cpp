//#include <iostream>
//
//using namespace std;
//
///*
//							著名的约瑟夫问题：
//N个人围成一圈，从第一个开始报数，第M个人出列，不断循环，按顺序输出出列人的编号。
//例如N=6，M=5，出列人的序号为5，4，6，2，3。最后剩下1号。
//*/
//struct Node {
//	int val;
//	struct Node* next;
//	Node() : val(0), next(nullptr) { }
//	Node(int _val): val(_val), next(nullptr) { }
//};
//
////下面实现一个循环链表：
//class circular_list {
//public:
//	circular_list() {
//		this->head = new Node(1);
//		this->head->next = this->head;
//	}
//
//	void insert(int _val) {		//头插法插入一个节点到循环链表当中
//		struct Node* newNode = new Node(_val);
//		newNode->next = this->head->next;
//		this->head->next = newNode;
//		newNode = nullptr;
//	}
//
//	struct Node* head;
//};
//
//int main(void) {
//	int N = 0, M = 0;		//N个人，数到第M个人出列
//	cin >> N >> M;
//
//	circular_list clist = circular_list();
//	for (int i = N; i >= 2; i--) clist.insert(i);		//插入N个节点表示N个人
//
//	struct Node* ptr = clist.head;
//	int count = 1;
//	cout << "出列序列为：";
//	while (ptr->next != ptr) {
//		if (count == M) {
//			struct Node* n = ptr->next;
//
//			cout << ptr->val << " ";
//			ptr->val = ptr->next->val;
//			ptr->next = ptr->next->next;
//
//			n->next = nullptr;
//			delete(n);
//			n = nullptr;
//
//			count = 1;
//		}
//		else {
//			ptr = ptr->next;
//			count++;
//		}
//	}
//	cout << endl << "最后一个人为：" << ptr->val;
//
//	ptr->next = nullptr;
//	delete(ptr);
//	ptr = nullptr;
//
//	return 0;
//}