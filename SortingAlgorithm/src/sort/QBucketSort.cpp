#include "QBucketSort.h"

#include <iostream>
#include <algorithm>
#include <list>

#include "QQuickSort.h"

// 桶排序
// 算法：将输入的数据值转化为键存储在额外开辟的数组空间中，计算数据出现的次数。
// 优化：减少不必要的桶，获取最小值和最大值的范围，分配这个范围的桶个数
template <typename T>
bool CQBucketSort<T>::sort(std::vector<T>& vtData)
{
    bool bRet = false;

    if (vtData.size() < 2) 
        return bRet;

    T maxVal = 0;
    T minVal = 0;

    for (int i = 0; i < vtData.size(); ++i) {
        maxVal = std::max(maxVal, vtData[i]);
        minVal = std::min(minVal, vtData[i]);
    }

    int b = 1; // 每个桶的容量
    
    int k = (maxVal - minVal + b) / b;
    std::vector<std::list<T>> buckets(k);

    // 分配
    for (const auto& val : vtData) {
        int index = (val - minVal) / b;
        buckets[index].push_back(val);
    }

    int index = 0;
    // 桶内排序与收集
    for (auto& l : buckets) {
        // 使用其他排序方法进行桶内排序
        l.sort();
        
        for (const auto& val : l)
            vtData[index++] = val;
    }

    bRet = true;

    return bRet;
}

template class CQBucketSort<int>;
template class CQBucketSort<long>;