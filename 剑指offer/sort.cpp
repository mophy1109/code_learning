#include <iostream>

using namespace std;

#define MAX_NUM 100000

class sort {
public:
    void ShellSort(int data[], int length)
    {
        int gap = length;
        while (gap > 1) {
            gap = gap / 3 + 1;
            for (int i = gap; i < length; i += gap) {
                int current = data[i];
                int preIndex = i - gap;
                while (preIndex >= 0 && data[preIndex] > current) {
                    data[i]  = data[preIndex];
                    preIndex -= gap;
                }
                data[preIndex + gap] = current;
            }
        }
    }

    // 归并两个部分
    // 第一个子序列是 data[l..m]
    // 第二个子序列是 data[m+1..r]
    void merge(int data[], int l, int m, int r)
    {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        /* create temp arrays */
        int L[n1], R[n2];

        /* Copy data to temp arrays L[] and R[] */
        for (i = 0; i < n1; i++)
            L[i] = data[l + i];
        for (j = 0; j < n2; j++)
            R[j] = data[m + 1 + j];

        /* Merge the temp arrays back into data[l..r]*/
        i = 0; // Initial index of first subdataay
        j = 0; // Initial index of second subdataay
        k = l; // Initial index of merged subdataay
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                data[k] = L[i];
                i++;
            } else {
                data[k] = R[j];
                j++;
            }
            k++;
        }

        /* Copy the remaining elements of L[], if there
       are any */
        while (i < n1) {
            data[k] = L[i];
            i++;
            k++;
        }

        /* Copy the remaining elements of R[], if there
       are any */
        while (j < n2) {
            data[k] = R[j];
            j++;
            k++;
        }
    }

    /* l is for left index and r is right index of the
   sub-dataay of data to be sorted */
    void mergeSort(int data[], int l, int r)
    {
        if (l < r) {
            // Same as (l+r)/2, but avoids overflow for
            // large l and h
            int m = l + (r - l) / 2;

            // Sort first and second halves
            mergeSort(data, l, m);
            mergeSort(data, m + 1, r);

            merge(data, l, m, r);
        }
    }

    /* UTILITY FUNCTIONS */
    /* Function to print an dataay */
    void printdataay(int A[], int size)
    {
        int i;
        for (i = 0; i < size; i++)
            printf("%d ", A[i]);
        printf("\n");
    }

    /* Driver program to test above functions */
    int main()
    {
        int data[] = {12, 11, 13, 5, 6, 7};
        int data_size = sizeof(data) / sizeof(data[0]);

        printf("Given dataay is \n");
        printdataay(data, data_size);

        mergeSort(data, 0, data_size - 1);

        printf("\nSorted dataay is \n");
        printdataay(data, data_size);
        return 0;
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

    void MergeSort(int data[], int length, int start, int end)
    {
        // to be complished
        if (start == end)
            return;

        if (data == NULL || start < 0 || start > end || end >= length) {
            throw runtime_error("Invalid Data");
        }
    }

    void CountingSort(int data[], int length)
    {
        //计数排序仅适用于已知数字范围的情形, 此处假设数小于100000

        if (data == NULL || length <= 0) {
            throw runtime_error("Invalid Data");
        }

        int count[MAX_NUM], result[length] = {0};

        //这步之后，count[i] 中保存的数字是i在data中出现的次数
        for (int i = 0; i < length; i++) {
            count[data[i]]++;
        }

        //这步之后count[i]保存小于等于i的数字出现的次数
        for (int i = 1; i < MAX_NUM; i++) {
            count[i] = count[i - 1] + count[i];
        }

        for (int i = length - 1; i >= 0; i--) {
            result[count[data[i]] - 1] = data[i];
            count[data[i]]--;
        }

        for (int i = 0; i < length; i++) {
            data[i] = result[i];
        }
    }

private:
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
        if (data == NULL || start < 0 || end >= length || end < start) {
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
};

void printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++) {
        cout << arr[i];
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int a[255];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort().CountingSort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
