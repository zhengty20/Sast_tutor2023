//类实现
class BinaryTree {
private:
	TNODE* root									//根结点
public:
	BinaryTree() { root = NULL; }]				//构造函数
	~BinaryTree() { };							//析构函数
	void CreateBiTree(char* POS, char* IOS);	//创建二叉树
	void ClearBiTree();							//清空二叉树
	bool IsEmpty() { return root == NULL; }		//判断树是否为空
	int GetDepth(TNODE* t); 					//求树的高度
	void Assign(TNODE* e, ElemType value)		//给树结点赋值
	{
		e->data = value;
	}
};

//顺序存储
#define MAX_TREE_SIZE 100						//二叉树的最大节点数 
typedef TElemType SqBiTree[MAX_TREE_SIZE];
typedef struct
{
	int level, order;
}position;					//节点的层数与序列数

//二叉链表存储
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;			//左、右子节点
}BiTNode, * BiTree;

//三叉链表存储
typedef struct BiTPNode {
	TElemType data;
	struct BiTPNode* parent, * lchild, * rchild;//父节点、左、右子节点
}BiTPNode, * BiPTree;

//先序遍历
void pre_order_traversal(TreeNode* root)
{
	// Do Something with root
	if (root->lchild != NULL)					//若其中一侧的子树非空则会读取其子树
		pre_order_traversal(root->lchild);
	if (root->rchild != NULL)					//另一侧的子树也做相同事
		pre_order_traversal(root->rchild);
}

//中序遍历
void in_order_traversal(TreeNode* root)
{
	if (root->lchild != NULL)					//若其中一侧的子树非空则会读取其子树
		in_order_traversal(root->lchild);
	// Do Something with root
	if (root->rchild != NULL)					//另一侧的子树也做相同事
		in_order_traversal(root->rchild);
}

//后序遍历
void post_order_traversal(TreeNode* root)
{
	if (root->lchild != NULL)					//若其中一侧的子树非空则会读取其子树
		post_order_traversal(root->lchild);
	if (root->rchild != NULL)					//另一侧的子树也做相同事
		post_order_traversal(root->rchild);
	// Do Something with root
}

//层序遍历
void level(TreeNode* node)
{
	Queue* queue = initQueue();
	enQueue(queue, node);
	while (!isQueueEmpty(queue))
	{
		TreeNode* curr = deQueue(queue);		//当前层次的节点出队进行遍历操作
		// Do Something with curr
		if (curr->lchild != NULL)
			enQueue(queue, curr->lchild);		//下一层的左子节点入队
		if (curr->rchild != NULL)
			enQueue(queue, curr->rchild);		//下一层的右子节点入队
	}
}

//输出二叉树
void BinaryTree::OutBT(TNODE* t)				//先序遍历
{
	if (t)
	{
		cout << t->data;
		if (t->LChild != NULL || t->RChild != NULL)
		{
			cout << ‘(’;
			OutBT(t->LChild);
			cout << ‘, ’;
			if (t->RChild != NULL)
				OutBT(t->RChild);
			cout << ‘)’;
		}
	}
}

//求深度
int BinaryTree::BTDepth(TNODE* t)				//后序遍历
{
	int depth;
	if (t == NULL) return FALSE;
	if (t->LChild = = NULL && t->RChild = = NULL)
		depth = 1;
	else
	{
		if (BTDepth(t->LChild) > BTDepth(t->RChild))
			depth = 1 + BTDepth(t->lChild);
		else
			depth = 1 + BTDepth(t->rChild);
	}
	return depth;
}

//清空
void BinaryTree::ClearBT(TNODE* t)				//后序遍历
{
	if (t)
	{
		ClearBT(t->LChild);
		ClearBT(t->RChild);
		delete t;
		t = NULL;
	}
}