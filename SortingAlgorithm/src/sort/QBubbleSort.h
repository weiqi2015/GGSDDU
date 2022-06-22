#ifndef DEMO1_SORT_QBUBBLESORT_H
#define DEMO1_SORT_QBUBBLESORT_H

#include "QSort.h"

template <typename T>
class CQBubbleSort : public CQSort<T>
{
private:
    /* data */
public:
    CQBubbleSort(/* args */){}
    ~CQBubbleSort(){}

    virtual bool sort(std::vector<T>& vtData);
};

#endif