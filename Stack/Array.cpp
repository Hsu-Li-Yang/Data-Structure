#include <iostream>
using namespace std;

class Stack{
private:
	int *data;
	int top;
	int capacity;
	void DoubleCapacity();
public:
	Stack(): top(-1),capacity(1){
		data = (int*)malloc(sizeof(int));
	}
	Stack(int size): top(-1),capacity(size){
		data = (int*)malloc(sizeof(int)*size);
	}

	void Push(int x);
	void Pop();
	int getSize();
	int Top();
	bool isEmpty();
};

void Stack::DoubleCapacity(){

	capacity *=2;
	int *newstack = (int*)malloc(sizeof(int)*capacity);
	for(int i=0;i<capacity/2;++i){
		newstack[i] = data[i];
	}
	free(data);
	data = newstack;
}

void Stack::Push(int x){

	if(top == capacity-1) DoubleCapacity();
	data[++top] = x;

}
int Stack::Top(){
	return data[top];
}
void Stack::Pop(){
	if(isEmpty()) {
		cout<<"Stack is Empty!";
		return;
	}
	top--;
}

bool Stack::isEmpty(){
	
	return (top == -1);
}

int Stack::getSize(){
	return top+1;
}

int main(){

    Stack s;
    s.Pop();
    s.Push(14);
    s.Push(9);
    cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << endl;

    s.Push(7);
    cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << endl;
    s.Pop();
    s.Pop();
    cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << endl; 
    s.Pop();
    cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << endl;

    return 0;
}
