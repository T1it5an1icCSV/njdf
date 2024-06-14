#include <iostream>
#include <vector>
#include <thread>
#include <functional>
using namespace std;

class MergeSort {
public:
    void Sort(vector<int>& array) {
        if (array.size() > 1) {
            vector<int> left(array.begin(), array.begin() + array.size() / 2);
            vector<int> right(array.begin() + array.size() / 2, array.end());
            thread left_thread(&MergeSort::Sort, this, ref(left));
            thread right_thread(&MergeSort::Sort, this, ref(right));
            left_thread.join();
            right_thread.join();
            Merge(array, left, right);
        }
    }

private:
    void Merge(vector<int>& array, const vector<int>& left, const vector<int>& right) {
        size_t i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                array[k++] = left[i++];
            }
            else {
                array[k++] = right[j++];
            }
        }
        while (i < left.size()) {
            array[k++] = left[i++];
        }
        while (j < right.size()) {
            array[k++] = right[j++];
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> array(10);
    cout << "Введите 10 целых чисел: ";
    for (int i = 0; i < 10; ++i) {
        cin >> array[i];
    }


    MergeSort sorter;


    auto sort_func = [&sorter](vector<int>& arr) {
        sorter.Sort(arr);
        };


    thread sort_thread(sort_func, ref(array));
    sort_thread.join();


    cout << "Отсортированный массив: ";
    for (const int& num : array) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
