#include<iostream>
using namespace std;

template<class T>
struct BSTreeNode{
	BSTreeNode<T>* _pLeft;
	BSTreeNode<T>* _pRight;
	T _data;

	BSTreeNode(const T& data)
		: _pLeft(NULL)
		, _pRight(NULL)
		, _data(data)
	{}
};

template<class T>
class BSTree{
	typedef BSTreeNode<T> Node;
	typedef Node* PNode;
public:
	BSTree()
		: _pRoot(NULL)
	{}
	bool Insert(const T& data)
	{
		if (NULL == _pRoot){
			_pRoot = new Node(data);
			return true;
		}
		PNode pCur = _pRoot;
		PNode pParent = NULL;
		while (pCur){
			if (data < pCur->_data){
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else if (data > pCur->_data){
				pParent = pCur;
				pCur = pCur->_pRight;
			}
			else
				return false;
		}
		pCur = new Node(data);
		if (data < pParent->_data)
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;
		return true;
	}
	void Find(const T& data)
	{
		PNode pCur = _pRoot;
		while (pCur){
			if (pCur->_data == data)
				return pCur;
			else if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else
				pCur = pCur->_pRight;
		}
		return NULL;
	}
	bool Delete(const T& data)
	{
		PNode pCur = _pRoot;
		PNode pParent = NULL;
		while (pCur){
			if (pCur->_data == data)
				break;
			else if (data > pCur->_data){
				pParent = pCur;
				pCur = pCur->_pRight;
			}
			else{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
		}
		if (pCur == NULL)
			return false;

		if (NULL == pCur->_pRight){
			if (pCur == _pRoot)
				_pRoot = pCur->_pLeft;
			else{
				if (pCur == pParent->_pLeft)
					pParent->_pLeft = pCur->_pLeft;
				else
					pParent->_pRight = pCur->_pLeft;
			}
		}
		else if (NULL == pCur->_pLeft){
			if (pCur == _pRoot)
				_pRoot = pCur->_pRight;
			else{
				if (pCur == pParent->_pRight)
					pParent->_pRight = pCur->_pRight;
				else
					pParent->_pLeft = pCur->_pRight;
			}
		}
		else{
			PNode pDel = pCur->_pRight;
			pParent = pCur;
			while (pDel->_pLeft){
				pParent = pDel;
				pDel = pDel->_pLeft;
			}
			pCur->_data = pDel->_data;
			if (pDel==pParent->_pLeft)
				pParent->_pLeft = pDel->_pRight;
			else
				pParent->_pRight = pDel->_pRight;

			pCur = pDel;
		}
		delete pCur;
		return true;
	}

	void InOrder(){
		cout << "InOrder:";
		_InOrder(_pRoot);
		cout << endl;
	}
private:
	void _InOrder(PNode pRoot)
	{
		if (pRoot){
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}
private:
	PNode _pRoot;
};


void test(){
	int arr[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> bs;
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		bs.Insert(arr[i]);
	bs.InOrder();
	bs.Delete(5);
	bs.InOrder();
}


int main(){
	test();
	return 0;
}

