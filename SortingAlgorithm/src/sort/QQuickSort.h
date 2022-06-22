#ifndef DEMO1_SORT_QQUICKSORT_H
#define DEMO1_SORT_QQUICKSORT_H

#include "QSort.h"

template <typename T>
class CQQuickSort : public CQSort<T>
{
private:
    /* data */
public:
    CQQuickSort(/* args */){}
    ~CQQuickSort(){}

    virtual bool sort(std::vector<T>& vtData);

private:
    void sort(std::vector<T>& vtData, int nLow, int nHight);
    int partition(std::vector<T>& vtData, int nLow, int nHight);
};

#endif