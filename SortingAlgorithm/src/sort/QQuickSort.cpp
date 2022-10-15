#include "QQuickSort.h"
#include <iostream>

// 快速排序
// 算法：递归获取一个基点，将小于基点的放到左边，大于基点的放到右边，直到最小下标 = 最大下标为止
// 优化：
//      三数取中:获取第一个,中间,最后元素中的中值为基数
//      挖坑法:减少不必要的交换
//      
template <typename T>
bool CQQuickSort<T>::sort(std::vector<T>& vtData)
{
    bool bRet = false;
    
    if (vtData.size() > 1)
    {
        sort(vtData, 0, vtData.size());
    }
    
    bRet = true;

    return bRet;
}

template <typename T>
void CQQuickSort<T>::sort(std::vector<T>& vtData, int nLow, int nHight)
{
    // 可以设置阈值,当区间小于阈值时,改用插入排序,减小递归深度

    if (nLow < nHight)
    {
        int pivot = partition(vtData, nLow, nHight);
        sort(vtData, nLow, (pivot - 1));
        sort(vtData, (pivot + 1), nHight);
    }
}

// 双边循环
template <typename T>
int CQQuickSort<T>::partition(std::vector<T>& vtData, int nLow, int nHight)
{
    // 可以使用三数取中的方法获取坑位
    // 坑位
    T pivot = vtData[nLow];

    while (nLow < nHight)
    {
        // 获取比基准点小的下标
        while ((nLow < nHight) && (vtData[nHight] >= pivot))
        {
            nHight --;
        }

        // 交换比基准点小的,移到左边
        if (nLow < nHight)
            vtData[nLow++] = vtData[nHight];

        // 获取比基准点大的下标
        while ((nLow < nHight) && (vtData[nLow] <= pivot))
        {
            nLow ++;
        }

        // 交换比基准点大的,移到右边
        if (nLow < nHight)
            vtData[nHight--] = vtData[nLow];
    }

    vtData[nLow] = pivot;

    return nLow;
}

template class CQQuickSort<int>;
template class CQQuickSort<long>;