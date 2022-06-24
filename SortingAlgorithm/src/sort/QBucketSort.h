#ifndef SORT_SORT_QBUCKETSORT_H
#define SORT_SORT_QBUCKETSORT_H

#include "QSort.h"

template <typename T>
class CQBucketSort : public CQSort<T>
{
private:
    /* data */
public:
    CQBucketSort(/* args */){}
    ~CQBucketSort(){}

    virtual bool sort(std::vector<T>& vtData);
};

extern template class CQBucketSort<int>;
extern template class CQBucketSort<long>;

#endif