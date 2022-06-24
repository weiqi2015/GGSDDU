#include "QCountingSort.h"

#include <iostream>
#include <algorithm>

// 计数排序
// 算法：将输入的数据值转化为键存储在额外开辟的数组空间中，计算数据出现的次数。
// 优化：减少不必要的桶，获取最小值和最大值的范围，分配这个范围的桶个数
template <typename T>
bool CQCountingSort<T>::sort(std::vector<T>& vtData)
{
    bool bRet = false;

    // 计数
    std::vector<int> vtCount(vtData.size());
    std::fill(vtCount.begin(), vtCount.end(), 0);

    std::vector<T> vtOut(vtData.size());

    for (size_t i = 0; i < vtData.size(); i++)
    {
        vtCount[vtData[i]]++;
    }

    // 给每个桶分配对应个数的存放位置
    for (int j = 1; j < vtCount.size(); j++)
    {
        vtCount[j] += vtCount[j - 1];
    }
    
    for (int j = vtData.size() - 1; j >= 0; j--)
    {
        vtOut[--vtCount[vtData[j]]] = vtData[j];
    }

    vtData = vtOut;

    bRet = true;

    return bRet;
}

template class CQCountingSort<int>;
template class CQCountingSort<long>;