#ifndef DEMO1_SORT_QRadixSORT_H
#define DEMO1_SORT_QRadixSORT_H

#include "QSort.h"

template <typename T>
class CQRadixSort : public CQSort<T>
{
private:
    /* data */
public:
    CQRadixSort(/* args */){}
    ~CQRadixSort(){}

    virtual bool sort(std::vector<T>& vtData);

private:
    int MaxBit(std::vector<T>& vtData);
};

#endif