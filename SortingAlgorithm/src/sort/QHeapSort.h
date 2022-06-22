#ifndef DEMO1_SORT_QHEAPSORT_H
#define DEMO1_SORT_QHEAPSORT_H

#include "QSort.h"

template <typename T>
class CQHeapSort : public CQSort<T>
{
private:
    /* data */
public:
    CQHeapSort(/* args */){}
    ~CQHeapSort(){}

    virtual bool sort(std::vector<T>& vtData);

private:
    void CreateHeap(std::vector<T>& vtData);
    void HeapAdjust(std::vector<T>& vtData, int index, int nSize);
};

#endif