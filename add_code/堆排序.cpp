#include <iostream>
#include <vector>

#define left(x) 2*x+1;//�����ڵ��������е��±�
#define right(x) 2*(x+1);//����ҽڵ��������е��±�

using namespace std;

void MaxHeapify(int* a,int i,int low,int high)//����ΪҪ�����������͸��ڵ㣬����a���б�ά������һ���ֵ��±�low��high
{
    int l = left(i);//�����±�Ϊi�Ľڵ�����ӽڵ�
    int r = right(i);//�����±�Ϊi�Ľڵ�����ӽڵ�
    int largest;//����i,l,r(��i�����������ӽڵ�)֮�����������±�
    int temp;//���������е�����ʹ�õ���ʱ����
    //�ҵ����������������Ǹ������������Ǹ�����i���л���
    if (l<=high && a[l]>a[i])
    {
        largest = l;
    }
    else{
        largest = i;
    }

    if (r<=high && a[r]>a[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        MaxHeapify(a, largest,low,high);//�����п����ƻ��������������ʣ����Զ����������Ǹ��ӽڵ����һ��ά������δ�������Ǹ��ӽڵ㣬�������ǵļ��裬�Ǳ������������ʵġ�
    }
}

void BuildMaxHeap(int* a,int length)
{
    for (int i = length / 2-1; i >= 0; i--)
    {
        MaxHeapify(a, i, 0, length - 1);
    }
}

void HeapSort(int a[],int length)
{
    int temp;
    BuildMaxHeap(a,length);
    for (int i = length - 1; i >= 1; i--)
    {
        //�������ڵ����������һ���ڵ�
        temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        MaxHeapify(a, 0, 0, i-1);//ά�����±�Ϊi-1��0��������
    }
}

void HeapDelete(int a[],int length,int target) {
    int index = 0;
    for (int i = 0;i < length;i++) {
        if (a[i] == target) {
            length --;
            a[i] = a[length];
            index = i;
            break;
        }
    }
    BuildMaxHeap(a,length);
}

int main() {
    int a[5] = {2,1,3,5,4};
    //HeapSort(a,4);
    BuildMaxHeap(a,5);
    for (int i = 0;i < 5;i++) {
        cout << a[i] << " ";
    }
    HeapDelete(a,5,2);
    for (int i = 0;i < 4;i++) {
        cout << a[i] << " ";
    }
    return 0;
}
