#ifndef DEMO1_SORT_QSORT_H
#define DEMO1_SORT_QSORT_H

#include <vector>

template <typename T>
class CQSort
{
private:
    /* data */
public:
    CQSort(/* args */) {}
    ~CQSort() {}

    virtual bool sort(std::vector<T>& vtData) = 0;
};

#endif