#include<iostream>
#include<assert.h>
using namespace std;

/****************/
//
//�ӱ������ʵ��
//
/****************/
class CPrefixSorting {
private:
	int* m_CakeArray;     //�ӱ���Ϣ����
	int m_nCakeCnt;       //�ӱ�����
	int m_nMaxSwap;       //��ཻ������������ǰ����ƶϣ��������Ϊ(m_nCakeCnt-2)*2+1
	int* m_SwapArray;     //�����������
	int* m_ReverseCakeArray;      //��ǰ��ת�ӱ���Ϣ����
	int* m_ReverseCakeArraySwap;  //��ǰ��ת�ӱ������������
	int m_nSearch;                //��ǰ����������Ϣ

public:
	CPrefixSorting(){   //���캯��
		m_nCakeCnt = 0;
		m_nMaxSwap = 0;
	}
	~CPrefixSorting() {  //��������
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
	//�����ӱ���ת��Ϣ
	//@param
	//pCakeArray  �洢�ӱ���������
	//nCakeCnt     �ӱ�����
	//
	void Run(int* pCakeArray, int nCakeCnt) {
		Init(pCakeArray, nCakeCnt);
		m_nSearch = 0;
		Search(0);
	}

	//
	//����ӱ���ת����
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
	//��ʼ��������Ϣ
	//@param
	//pCakeArray  �洢�ӱ���������
	//nCakeCnt
	//
	void Init(int* pCakeArray, int nCakeCnt) {
		assert(pCakeArray != NULL);
		assert(nCakeCnt > 0);
		m_nCakeCnt = nCakeCnt;

		//��ʼ���ӱ�����
		m_CakeArray = new int[m_nCakeCnt];
		assert(m_CakeArray != NULL);
		for (int i = 0; i < m_nCakeCnt; i++) {
			m_CakeArray[i] = pCakeArray[i];
		}

		//������ཻ��������Ϣ
		m_nMaxSwap = UpBound(m_nCakeCnt);

		//��ʼ�������������
		m_SwapArray = new int[m_nMaxSwap + 1];
		assert(m_SwapArray!=NULL);

		//��ʼ���м佻�������Ϣ
		m_ReverseCakeArray = new int[m_nCakeCnt];
		for (int i = 0; i < m_nCakeCnt; i++) {
			m_ReverseCakeArray[i] = m_CakeArray[i];
		}
		m_ReverseCakeArraySwap = new int[m_nMaxSwap];
	}

	//
	//Ѱ�ҵ�ǰ��ת���Ͻ�
	//
	int UpBound(int nCakeCnt) {
		return (nCakeCnt - 2) * 2 + 1;//ԭ��return (nCakeCnt-1)*2Ҳ���ԣ�
									  //������ôдҲû���⣬ֻ�����������Ž����
	}

	//
	//Ѱ�ҵ�ǰ��ת���½�
	//
	int LowerBound(int* pCakeArray, int nCakeCnt) {
		int t, ret = 0;

		//���ݵ�ǰ����������Ϣ����ж�������Ҫ�������ٴ�
		for (int i = 1; i < nCakeCnt; i++) {
			//�ж�λ�����ڵ������ӱ����Ƿ�Ϊ�ߴ����������ڵ�
			//�˴�Ӧ�ÿ���˳�����⣬���ӱ��Ĵ�������������ǴӴ�С�ģ���t==-1
			//��ת����Ӧ����1����0����Ҫ������תһ�Ρ�
			t = pCakeArray[i] - pCakeArray[i - 1];
			if ((t == 1) || (t == -1)) {
			}
			else {
				ret++;
			}
		}
		//�ж��½�ʱ����������ӱ��������һ��λ�ã���Ҫ�෭תһ��(������t==-1�����)
		//����Ч������Ч������������Ȼ���ǻ������Ч��������
		if (pCakeArray[nCakeCnt - 1] != nCakeCnt - 1)
			ret++;
		return ret;
	}

	//�����������
	void Search(int step) {
		int i, nEstimate;
		m_nSearch++;

		//���������������Ҫ����С��������nEstimate
		nEstimate = LowerBound(m_ReverseCakeArray, m_nCakeCnt);
		//���ڵ㣨��ԭʼ���飩����searchʱstep��0����һ���ӽڵ�step��1��
		//�ڶ����ӽڵ�step��2���Դ����ƿ�֪step�Ǵ�0��ʼ�����ġ���ΪnElimate����Ϊ0��
		//���Ե�step����m_nMaxSwapʱ�򣬻���������m_reverseCakeArraySwap[step]=i;
		//������Խ�硣�����ж�����Ӧ��Ϊ>=
		if (step + nEstimate >= m_nMaxSwap)
			return;

		//����Ѿ�����ã�����ת��ɣ�������
		if (IsSorted(m_ReverseCakeArray, m_nCakeCnt)) {
			if (step < m_nMaxSwap) {
				m_nMaxSwap = step;
				for (i = 0; i < m_nMaxSwap; i++)
					m_SwapArray[i] = m_ReverseCakeArraySwap[i];
			}
			return;
		}

		//�ݹ���з�ת
		for (i = 1; i < m_nCakeCnt; i++) {
			Revert(0, i);
			m_ReverseCakeArraySwap[step] = i;
			Search(step + 1);
			Revert(0, i);
		}
	}

	//
	//true:�Ѿ��ź���
	//false:δ����
	//
	bool IsSorted(int* pCakeArray, int nCakeCnt) { //���������ݴ�С�������򣬷���true
		for (int i = 1; i < nCakeCnt; i++) {
			if (pCakeArray[i - 1] > pCakeArray[i]) {
				return false;
			}
		}
		return true;
	}

	//
	//��ת�ӱ���Ϣ
	//
	void Revert(int nBegin, int nEnd) { //�������и�������ϵ��֮������ݷ���֮~
		assert(nEnd > nBegin);
		int i, j, t;

		//��ת�ӱ���Ϣ
		for (i = nBegin, j = nEnd; i < j; i++, j--) {
			t = m_ReverseCakeArray[i];
			m_ReverseCakeArray[i] = m_ReverseCakeArray[j];
			m_ReverseCakeArray[j] = t;
		}
	}
};

//��������������
int main() {
	int Cake[10] = {3,2,1,6,5,4,9,8,7,0};
	CPrefixSorting TestA;
	TestA.Run(Cake, 10);
	TestA.Output();
	return 0;
}
