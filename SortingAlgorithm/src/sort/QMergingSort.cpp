#include "QMergingSort.h"
#include <iostream>

// 归并排序排序
// 算法：将 n 个数据递归分割成 n 组，再合并排列，组合成一个有序列表
// 优化：
template <typename T>
bool CQMergingSort<T>::sort(std::vector<T>& vtData)
{
    bool bRet = false;
    
    MergeSort(vtData, 0, vtData.size() - 1);

    bRet = true;

    return bRet;
}

template <typename T>
void CQMergingSort<T>::MergeSort(std::vector<T>& vtData, int nStart, int nEnd)
{
    if (nStart >= nEnd)
        return;

    int nMid = (nStart + nEnd) / 2;
    MergeSort(vtData, nStart, nMid);
    MergeSort(vtData, nMid + 1, nEnd);
    Merge(vtData, nStart, nMid, nEnd);
}

template <typename T>
void CQMergingSort<T>::Merge(std::vector<T>& vtData, int nStart, int nMid, int nEnd)
{
    std::vector<T> vtTmp;
    vtTmp.reserve(nEnd - nStart + 1);

    int nLow = nStart;
    int nHight = nMid + 1;
    while ((nLow <= nMid) && (nHight <= nEnd))
    {
        if (vtData[nLow] <= vtData[nHight])
        {
            vtTmp.push_back(vtData[nLow]);
            nLow ++;
        }
        else
        {
            vtTmp.push_back(vtData[nHight]);
            nHight ++;
        }
    }
    
    while (nLow <= nMid)
    {
        vtTmp.push_back(vtData[nLow]);
        nLow ++;
    }
    while (nHight <= nEnd)
    {
        vtTmp.push_back(vtData[nHight]);
        nHight ++;
    }

    for (int i = 0; i < vtTmp.size(); i++)
    {
        vtData[nStart + i] = vtTmp[i];
    }

    printf("start:%d mid:%d end:%d ", nStart, nMid, nEnd);
    for (int value : vtData)
    {
        std::cout << value << " ";
    }

    std::cout << std::endl;
}

template class CQMergingSort<int>;
template class CQMergingSort<long>;