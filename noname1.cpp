#includde<iostream>
using namespace std;

//申明AVLTree的结构 
struct AVLTreeNode
{
	AVLTreeNode(T vale AVLTreeNode<T>*1,AVLTreeNode<T>*r)
	:key(value),lchild(1),rchild(r){}
	
	T key;
	int height;
	AVLTreeNode<T>* lchild;
	AVLTreeNode<T>* rchild;
} ;

//AVL树的抽象数据结构
template<typename T>
class AVLTree
{
public:
	ATVTree();   //构造函数
	~AVLTree();	//析构函数
	
	void proOrder();	//	前序遍历AVL树
	void InOrder();		//中序遍历AVL树
	void postOrder();	//后序遍历AVL树
	
	void print();		//打印AVL树
	void destory();		//销毁AVL树
	
	void insert(T key);	//	插入指定值的节点
	void remove(T key);	//	移除指定值的节点
	
	AVLTreeNode<T>* search_recurse(T key);	//利用递归双方进行查找指定的值
	AVLTreeNode<T>* search_iterator(T key);	//利用迭代双方进行指定值查找
	
	T minimum();	//返回AVL中最小值
	T maximum();	//返回AVL中最大值
	
	int height();		//返回树的高度
private:
	AVLTreeNode<T>* root;	//AVL树的跟节点
	
private:
	void preOrder(AVLTreeNode<T>* pnode) const;
	void inOrder(AVLTreeNode<T>* pnode) const;
	void postOrder(AVLTreeNode<T>* pnode) const;
	
	void print(AVLTreeNode<T>* pnode,T key, int direction) const;
	void destory(AVLTreeNode<T>* &pnode);
	
	AVLTreeNode<T>* insert(AVLTreeNode<T>* &pnode,T key);
	AVLTreeNode<T>* remove(AVLTreeNode<T>* &pnode,AVLTreeNode<T>* pdel);
	
	AVLTreeNode<T>* minimum(AVLTreeNode<T>*pnode)const;
    AVLTreeNode<T>* maximum(AVLTreeNode<T>*pnode)const;

	AVLTreeNode<T>* search_recurse(AVLTreeNode<T>* pnode, T key) const;
    AVLTreeNode<T>* search_iterator(AVLTreeNode<T>* pnode, T key) const;

	AVLTreeNode<T>* leftRoration(AVLTreeNode<T>* pnode);
	AVLTreeNode<T>* rightRotation(AVLTreeNode<T>* pnode);
	AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* pnode);
	AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* pnode);
}


//利用递归删除AVL的值key 
template<typename T>
AVLTreeNode<T>* AVLTree<T>::remove(AVLTreeNode<T>* &pnode,T key)
{
	if(pnode!=nullptr)
		{
			if(key==pnode->key)
			{
				//判断节点的左右节点的数量，以下包含左右节点
				if(pnode->lchild!=nullptr&&pnode->rchild!=nullptr)
					{
							//左节点比右节点高的话，删除左节点 
						if(height(pnode->lchild)>height(pnode->rchild))
							{
								AVLTreeNode<T>* psucc=maximum(pnode->lchild);
								pnode->key=psucc->key;
								pnode->lchild=remove(pnode->lchild,psucc->key);	
							}
						else
							{
								AVLTreeNode<T>* psucc=minimum(pnode->rchild);
								pnode->key=psucc->key;
								pnode->rchild=remove(pnode->rchild,psucc->key);
							}
					} 
				else
					{
						AVLTreeNode<T>* ptemp=pnode;
						if(pnode->lchild!=nullptr)
							pnode=pnode->lchild;
						else if(pnode->rchild!=nullptr)
							pnode=pnode->rchild
						delete ptemp;
					//????	pnode->height--;
						return nullptr;
					}
			}
			else if(key<pnode->key)
				{
					//key在节点的左节点
					pnode->lchild=remove(pnode->lchild,key);
					 if(height(pnode->rchild)-height(pnode->lchild)==2))
					//相当于在右节点添加了一个节点
					{
						if(height(pnode->rchild->lchild)>height(pnode->rchild->rchild))
						//RL旋转
							pnode->lchild=rightLeftRotation(pnode->lchild); 
						else
							pnode->lchild=rightRotation(pnode->lchild);
					}
				
				}
		}	
		
}