#include <iostream>
using namespace std;

class QueueArraySequential{
private:
    int capacity, front, back;
    int *queue;
    void DoubleCapacity();
public:
    QueueArraySequential():capacity(5),front(0),back(0){
        queue = (int*)malloc(sizeof(int)*capacity);
    };
    void Push(int x);
    void Pop();
    bool IsEmpty();
    bool IsFull();
    int getFront();
    int getBack();
    int getSize();
    int getCapacity();    // 驗證用, 可有可無
};

void QueueArraySequential::DoubleCapacity(){
    
    int *newqueue = (int*)malloc(sizeof(int)*capacity*2);
    int j=front;
    int size = getSize();
    for(int i=1;i<=size;i++){
        newqueue[i] = queue[++j % capacity];
    }
    front = 0;
    back = size;
    free(queue);
    queue = newqueue;
    capacity *=2;
}

void QueueArraySequential::Push(int x){
    if(IsFull()){
        DoubleCapacity();
    }
    back = (back +1) % capacity;
    queue[back] = x;
}

void QueueArraySequential::Pop(){
    if(IsEmpty()){
        cout<<"Queue is Empty!";
        return;
    }
    front  = (front+1) %capacity ;
}
bool QueueArraySequential::IsEmpty(){

    return (front==back);
}

bool QueueArraySequential::IsFull(){
    return (back +1) % capacity == front;
}

int QueueArraySequential::getFront(){
    if(IsEmpty()) return -1;
    return queue[(front+1)%capacity];
}

int QueueArraySequential::getBack(){
    if(IsEmpty()) return -1;
    return queue[back];
}

int QueueArraySequential::getSize(){
    if(back > front) return back-front;
    else return capacity - (front  - back  -1);
}

int QueueArraySequential::getCapacity(){
    return capacity;
}

void printSequentialQueue (QueueArraySequential queue){
    cout << "front: " << queue.getFront() << "    back: " << queue.getBack() << "\n"
    << "capacity: " << queue.getCapacity() << "  number of elements: " << queue.getSize() << "\n\n";
}
int main(){

    QueueArraySequential q;
    if (q.IsEmpty()) {
        cout << "Queue is empty.\n\n";
    }
    q.Push(24);
    cout << "After push 24: \n";
    printSequentialQueue(q);
    q.Push(8);
    q.Push(23);
    cout << "After push 8, 23: \n";
    printSequentialQueue(q);
    q.Pop();
    cout << "After pop 24: \n";
    printSequentialQueue(q);
    q.Push(13);
    cout << "After push 13: \n";
    printSequentialQueue(q);
    q.Pop();
    cout << "After pop 8: \n";
    printSequentialQueue(q);
    q.Push(35);
    cout << "After push 35: \n";
    printSequentialQueue(q);
    q.Push(9);
    cout << "After push 9: \n";
    printSequentialQueue(q);

    return 0;
}
