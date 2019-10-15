#include <iostream>
#include <vector>

#define left(x) 2*x+1;//获得左节点在数组中的下标
#define right(x) 2*(x+1);//获得右节点在数组中的下标

using namespace std;

void MaxHeapify(int* a,int i,int low,int high)//输入为要被排序的数组和根节点，数组a当中被维护的那一部分的下标low，high
{
    int l = left(i);//计算下标为i的节点的左子节点
    int r = right(i);//计算下标为i的节点的右子节点
    int largest;//保存i,l,r(即i和它的左右子节点)之间的最大数的下标
    int temp;//交互数组中的数所使用的临时变量
    //找到三个数当中最大的那个数，将最大的那个数和i进行互换
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
        MaxHeapify(a, largest,low,high);//交换有可能破坏子树的最大堆性质，所以对所交换的那个子节点进行一次维护，而未交换的那个子节点，根据我们的假设，是保持着最大堆性质的。
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
        //交换根节点和数组的最后一个节点
        temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        MaxHeapify(a, 0, 0, i-1);//维护从下标为i-1到0的子数组
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
