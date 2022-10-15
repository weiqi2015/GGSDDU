#include "QBubbleSort.h"

// 冒泡排序
// 算法原理：
//     从头到尾遍历，比较相邻的两个元素，如果顺序是逆序，交换两个元素。
//     每次遍历会将遍历区间中最值移动到遍历区间的末端，末端变为有序。
//     遍历区间会随着遍历次数的增加而减小。
// 优化：如果遍历完后，顺序没有发生改变，证明排序已经完成，退出循环。
template <typename T>
bool CQBubbleSort<T>::sort(std::vector<T>& vtData)
{
    bool bRet = false;
    bool bChange = false;
    
    for (int i = 0; i < (vtData.size() - 1); i++)
    {
        for (int j = 0; j < (vtData.size() - 1 - i); j++)
        {
            if (vtData[j] > vtData[j+1])
            {
                // vtData[j]  += vtData[j+1];
                // vtData[j+1] = vtData[j] - vtData[j+1];
                // vtData[j]   = vtData[j] - vtData[j+1];
                std::swap(vtData[j], vtData[j+1]);

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