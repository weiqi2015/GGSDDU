#include "QInsertionSort.h"
#include <iostream>

// 插入排序
// 算法：将数据插入已经排好序的有序表中
// 优化：折半插入
template <typename T>
bool CQInsertionSort<T>::sort(std::vector<T>& vtData)
{
    bool bRet = false;
    
    // 1 个数据时，是一个有序表，所以从第 2 个元素开始插入
    for (int i = 1; i < vtData.size(); i++)
    {
        int tmp = vtData[i];
        int j = 0;

        // 折半查找
        {
            int nLow = 0;
            int nHight = i;
            while (nLow < nHight)
            {
                int nPos = (nLow + nHight) / 2;
                if (vtData[nPos] < tmp)
                    nLow = nPos + 1;
                else
                    nHight = nPos - 1;
            }

            // 将 nHight 元素往后移
            for (j = (i - 1); j >= nHight; j--)
            {
                vtData[j+1] = vtData[j]; 
            }
        }

        // {   // 直接查找插入
        //     // 比插入元素小的，往后移
        //     for (j = (i - 1); j >= 0; j--)
        //     {
        //         if (vtData[j] <= tmp)
        //             break;
                
        //         vtData[j+1] = vtData[j]; 
        //     }
        // }

        // 将数据插入合适位置
        vtData[j+1] = tmp;
    }
    
    bRet = true;

    return bRet;
}

template class CQInsertionSort<int>;
template class CQInsertionSort<long>;