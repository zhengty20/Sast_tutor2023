#include<iostream>
using namespace std;

//交换操作
template<class T>
inline void exch(T* e1, T* e2)
{
	T tmp;
	tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

//比较-交换操作，保证二元组从小到大有序
template<class T>
bool compExch(T* e1, T* e2)
{
	if (*e1 > *e2) {
		exch(e1, e2); return true;
	}
	else return false;
}

//冒泡排序
template<class T>
void bubble_sort(T* a, int left, int right)//对第left+1到第right+1个元素进行排序
{
	int i, j;
	for (i = left; i < right; i++)//n-1趟冒泡，第i次冒泡
	{
		for (j = right; j > i; j--)//第i次冒泡要进行n-i次比较和交换操作
		{
			compExch(a + j - 1, a + j);
		}
	}
}

//经过改进的冒泡排序
template<class T>
void bubble_sort_improved(T* a, int left, int right)//对第left+1到第right+1个元素进行排序
{
	int i, j;
	for (i = left; i < right; i++)//n-1趟冒泡，第i次冒泡
	{
		int flag = false;
		for (j = right; j > i; j--)//第i次冒泡要进行n-i次比较和交换操作
		{
			if (compExch(a + j - 1, a + j))//如果发现有逆序，将标志置为true
			{
				flag = true;
			}
		}
		if (flag == false)return;//如果这一趟冒泡没有逆序，返回
	}
}

template<class T>
void insert_sort(T* a, int left, int right)
{
	int i, j;
	T tTag;
	for (i = right; i > left; i--)//一次冒泡，将最小的元素放在最前面，避免负溢
	{
		if (a[i - 1] > a[i])exch(a + i - 1, a + i);
	}
	for (i = left + 2; i <= right; i++)//表示本次进行插入操作的元素下标
	{
		j = i;//记录位置
		tTag = a[i];//记录元素大小
		while (tTag < a[j - 1])//如果满足，此处不是插入位置，再往前寻找小于或等于tTag的位置
		{
			a[j] = a[j - 1];//挪位置
			j--;
		}
		a[j] = tTag;//插入
	}
}

template<class T>
void insert_bisort(T* a, int l, int r)
{
	int i, j, right, left, middle;
	T e;
	for (i = l + 1; i <= r; i++)
	{
		e = a[i];//当前插入的元素
		left = l; right = i - 1;//折半查找范围
		while (left <= right)//折半查找
		{
			middle = (left + right) / 2;//中间位置
			if (e < a[middle])right = middle - 1;
			else left = middle + 1;
		}//确定插入位置
		for (j = i - 1; j >= left; j--)a[j + 1] = a[j];//成块向后移动，空出插入位置
		a[left] = e;//插入
	}
}

//template<class T>
//void shell_insert_sort(T* a, int left, int right,int gap)
//{
//	int i, j;
//	T tTag;
//	for (i = right; i > left; i--)//一次冒泡，将最小的元素放在最前面，避免负溢
//	{
//		if (a[i - 1] > a[i])exch(a + i - 1, a + i);
//	}
//	for (i = left + 2; i <= right; i++)//表示本次进行插入操作的元素下标
//	{
//		j = i;//记录位置
//		tTag = a[i];//记录元素大小
//		while (tTag < a[j - 1])//如果满足，此处不是插入位置，再往前寻找小于或等于tTag的位置
//		{
//			a[j] = a[j - 1];//挪位置
//			j--;
//		}
//		a[j] = tTag;//插入
//	}
//}

template<class T>
void shell_sort(T* a, int left, int right)
{
	int shellh[3] = { 1, 2, 5 };
	for (int i = 2; i >= 0; i--)//选择本次排序的gap
	{
		int gap = shellh[i];
			for (int j = left; j < left+gap; j++)//分为gap个组，组内进行直接插入排序
			{
				for (int k = j + gap; k <= right; k += gap)//直接插入排序
				{
					T temp = a[k];
					int s = k - gap;
					while (s >= left && temp < a[s])//s>=left避免负溢
					{
						a[s + gap] = a[s];
						s -= gap;
					}
					a[s + gap] = temp;
				}
			}
	}
}

template<class T>
void select_sort(T* a, int left, int right)
{
	int i, j, min;
	for (i = left; i < right; i++)//从第一个到第n-1个位置
	{
		min = i;
		for (j = i + 1; j <= right; j++)
			//选择该位置及之后所有位置中最小值的下标
			if (a[j] < a[min])min = j;
		exch(a + i, a + min);//和i位置交换
	}
}

//快速排序
// 三数取中
template<class T>
void MiddleOfThree(T* a, int left, int right)
{
	int middle = (left + right) / 2;
	if (a[middle] > a[right])exch(a + middle, a + right);
	if (a[left] > a[right])exch(a + left, a + right);
	if (a[left] > a[middle])exch(a + left, a + middle);
	exch(a + middle, a + right);
}

//划分操作
template<class T>
int partition(T* a, int left, int right)//划分 返回划分位置
{
	int i = left - 1, j = right;
	MiddleOfThree(a, left, right);
	T e = a[right];
	while (1)
	{
		while (a[++i] <= e)if (i == right)break;
		while (e <= a[--j])if (j == left)break;
		if (i >= j)break;
		exch(a + i, a + j);
	}
	exch(a + i, a + right);
	return i;
}
//递归实现
template<class T>
void quick_sort(T* a, int left, int right)
{
	if (right <= left)return;
	int i = partition(a, left, right);
	quick_sort(a, left, i - 1);
	quick_sort(a, i + 1, right);
}

template<class T>
void merge(T* a, int p1, int p2, int p3)//经过修正的
{
	long i, j, k;
	T* c = new T[p3 - p1 + 1];
	for (i = 0, j = 0, k = 0; k < p3 - p1+1; k++)
	{
		if (i == p2 - p1) { c[k] = a[p2+j]; j++; continue; }
		if (j == p3-p2+1) { c[k] = a[p1+i]; i++; continue; }
		if (a[p1 + i] <= a[p2 + j]) { c[k] = a[p1 + i]; i++; }
		else { c[k] = a[p2 + j]; j++; }
	}
	for (i = 0; i < p3-p1+1; i++)
	{
		a[p1+i] = c[i];
	}
	delete[] c;
}

template<class T>
void merge_sort(T* a, int left, int right)
{
	int i, m;
	for (m = 1; m < right - left; m = m + m)//每次循环m翻倍
	{
		for (i = left; i <= right - m; i += m + m)
		{
			merge(a, i, i + m, min(i + m + m - 1, right));
		}
	}
}

//链表结构单位
struct Node {
	int val;
	Node* next;
};

//node -- 链表表头
Node* MergeSort(Node* node) {
	//先判断链表长度是否大于1，小于1时无须排序
	if (node != NULL && node->next != NULL) {
		//运用快慢指针，找到链表的中间节点
		Node* fast = node->next;
		Node* slow = node;
		while (fast != NULL && fast->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}

		//将链表分成两部分进行分割
		Node* p1 = MergeSort(slow->next);
		slow->next = NULL;                 
		Node* p2 = MergeSort(node);
		//对两条子链进行归并
		Node* p0 = (Node*)malloc(sizeof(Node));
		Node* p = p0;
		while (p1 != NULL && p2 != NULL) {
			if (p1->val < p2->val) { p->next = p1; p1 = p1->next; }
			else { p->next = p2; p2 = p2->next; }
			p = p->next;
		}
		if (p1 != NULL) p->next = p1;
		if (p2 != NULL) p->next = p2;
		p = p0->next;free(p0);
		return p;
	}
	return node;
}

template<class T>
void merge_sort2(T* a, int left, int right)
{
	if (right <= left)return;//子序列的长度小于等于1
	int m = (left + right) / 2;//取中间位置
	merge_sort2(a, left, m);//左右分别递归排序
	merge_sort2(a, m + 1, right);
	merge(a, left, m+1, right);
}

int main()
{
	int a[13] = { 1,4,63,5,73,3,74,24,54,11,35,8,12 };
	//bubble_sort_improved<int>(a, 0, 12);
	//insert_sort<int>(a, 0, 12);
	//insert_bisort<int>(a, 0, 12);
	//shell_sort<int>(a, 0, 12);
	//select_sort(a, 0, 12);
	//quick_sort(a, 0, 12);
	//merge_sort(a, 0, 12);
	merge_sort2(a, 0, 12);
	for (int i = 0; i < 13; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}