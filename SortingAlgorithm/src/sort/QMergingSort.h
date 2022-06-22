#ifndef DEMO1_SORT_QMERGINGSORT_H
#define DEMO1_SORT_QMERGINGSORT_H

#include "QSort.h"

template <typename T>
class CQMergingSort : public CQSort<T>
{
private:
    /* data */
public:
    CQMergingSort(/* args */){}
    ~CQMergingSort(){}

    virtual bool sort(std::vector<T>& vtData);

private:
    void MergeSort(std::vector<T>& vtData, int nStart, int nEnd);
    void Merge(std::vector<T>& vtData, int nStart, int nMid, int nEnd);
};

#endif