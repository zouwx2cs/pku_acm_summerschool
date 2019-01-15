#include <iostream>
#include <vector>

using namespace std ;

bool cmp(const int a, const int b)
{
    return a < b ;
}

void MergeSort(vector<int>::iterator start,
               vector<int>::iterator end,
               bool cmp(const int, const int))
{
    if (start + 1 >= end)
        return ;
    
    vector<int>::iterator mid = start + ((end - start) >> 1) ;
    MergeSort(start, mid, cmp) ;
    MergeSort(mid, end, cmp) ;
    
    vector<int> tmp(start, mid) ;
    
    vector<int>::iterator p = start, p1 = tmp.begin(), p2 = mid ;
    while (p1 != tmp.end() && p2 != end)
    {
        if (cmp(*p1, *p2))
            *p++ = *p1++ ;
        else
            *p++ = *p2++ ;
    }
    
    while (p1 != tmp.end())
        *p++ = *p1++ ;
    
    while (p2 != end)
        *p++ = *p2++ ;
}