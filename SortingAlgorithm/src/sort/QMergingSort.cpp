#include "QMergingSort.h"
#include <iostream>

// 归并排序排序
// 算法：将 n 个数据递归分割成 n 组，再合并排列，组合成一个有序列表
// 优化：
template <typename T>
bool CQMergingSort<T>::sort(std::vector<T>& vtData)
{
    bool bRet = false;

    // 递归实现
    // MergeSort(vtData, 0, vtData.size() - 1);

    // 迭代实现
    // 按照步长1将素组分割成 nLen 份组合,再加宽步长继续组合
    int nLen = vtData.size();
    for (int nStep = 1; nStep < nLen; nStep *= 2)
    {
        for (int nStart = 0; nStart < nLen; nStart += (nStep * 2))
        {
            Merge(vtData, nStart, std::min(nStart+nStep-1, nLen), std::min(nStart+nStep+nStep-1, nLen));
        }
    }

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
}

template class CQMergingSort<int>;
template class CQMergingSort<long>;