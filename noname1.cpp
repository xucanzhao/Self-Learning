#includde<iostream>
using namespace std;

//����AVLTree�Ľṹ 
struct AVLTreeNode
{
	AVLTreeNode(T vale AVLTreeNode<T>*1,AVLTreeNode<T>*r)
	:key(value),lchild(1),rchild(r){}
	
	T key;
	int height;
	AVLTreeNode<T>* lchild;
	AVLTreeNode<T>* rchild;
} ;

//AVL���ĳ������ݽṹ
template<typename T>
class AVLTree
{
public:
	ATVTree();   //���캯��
	~AVLTree();	//��������
	
	void proOrder();	//	ǰ�����AVL��
	void InOrder();		//�������AVL��
	void postOrder();	//�������AVL��
	
	void print();		//��ӡAVL��
	void destory();		//����AVL��
	
	void insert(T key);	//	����ָ��ֵ�Ľڵ�
	void remove(T key);	//	�Ƴ�ָ��ֵ�Ľڵ�
	
	AVLTreeNode<T>* search_recurse(T key);	//���õݹ�˫�����в���ָ����ֵ
	AVLTreeNode<T>* search_iterator(T key);	//���õ���˫������ָ��ֵ����
	
	T minimum();	//����AVL����Сֵ
	T maximum();	//����AVL�����ֵ
	
	int height();		//�������ĸ߶�
private:
	AVLTreeNode<T>* root;	//AVL���ĸ��ڵ�
	
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


//���õݹ�ɾ��AVL��ֵkey 
template<typename T>
AVLTreeNode<T>* AVLTree<T>::remove(AVLTreeNode<T>* &pnode,T key)
{
	if(pnode!=nullptr)
		{
			if(key==pnode->key)
			{
				//�жϽڵ�����ҽڵ�����������°������ҽڵ�
				if(pnode->lchild!=nullptr&&pnode->rchild!=nullptr)
					{
							//��ڵ���ҽڵ�ߵĻ���ɾ����ڵ� 
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
					//key�ڽڵ����ڵ�
					pnode->lchild=remove(pnode->lchild,key);
					 if(height(pnode->rchild)-height(pnode->lchild)==2))
					//�൱�����ҽڵ������һ���ڵ�
					{
						if(height(pnode->rchild->lchild)>height(pnode->rchild->rchild))
						//RL��ת
							pnode->lchild=rightLeftRotation(pnode->lchild); 
						else
							pnode->lchild=rightRotation(pnode->lchild);
					}
				
				}
		}	
		
}