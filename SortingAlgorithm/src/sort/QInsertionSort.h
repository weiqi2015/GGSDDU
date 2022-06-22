#ifndef DEMO1_SORT_QINSERTIONSORT_H
#define DEMO1_SORT_QINSERTIONSORT_H

#include "QSort.h"

template <typename T>
class CQInsertionSort : public CQSort<T>
{
private:
    /* data */
public:
    CQInsertionSort(/* args */){}
    ~CQInsertionSort(){}

    virtual bool sort(std::vector<T>& vtData);
};

#endif