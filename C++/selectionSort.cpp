#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        swap(v[i], v[menor]);
    }
}

void printArray(vector<int> v)
{
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ((i == v.size() -1) ? "\n" : " ");
    }
}

int main()
{
    vector<int> v = {5, 6, 3, 1, 8, 7, 2, 4};

    printArray(v);
    selectionSort(v);
    printArray(v);

    return 0;
}