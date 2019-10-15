#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &A)
{
	int n = A.size()-1;
	for(int i = n/2 ;i >= 0;i--)
		heapify(A,i);
}

void heapify(vector<int> &A,int i)
{
	int ld = 2*i+1;//数组A下标从0开始 所以i节点的左右孩子节点为2i+1、2i+2
	int rd = 2*i+2;//
	int minpos = i;
	if(ld < A.size() && A[ld] < A[minpos])
		minpos = ld;
	if(rd < A.size() && A[rd] < A[minpos])
		minpos = rd;
	if(minpos != i)
	{
	    swap(A[i],A[minpos]);
    	heapify(A,minpos);
	}
}


int main() {
    return 0;
}
