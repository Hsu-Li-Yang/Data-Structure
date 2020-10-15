## Max Binary Heap

```
class BinaryHeap{
private:
	vector<int> heap;
	void swap(int &a,int &b){
		int tmp = b;
		b=a;
		a=tmp;
	}
	
public:
	BinaryHeap(){
		heap.resize(1);
	}
	BinaryHeap(int n){
		heap.resize(n+1);
	}
	bool Isempty(){
		return heap.empty();
	}
	void push(int x);
	void pop();
	void sink(int pos);
	void swim(int pos);
	void report(){
		cout<<"Heap = [";
		for(int i=1;i<heap.size();++i){
			cout<<heap[i]<<",";
		}
		cout<<"\b";
		cout<<"]"<<endl;
	}
	int top(){ return heap[1];}


};
```

```
void BinaryHeap::push(int x){
	
	heap.push_back(x);
	swim(heap.size()-1);
}

void BinaryHeap::pop(){
	heap[1] = heap.back();
	heap.pop_back();
	sink(1);
}

void BinaryHeap::sink(int pos){
	int n = heap.size();
	while(2*pos <= n){

		int i = 2*pos;
		if(i<n && heap[i] < heap[i+1]) {i++;}
		if(heap[pos]>=heap[i]) {break;}
		swap(heap[pos],heap[i]);
		pos = i;

	}
}

void BinaryHeap::swim(int pos){

	while(pos>1 && heap[pos/2] < heap[pos]){
		swap(heap[pos/2],heap[pos]);
		pos /=2;
	}
}
```


## Test
```
int main(){

	BinaryHeap heap;
	cout<<"push 5,20,16,13,9"<<endl;
	heap.push(5);
	heap.push(20);
	heap.push(16);
	heap.push(13);
	heap.push(9);

	heap.report();
	cout<<heap.top()<<endl;

	cout<<"pop"<<endl;
	heap.pop();
	heap.report();
	cout<<heap.top()<<endl;

}
```
![img1](https://github.com/Hsu-Li-Yang/Data-Structure/blob/main/Heap/img1.png)
