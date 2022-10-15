#include "QHeapSort.h"
#include <iostream>

// 堆排序
// 算法：将数据组成树状形式排序堆，每次获取根节点，用最低端的节点替换，再调整堆。
// 优化：
//
// 堆的数据分布
// A=0|B=A*2+1|C=A*2+2|D=B*2+1|E=B*2+2|F=C*2+1|G=C*2+2
template <typename T>
bool CQHeapSort<T>::sort(std::vector<T>& vtData)
{
    bool bRet = false;
    // 初始化堆排序
    CreateHeap(vtData);

    int nSize = vtData.size();
    for (int i = nSize - 1; i > 0; i--)
    {
        // 将符合排序的根节点和最后一个子节点数据，vtData[i] 为已经排好序节点
        std::swap(vtData[i], vtData[0]);

        // 减少一个数据 vtData[i]，重新调整堆
        HeapAdjust(vtData, 0, i);
    }
    
    return bRet;
}

template <typename T>
void CQHeapSort<T>::CreateHeap(std::vector<T>& vtData)
{
    int nSize = vtData.size();
    // 从最后一个父节点开始调整。
    for (int i = (nSize / 2 - 1); i >= 0; i--)
    {
        HeapAdjust(vtData, i, nSize);
    }
}

template <typename T>
void CQHeapSort<T>::HeapAdjust(std::vector<T>& vtData, int index, int nSize)
{
    int nDad = index;
    int nSon = index * 2 + 1;

    while (nSon < nSize)
    {
        // 获取最大子节点下标
        if (((nSon+1) < nSize) && (vtData[nSon] < vtData[nSon + 1]))
            nSon ++;

        // 创建堆后，子节点后面部分已经是有序的，如果父节点没有变化，堆已经调整完成。
        if (vtData[nDad] >= vtData[nSon])
            break;

        // 调整父子节点数据
        std::swap(vtData[nDad], vtData[nSon]);

        // 数据发生变化，需要继续调整子堆的数据
        nDad = nSon;
        nSon = nSon * 2 + 1;
    }
}

template class CQHeapSort<int>;
template class CQHeapSort<long>;