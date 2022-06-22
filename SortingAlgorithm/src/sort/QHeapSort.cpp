#include "QHeapSort.h"
#include <iostream>

// 堆排序
// 算法：将数据组成树状形式排序堆，每次获取根节点，用最低端的节点替换，再调整堆。
// 优化：
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
        if (((nSon+1) < nSize) && (vtData[nSon] < vtData[nSon + 1]))
            nSon ++;

        // 创建堆后，子节点后面部分已经是有序的，如果父节点没有变化，堆已经调整完成。
        if (vtData[nDad] >= vtData[nSon])
            break;

        std::swap(vtData[nDad], vtData[nSon]);
        nDad = nSon;
        nSon = nSon * 2 + 1;
    }
}

template class CQHeapSort<int>;
template class CQHeapSort<long>;