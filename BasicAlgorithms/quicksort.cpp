#include <ctime>
#include <iostream>
using namespace std;

int RandomInRange(int start, int end)
{
    srand((unsigned) time(NULL));
    int value = rand() % (end - start + 1) + start;
    return value;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int data[], int length, int start, int end)
{
    if (data == NULL || length <= 0 || start < 0 || end >= length || end <= start) {
        throw runtime_error("Invalid data");
    }

    int index = RandomInRange(start, end);
    swap(&data[index], &data[end]);

    int small = start - 1;
    for (index = start; index < end; index++) {
        if (data[index] <= data[end]) {
            small++;
            swap(&data[index], &data[small]);
        }
    }
    small++;
    swap(&data[small], &data[end]);
    return small;
}

void QuickSort(int data[], int length, int start, int end)
{
    if (start == end) {
        return;
    }

    int index = Partition(data, length, start, end);
    if (index > start) {
        QuickSort(data, length, start, index - 1);
    }
    if (index < end) {
        QuickSort(data, length, index + 1, end);
    }
    return;
}

int main()
{
    int a[255];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    QuickSort(a, n, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}