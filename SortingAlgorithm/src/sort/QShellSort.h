#ifndef DEMO1_SORT_QSHELLSORT_H
#define DEMO1_SORT_QSHELLSORT_H

#include "QSort.h"

template <typename T>
class CQShellSort : public CQSort<T>
{
private:
    /* data */
public:
    CQShellSort(/* args */){}
    ~CQShellSort(){}

    virtual bool sort(std::vector<T>& vtData);
};

#endif