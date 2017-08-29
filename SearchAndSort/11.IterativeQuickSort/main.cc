/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/08/29 23:00:59
 * @brief 
 * 
 **/ 
 
int partition(vector<int>& v, int l, int h) {
    int pivot = v[h];
    // i表示最后一个比pivot小的位置
    int i = l - 1;
    for (int j = i; j < h; j++) {
        if (v[j] <= pivot) {
            ++i;
            swap[v[i], v[j]];
        }
    }
    swap(v[i + 1], v[h]);
    return i + 1;
}

void quickSortRecursive(vector<int>& v, int l, int h) {
    if (l >= h) {
        return;
    }
    int mid = partition(v, l, h);
    quickSortRecursive(v, l, mid - 1);
    quickSortRecursive(v, mid + 1, h);
}

void quickSortIterative(vector<int>& v, int l , int h) {
    if (l >= h) {
        return;
    }

    stack<int> s;
    s.push(l);
    s.push(h);
    while (!s.empty()) {
        int h = s.top();
        s.pop();
        int l = s.top();
        s.pop();
        int mid = partition(v, l, h);
        if (l < mid - 1) {
            s.push(l);
            s.push(mid - 1);
        }
        if (mid + 1 < h) {
            s.push(mid + 1);
            s.push(h);
        }
    }
    return;

}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
