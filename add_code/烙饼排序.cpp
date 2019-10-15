#include<iostream>
#include<assert.h>
using namespace std;

/****************/
//
//烙饼排序的实现
//
/****************/
class CPrefixSorting {
private:
	int* m_CakeArray;     //烙饼信息数组
	int m_nCakeCnt;       //烙饼个数
	int m_nMaxSwap;       //最多交换次数。根据前面的推断，这里最多为(m_nCakeCnt-2)*2+1
	int* m_SwapArray;     //交换结果数组
	int* m_ReverseCakeArray;      //当前翻转烙饼信息数组
	int* m_ReverseCakeArraySwap;  //当前翻转烙饼交换结果数组
	int m_nSearch;                //当前搜索次数信息

public:
	CPrefixSorting(){   //构造函数
		m_nCakeCnt = 0;
		m_nMaxSwap = 0;
	}
	~CPrefixSorting() {  //析构函数
		if (m_CakeArray != NULL) {
			delete  m_CakeArray;
		}
		if (m_SwapArray != NULL) {
			delete m_SwapArray;
		}
		if (m_ReverseCakeArray != NULL) {
			delete m_ReverseCakeArray;
		}
		if (m_ReverseCakeArraySwap != NULL) {
			delete m_ReverseCakeArraySwap;
		}
	}

	//
	//计算烙饼翻转信息
	//@param
	//pCakeArray  存储烙饼索引数组
	//nCakeCnt     烙饼个数
	//
	void Run(int* pCakeArray, int nCakeCnt) {
		Init(pCakeArray, nCakeCnt);
		m_nSearch = 0;
		Search(0);
	}

	//
	//输出烙饼翻转次数
	//
	void Output() {
		for (int i = 0; i < m_nMaxSwap; i++) {
			cout << m_SwapArray[i] << " ";
		}
		cout << endl << " |Search Times| : " << m_nSearch << endl;
		cout << "Total Swap Times = " << m_nMaxSwap << endl;
	}

private:
	//
	//初始化数组信息
	//@param
	//pCakeArray  存储烙饼索引数组
	//nCakeCnt
	//
	void Init(int* pCakeArray, int nCakeCnt) {
		assert(pCakeArray != NULL);
		assert(nCakeCnt > 0);
		m_nCakeCnt = nCakeCnt;

		//初始化烙饼数组
		m_CakeArray = new int[m_nCakeCnt];
		assert(m_CakeArray != NULL);
		for (int i = 0; i < m_nCakeCnt; i++) {
			m_CakeArray[i] = pCakeArray[i];
		}

		//设置最多交换次数信息
		m_nMaxSwap = UpBound(m_nCakeCnt);

		//初始化交换结果数组
		m_SwapArray = new int[m_nMaxSwap + 1];
		assert(m_SwapArray!=NULL);

		//初始化中间交换结果信息
		m_ReverseCakeArray = new int[m_nCakeCnt];
		for (int i = 0; i < m_nCakeCnt; i++) {
			m_ReverseCakeArray[i] = m_CakeArray[i];
		}
		m_ReverseCakeArraySwap = new int[m_nMaxSwap];
	}

	//
	//寻找当前翻转的上界
	//
	int UpBound(int nCakeCnt) {
		return (nCakeCnt - 2) * 2 + 1;//原先return (nCakeCnt-1)*2也可以，
									  //代码这么写也没问题，只不过不是最优解而已
	}

	//
	//寻找当前翻转的下界
	//
	int LowerBound(int* pCakeArray, int nCakeCnt) {
		int t, ret = 0;

		//根据当前数组排序信息情况判断至少需要交换多少次
		for (int i = 1; i < nCakeCnt; i++) {
			//判断位置相邻的两个烙饼，是否为尺寸排序上相邻的
			//此处应该考虑顺序问题，若烙饼的次序从上往下数是从大到小的，即t==-1
			//翻转次数应该是1而非0，即要整个翻转一次。
			t = pCakeArray[i] - pCakeArray[i - 1];
			if ((t == 1) || (t == -1)) {
			}
			else {
				ret++;
			}
		}
		//判断下界时，如果最大的烙饼不在最后一个位置，则要多翻转一次(包含了t==-1的情况)
		//能有效减少无效搜索次数，虽然还是会包含无效搜索。。
		if (pCakeArray[nCakeCnt - 1] != nCakeCnt - 1)
			ret++;
		return ret;
	}

	//排序的主函数
	void Search(int step) {
		int i, nEstimate;
		m_nSearch++;

		//估算这次搜索所需要的最小交换次数nEstimate
		nEstimate = LowerBound(m_ReverseCakeArray, m_nCakeCnt);
		//根节点（最原始数组）调用search时step是0，第一层子节点step是1，
		//第二层子节点step是2，以此类推可知step是从0开始计数的。因为nElimate可能为0，
		//所以当step等于m_nMaxSwap时候，会造成下面的m_reverseCakeArraySwap[step]=i;
		//的数组越界。所以判断条件应改为>=
		if (step + nEstimate >= m_nMaxSwap)
			return;

		//如果已经排序好，即翻转完成，输出结果
		if (IsSorted(m_ReverseCakeArray, m_nCakeCnt)) {
			if (step < m_nMaxSwap) {
				m_nMaxSwap = step;
				for (i = 0; i < m_nMaxSwap; i++)
					m_SwapArray[i] = m_ReverseCakeArraySwap[i];
			}
			return;
		}

		//递归进行翻转
		for (i = 1; i < m_nCakeCnt; i++) {
			Revert(0, i);
			m_ReverseCakeArraySwap[step] = i;
			Search(step + 1);
			Revert(0, i);
		}
	}

	//
	//true:已经排好序
	//false:未排序
	//
	bool IsSorted(int* pCakeArray, int nCakeCnt) { //若数组内容从小到大有序，返回true
		for (int i = 1; i < nCakeCnt; i++) {
			if (pCakeArray[i - 1] > pCakeArray[i]) {
				return false;
			}
		}
		return true;
	}

	//
	//翻转烙饼信息
	//
	void Revert(int nBegin, int nEnd) { //把数组中给定两个系数之间的内容反序之~
		assert(nEnd > nBegin);
		int i, j, t;

		//翻转烙饼信息
		for (i = nBegin, j = nEnd; i < j; i++, j--) {
			t = m_ReverseCakeArray[i];
			m_ReverseCakeArray[i] = m_ReverseCakeArray[j];
			m_ReverseCakeArray[j] = t;
		}
	}
};

//主函数，供测试
int main() {
	int Cake[10] = {3,2,1,6,5,4,9,8,7,0};
	CPrefixSorting TestA;
	TestA.Run(Cake, 10);
	TestA.Output();
	return 0;
}
