#ifndef DEMO1_SORT_QSELECTIONSORT_H
#define DEMO1_SORT_QSELECTIONSORT_H

#include "QSort.h"

template <typename T>
class CQSelectionSort : public CQSort<T>
{
private:
    /* data */
public:
    CQSelectionSort(/* args */){}
    ~CQSelectionSort(){}

    virtual bool sort(std::vector<T>& vtData);
    // virtual bool sort(std::vector<int>& vtData);
};

#endif