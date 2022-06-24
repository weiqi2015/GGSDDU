#include <iostream>
#include <vector>
#include <time.h>

#include "QBubbleSort.h"
#include "QSelectionSort.h"
#include "QQuickSort.h"
#include "QInsertionSort.h"
#include "QShellSort.h"
#include "QHeapSort.h"
#include "QMergingSort.h"
#include "QCountingSort.h"
#include "QBucketSort.h"
#include "QRadixSort.h"

int main(int argc, char const *argv[])
{
    std::cout << "Hello world" << std::endl;
    
    int nsize = 50;
    std::vector<int> vtData;

    // 定义随机种子数
    srand((unsigned)time(0));
    for (size_t i = 0; i < nsize; i++)
    {
        int nValue = rand() % (nsize);
        vtData.push_back(nValue);
    }
    
    std::cout << "list:" << std::endl;
    for (int value : vtData)
    {
        std::cout << value << " ";
    }

    std::cout << std::endl;

    // CQBubbleSort<int> qsort;     // 冒泡
    // CQSelectionSort<int> qsort;  // 选择
    // CQQuickSort<int> qsort;      // 快速
    // CQInsertionSort<int> qsort;  // 插入
    // CQShellSort<int> qsort;      // 希尔
    // CQHeapSort<int> qsort;       // 堆
    // CQMergingSort<int> qsort;    // 归并
    // CQCountingSort<int> qsort;   // 计数
    // CQBucketSort<int> qsort;     // 桶
    CQRadixSort<int> qsort;      // 基数
    qsort.sort(vtData);

    std::cout << "after sort:" << std::endl;
    
    for (int value : vtData)
    {
        std::cout << value << " ";
    }

    std::cout << std::endl;

    return 0;
}
