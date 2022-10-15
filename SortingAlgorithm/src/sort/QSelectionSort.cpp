#include "QSelectionSort.h"

// 选择排序
// 算法：遍历数据，每趟从待排序的数据中选出最小/最大的数据，按照顺序将数据存放遍历末端。
// 优化：每趟从待排序的数据中选出最小和最大的数据，按照顺序将数据存放到两端。
template <typename T>
bool CQSelectionSort<T>::sort(std::vector<T>& vtData)
{
    bool bRet = false;

    // 最值
    int maxIndex = 0;
    int minIndex = 0;
    
    // 无序区间末端下标
    int nLeft = 0;
    int nRight = vtData.size() - 1;

    // 从左往右遍历
    while (nLeft < nRight)
    {
        // 最值设置为无序区间两端
        minIndex = nLeft;
        maxIndex = nRight;

        // 遍历无序区间，记录最大和最小数据下标
        for (int j = nLeft; j < nRight; j++)
        {
            if (vtData[j] > vtData[maxIndex])
                maxIndex = j;
            else if (vtData[j] < vtData[minIndex])
                minIndex = j;
        }
        
        // 最大和最小值位置互换
        if (maxIndex == nLeft && minIndex == nRight)
        {
            std::swap(vtData[maxIndex], vtData[minIndex]);
        }
        else
        {
            // 最小值移动到最左端
            if (minIndex != nLeft)
            {
                std::swap(vtData[nLeft], vtData[minIndex]);
                
                // 最大值位置发生改变，更新下标值
                if (maxIndex == nLeft)
                    maxIndex = minIndex;
            }
            
            // 最大值移动到最右端
            if (maxIndex != nRight)
                std::swap(vtData[nRight], vtData[maxIndex]);
        }

        nLeft++;
        nRight--;
    }

    bRet = true;

    return bRet;
}

template class CQSelectionSort<int>;
template class CQSelectionSort<long>;