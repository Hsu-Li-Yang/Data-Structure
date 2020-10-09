#include <iostream>
using namespace std;



struct ListNode{

	int val;
	ListNode *next;

	ListNode(): val(0),next(nullptr){}
	ListNode(int a): val (a), next(nullptr){}
	ListNode(int a,ListNode*b): val (a),next(b){}

};

void push_front(ListNode **head,int x){
	if(*head == nullptr) *head = new ListNode(x);
	else{
	ListNode *frontNode = new ListNode(x);
	frontNode->next = *head;
	*head = frontNode;
	}
}

void push_back(ListNode *head,int x){

	ListNode *tmp = head;
	while(tmp->next){
		tmp = tmp->next;
	} 
	tmp->next = new ListNode(x);
}

void Delete(ListNode **head,int x){

	ListNode *pre,*cur=*head;
	while(cur && cur->val != x ){
		pre = cur;
		cur = cur->next;
	}
	if(!cur) {cout<<"not found!"<<endl;}
	else if(cur ==  *head){
		*head = (*head)->next;
		delete cur;
		cur = nullptr;

	}
	else{
		pre->next = cur->next;
		delete cur;
		cur = nullptr;
	} 
}

void Reverse(ListNode **head){
	if(*head == nullptr || (*head)->next == nullptr) return;

	ListNode *pre = nullptr,*cur = *head,*next;
	while(cur){
		next = cur->next;
		cur->next = pre;

		pre = cur;
		cur = next;

	}
	*head = pre;
}
ListNode* find_middle(ListNode *head){
	ListNode*fast=head,*slow=head;
	while(fast->next && fast->next->next){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
void report(ListNode *head){
		
	ListNode *tmp = head;
	if(tmp) cout<<tmp->val;
	while(tmp->next){
		tmp = tmp->next;
		cout<<"->"<<tmp->val;
	}
	cout<<endl;
}

int main()
{

	ListNode *head = new ListNode(5);
	cout<<"create ListNode =5:"<<endl;
	report(head);

	push_front(&head,10);
	cout<<"After Push_front 10:"<<endl;
	report(head);

	push_back(head,30);
	cout<<"After Push_back 30:"<<endl;
	report(head);

	Reverse(&head);
	cout<<"After Reverse:"<<endl;
	report(head);

	ListNode *middle = find_middle(head);
	cout<<"middle="<<middle->val<<endl; 

	Delete(&head,10);
	cout<<"After delete 10:"<<endl;
	report(head);

	cout<<"After delete 50:"<<endl;
	Delete(&head,50);
	
	
	Delete(&head,30);
	cout<<"After delete 30:"<<endl;
	report(head);
	return 0;
}
