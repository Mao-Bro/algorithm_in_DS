//#include <iostream>
//
//using namespace std;
//
///*
//							������Լɪ�����⣺
//N����Χ��һȦ���ӵ�һ����ʼ��������M���˳��У�����ѭ������˳����������˵ı�š�
//����N=6��M=5�������˵����Ϊ5��4��6��2��3�����ʣ��1�š�
//*/
//struct Node {
//	int val;
//	struct Node* next;
//	Node() : val(0), next(nullptr) { }
//	Node(int _val): val(_val), next(nullptr) { }
//};
//
////����ʵ��һ��ѭ������
//class circular_list {
//public:
//	circular_list() {
//		this->head = new Node(1);
//		this->head->next = this->head;
//	}
//
//	void insert(int _val) {		//ͷ�巨����һ���ڵ㵽ѭ��������
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
//	int N = 0, M = 0;		//N���ˣ�������M���˳���
//	cin >> N >> M;
//
//	circular_list clist = circular_list();
//	for (int i = N; i >= 2; i--) clist.insert(i);		//����N���ڵ��ʾN����
//
//	struct Node* ptr = clist.head;
//	int count = 1;
//	cout << "��������Ϊ��";
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
//	cout << endl << "���һ����Ϊ��" << ptr->val;
//
//	ptr->next = nullptr;
//	delete(ptr);
//	ptr = nullptr;
//
//	return 0;
//}