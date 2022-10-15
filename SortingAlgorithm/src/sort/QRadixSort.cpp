#include "QRadixSort.h"

#include <iostream>
#include <algorithm>

// 基数排序
// 算法：按照数据位数上的值比较，依次存放到临时容器中，直到比较完所有位数，最后得到排好序的数据。
// 优化：
template <typename T>
bool CQRadixSort<T>::sort(std::vector<T>& vtData)
{
    bool bRet = false;

    // 求位数
    int d = MaxBit(vtData);

    if (vtData.empty() || d <= 0)
    {
        return false;
    }
    
    int i = 0;  // 遍历位数 个位 -> 十位 -> 百位 ...
    int j = 0;  
    int k = 0;
    int radix = 1;  // 位数
    std::vector<int> vtRadix(10);   // 基数容器 0-9
    std::vector<T> vtTmp(vtData.size());   // 临时排序
    
    for (i = 0; i < d; i++)
    {
        // 基数容器清零
        std::fill(vtRadix.begin(), vtRadix.end(), 0);

        // 计算分配给每个桶的元素个数
        for (const auto& val : vtData)
        {
            k = (val / radix) % 10;
            vtRadix[k]++;
        }
        
        // 给每个桶分配对应个数的存放位置
        for (j = 1; j < 10; j++)
        {
            vtRadix[j] += vtRadix[j - 1];
        }
        
        // 存放到桶中的顺序是倒序，从后往前遍历数据
        for (j = vtData.size() - 1; j >= 0; j--)
        {
            k = (vtData[j] / radix) % 10;
            // 倒序
            vtTmp[--vtRadix[k]] = vtData[j];
        }
        
        vtData = vtTmp;

        radix *= 10;
    }
    
    bRet = true;

    return bRet;
}

template <typename T>
int CQRadixSort<T>::MaxBit(std::vector<T>& vtData)
{
    T tMax = 0;
    auto it = std::max_element(vtData.begin(), vtData.end());
    if (it != vtData.end())
    {
        tMax = *it;
    }
    
    int d = 1;
    int p = 10;
    while (tMax >= p)
    {
        tMax /= 10;
        d++;
    }

    return d;
}


template class CQRadixSort<int>;
template class CQRadixSort<long>;