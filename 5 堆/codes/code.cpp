#include<iostream>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

class MinHeap
{
	int *arr; // 指向堆中元素数组的指针
	int capacity; // 最大容量
	int size; //当前堆的大小
public:
	//初始化
    MinHeap(int capacity);
    //由数组表示返回堆节点的父/子节点
    int parent(int i) { return (i-1)/2; }
	int left(int i) { return (2*i + 1); }
	int right(int i) { return (2*i + 2); }
    
	// 用给定索引处的根来堆积子树
	void Heapify(int k);

	// 提取作为最小元素的根
	int getMin();

	// 将索引 i 处的键的键值减小到 new_val
	void decreaseKey(int i, int new_val);

	// 返回堆顶
	int getMin() { return arr[0]; }

	// 删除索引为i的词条
	void delKey(int i);

	// 添加一个值为k的词条
	void addKey(int k);

	// 自顶向下调整
	void ModDown(int k);

	void ModUp(int k)
};

MinHeap::MinHeap(int cap)
{
	size = 0;
	capacity = cap;
	arr = new int[cap];
}


void MinHeap::addKey(int k)
{
	if (size == capacity)
	{
		cout << "\n超载:不能添加key\n";
		return;
	}

	// 首先在末尾插入新key
	size++;
	int i = size - 1;
	arr[i] = k;

	// 如果违反了最小堆属性，则修复之
	while (i != 0 && arr[parent(i)] > arr[i])
	{
	    swap(&arr[i], &arr[parent(i)]);
	    i = parent(i);
	}
}

// 将索引i处的键值减小到 new_val。 假设new_val小于arr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
	arr[i] = new_val;
	while (i != 0 && arr[parent(i)] > arr[i])
	{
	    swap(&arr[i], &arr[parent(i)]);
	    i = parent(i);
	}
}

// 从最小堆中删除最小元素（或根）的方法
int MinHeap::getMin()
{
	if (size <= 0)
		return INT_MAX;
	if (size == 1)
	{
		size--;
		return arr[0];
	}

	// 存储最小值，并将其从堆中删除
	int root = arr[0];
	arr[0] = arr[size-1];
	size--;
	Heapify(0);

	return root;
}


// 此函数删除索引 i 处的键。 它首先将值减小到负无穷大，然后调用 getMin()
void MinHeap::delKey(int i)
{
	decreaseKey(i, INT_MIN);
	getMin();
}

// 一种递归方法，用于在给定索引处堆积具有根的子树
// 该方法假设子树已经堆化
void MinHeap::Heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int tmp = i;
	if (l < size && arr[l] < arr[i])
		tmp = l;
	if (r < size && arr[r] < arr[tmp])
		tmp = r;
	if (tmp != i)
	{
		swap(&arr[i], &arr[tmp]);
		Heapify(tmp);
	}
}

void Minheap::ModDown(int k){
    //k为已知的出现问题节点的index
	int i;
	i = 2*k+1; 											
	while(i < heapSize) {
		if(i < heapSize-1 && heap[i] < heap[i+1]) 		
			i++;
		if(heap[k] > heap[i]) break; 					
		swap(heap[k],heap[i]); 							
		k = i; 											//新的当前结点位置
		i = 2*k+1; 										//新的左孩子结点位置
	}
}

void Minheap::ModUp(int k) {
	int i;
	i = (k-1)/2; 
	while(k > 0 && heap[i] < heap[k]) { 
		swap(heap[k],heap[i]); 
		k = i; 			//新的当前结点
		i = (k-1)/2; 	//新的父亲结点
	}	
}
