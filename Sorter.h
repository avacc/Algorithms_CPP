//
//  Sorter.h
//  C++ Programs
//
//  Created by Alex Vaccarino on 10/21/13.
//  Copyright (c) 2013 Alex. All rights reserved.
//

#ifndef __C___Programs__Sorter__
#define __C___Programs__Sorter__

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
vector<T> counting_sort(const vector<T>& unsorted) {
    vector<T> counts(unsorted.size());
    vector<T> sorted(unsorted.size());
    
    for (size_t i = 0; i < unsorted.size(); i++)
        for (size_t j = i + 1; j < unsorted.size(); j++) {
            if (unsorted[i] >= unsorted[j])
                counts[i]++;
            else
                counts[j]++;
        }
    for (size_t i = 0; i < unsorted.size(); i++)
        sorted[counts[i]] = unsorted[i];
    return sorted;
}

template <class T>
vector<T> selection_sort_v1(const vector<T>& unsorted) {
    vector<T> sorted;
    copy(unsorted.begin(), unsorted.end(), sorted);
    
    for (size_t i = 0; i < unsorted.size(); i++)
        for (size_t j = i + 1; j < unsorted.size(); j++)
            if (sorted[i] > sorted[j]) {
                T tmp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = tmp;
            }
    return sorted;
}

template <class T>
vector<T> selection_sort_v2(const vector<T>& unsorted) {
    vector<T> sorted;
    copy(unsorted.begin(), unsorted.end(), sorted);
    
    for (size_t i = 0; i < unsorted.size(); i++) {
        T min = sorted[i];
        int min_idx = -1;
        
        for (size_t j = i + 1; j < unsorted.size(); j++)
            if (min > sorted[j]) {
                min = sorted[j];
                min_idx = (int) j;
            }
        
        if (min_idx != -1) {
            T tmp = sorted[i];
            sorted[i] = sorted[min_idx];
            sorted[min_idx] = tmp;
        }
    }
    return sorted;
}

template <class T>
vector<T> insertion_sort(const vector<T>& unsorted) {
    vector<T> sorted;
    copy(unsorted.begin(), unsorted.end(), sorted);
    
    for (size_t i = 0; i < unsorted.size(); i++)
        for (size_t j = i; j > 0 && sorted[j] < sorted[j - 1]; i--) {
            T tmp = sorted[j];
            sorted[j] = sorted[j - 1];
            sorted[j - 1] = tmp;
        }
    return sorted;
}

template <class T>
vector<T> bubble_sort(const vector<T>& unsorted) {
    vector<T> sorted;
    copy(unsorted.begin(), unsorted.end(), sorted);
    bool swapped;
    
    do {
        swapped = false;
        for (size_t i = 0; i < unsorted.size(); i++) {
            size_t j = i + 1;
            if (sorted[i] > sorted[j]) {
                T tmp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = tmp;
                swapped = true;
            }
        }
    } while (swapped);
    return sorted;
}

#endif /* defined(__C___Programs__Sorter__) */
