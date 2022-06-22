#include "QBubbleSort.h"

// 冒泡排序
// 算法：遍历数据，两两比较，如果是逆序，则交换数据。
// 优化：如果遍历完后，数据顺序没有发生改变，证明排序已经完成
template <typename T>
bool CQBubbleSort<T>::sort(std::vector<T>& vtData)
// bool CQBubbleSort::sort(std::vector<int>& vtData)
{
    bool bRet = false;
    bool bChange = false;
    for (int i = vtData.size(); i >= 0; i--)
    {
        for (int j = (i - 1); j >= 0; j--)
        {
            if (vtData[j] > vtData[i])
            {
                // vtData[j] += vtData[i];
                // vtData[i] = vtData[j] - vtData[i];
                // vtData[j] = vtData[j] - vtData[i];
                std::swap(vtData[i], vtData[j]);

                bChange = true;
            }
        }

        if (! bChange)
            break;
    }
    
    bRet = true;

    return bRet;
}

template class CQBubbleSort<int>;
template class CQBubbleSort<long>;