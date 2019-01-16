#include <iostream>
#include <vector>

using namespace std ;

bool cmp(const int a, const int b)
{
    return a < b ;
}

inline void swap(int &a, int &b)
{
    a ^= b ;
    b ^= a ;
    a ^= b ;
}

void QuickSort(vector<int>::iterator start,
               vector<int>::iterator end,
               bool cmp(const int, const int))
{
    if (start + 1 >= end)
        return ;
    
    vector<int>::iterator i = start, j = end-1 ;
    while (i < j)
    {
        while (cmp(*i, *j))
            --j ;
        
        if (i == j)
            break ;
        else
            swap(*i++, *j) ;
        
        while (cmp(*i, *j))
            ++i ;
        
        if (i != j)
            swap(*i, *j--) ;
    }
    QuickSort(start, i, cmp) ;
    QuickSort(i+1, end, cmp) ;
}