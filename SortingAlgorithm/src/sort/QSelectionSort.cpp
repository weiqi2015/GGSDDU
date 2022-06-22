#include "QSelectionSort.h"

// 选择排序
// 算法：遍历数据，每趟从待排序的数据中选出最小/最大的数据，按照顺序将数据存放遍历末端。
// 优化：每趟从待排序的数据中选出最小和最大的数据，按照顺序将数据存放到两端。
template <typename T>
bool CQSelectionSort<T>::sort(std::vector<T>& vtData)
{
    bool bRet = false;
    bool bChange = false;
    int maxIndex = 0;
    int minIndex = 0;
    
    for (int i = 0; i < (vtData.size() / 2); i++)
    {
        size_t size = vtData.size() - i;
        minIndex = i;
        maxIndex = size-1;
        
        // 遍历没有排序数据，记录最大和最小数据下标
        for (int j = i; j < size; j++)
        {
            if (vtData[j] > vtData[maxIndex])
                maxIndex = j;
            else if (vtData[j] < vtData[minIndex])
                minIndex = j;
        }
        
        { // 升序
            if (minIndex != i)
            {
                std::swap(vtData[i], vtData[minIndex]);
                bChange = true;
            }
            if (maxIndex != size-1)
            {
                std::swap(vtData[size-1], vtData[maxIndex]);
                bChange = true;
            }
        }
        
        /*
        { // 降序
            if (minIndex != size-1)
            {
                std::swap(vtData[size-1], vtData[minIndex]);
                bChange = true;
            }
            if (maxIndex != i)
            {
                std::swap(vtData[i], vtData[maxIndex]);
                bChange = true;
            }
        }
        */
       
        if (! bChange)
            break;
    }
    
    bRet = true;

    return bRet;
}

template class CQSelectionSort<int>;
template class CQSelectionSort<long>;