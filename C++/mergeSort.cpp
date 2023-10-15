#include <iostream>
#include <vector>

using namespace std;


void merge(vector<int> &v, int begin, int mid, int end)
{
    vector<int> aux(end - begin);

    int i = begin;
    int j = mid;
    int k = 0;

    while (i < mid && j < end) {
        if (v[i] < v[j]) {
            aux[k] = v[i++];
        } else {
            aux[k] = v[j++];
        }
        k++;
    }
    while (i < mid) {
        aux[k++] = v[i++];
    }
    while (j < end) {
        aux[k++] = v[j++];
    }
    for (auto i = 0; i < aux.size(); i++) {
        v[begin + i] = aux[i];
    }
}

void mergeSort(vector<int> &v, int begin, int end)
{
    if (end - begin <= 1) {
        return;
    }

    int mid = begin + (end - begin) / 2;

    mergeSort(v, begin, mid);
    mergeSort(v, mid, end);

    merge(v, begin, mid, end);

}

void printArray(vector<int> v)
{
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ((i == v.size() -1) ? "\n" : " ");
    }
}

int main()
{
    vector<int> v = {2, 3, 1, 7, 5, 4, 6, 8, 2};

    printArray(v);
    mergeSort(v, 0, v.size());
    printArray(v);

    return 0;
}