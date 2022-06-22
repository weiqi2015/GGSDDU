#include "QShellSort.h"
#include <iostream>

// 希尔排序
// 算法：增加增量的插入排序，按照增量分组，直到增量为 0 为止
// 优化：
template <typename T>
bool CQShellSort<T>::sort(std::vector<T>& vtData)
{
    bool bRet = false;
    
    // 获取增量
    for (int d = vtData.size() / 2; d > 0; d /= 2)
    {
        for (int i = d; i < vtData.size(); i++)
        {
            T tmp = vtData[i];
            int j = i - d;
            for (j; j >= 0 && (vtData[j] > tmp); j -= d)
            {
                std::swap(vtData[j], vtData[j+d]); 
            }
            vtData[j+d] = tmp;
        }
    }
    
    bRet = true;

    return bRet;
}

template class CQShellSort<int>;
template class CQShellSort<long>;