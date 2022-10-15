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

    if (vtData.size() < 0)
        return bRet;
    
    if (vtData.size() <= 1)
        return true;
    
    T max = 0;
    T min = 0;
    for (T i : vtData)
    {
        if (i > max)
            max = i;
        if (i < min)
            min = i;
    }
    
    // 分配大小为最大值和最小值差值的数组用于计数
    std::vector<int> vtCount(max - min + 1, 0);

    std::vector<T> vtOut(vtData.size());

    // 统计数据出现的次数
    for (size_t i = 0; i < vtData.size(); i++)
    {
        vtCount[vtData[i]-min]++;
    }

    // 在输出数组中给每个桶分配对应个数的存放位置
    for (int j = 1; j < vtCount.size(); j++)
    {
        vtCount[j] += vtCount[j - 1];
    }
    
    // 将数据填入输出数组中
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