#ifndef SORT_SORT_QCOUNTINGSORT_H
#define SORT_SORT_QCOUNTINGSORT_H

#include "QSort.h"

template <typename T>
class CQCountingSort : public CQSort<T>
{
private:
    /* data */
public:
    CQCountingSort(/* args */){}
    ~CQCountingSort(){}

    virtual bool sort(std::vector<T>& vtData);
};

extern template class CQCountingSort<int>;
extern template class CQCountingSort<long>;

#endif