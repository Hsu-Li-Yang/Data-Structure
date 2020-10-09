#include <iostream>
using namespace std;

class StackNode{
private:
	int data;
	StackNode *next;
public:

	StackNode(): data(0),next(nullptr){}
	StackNode(int x): data(x),next(nullptr){}
	StackNode(int x,StackNode *s): data(x),next(s){}
	friend class StackList;

};

class StackList{
private:
	
	StackNode *top;
	int size;
	
public:
	StackList(): top(nullptr),size(0){}

	void Push(int x);
	void Pop();
	int getSize();
	int Top();
	bool isEmpty();
};



void StackList::Push(int x){

	if(isEmpty()){
		top = new StackNode(x);
		size++;
		return;
	}

	StackNode *cur = new StackNode(x);
	cur->next = top;
	top = cur;
	size++; 

}
int StackList::Top(){
	if(isEmpty()) {
		cout<<"Stack is Empty!";
		return -1;
	}
	return top->data;
}

void StackList::Pop(){
	if(isEmpty()) {
		cout<<"Stack is Empty!";
		return;
	}
	StackNode * cur = top;
	delete cur;
	cur = nullptr;

	top = top->next;
	size--;
}

bool StackList::isEmpty(){
	
	return (size==0);
}

int StackList::getSize(){
	return size;
}

int main(){

    StackList s;
    s.Pop();
    s.Push(32);
    s.Push(4);
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;        
    s.Push(15);
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;         
    s.Pop();
    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;          
    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;

    return 0;
}