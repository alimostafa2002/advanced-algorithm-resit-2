#include <iostream>
#include <vector>
using namespace std

void swap(int i, int j, vector<int>& array) {
    swap(array[i], array[j]);
}
// C++ program for implementation of Heap Sort



// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void normalheapify(int arr[], int N, int i)
{

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        normalheapify(arr, N, largest);
    }
}

// Main function to do heap sort
void normalheapSort(int arr[], int N)
{

    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        normalheapify(arr, N, i);

    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        normalheapify(arr, i, 0);
    }
}

// A utility function to print array of size n
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver's code

void heapify(int currentIdx, int endIdx, std::vector<int>& array) {
    int leftChildIdx = 2 * currentIdx + 1;
    while (leftChildIdx <= endIdx) {
        int rightChildIdx = (2 * currentIdx + 2 <= endIdx) ? 2 * currentIdx + 2 : -1;
        int largestChildIdx = leftChildIdx;
        if (rightChildIdx != -1 && array[leftChildIdx] < array[rightChildIdx]) {
            largestChildIdx = rightChildIdx;
        }

        if (array[currentIdx] < array[largestChildIdx]) {
            swap(currentIdx, largestChildIdx, array);
            currentIdx = largestChildIdx;
            leftChildIdx = 2 * currentIdx + 1;
        } else {
            return;
        }
    }
}

void buildMaxHeap(vector<int>& array) {
    int lastNonLeafNodeIdx = (array.size() - 2) / 2;
    for (int currentIdx = lastNonLeafNodeIdx; currentIdx >= 0; --currentIdx) {
        heapify(currentIdx, array.size() - 1, array);
    }
}

vector<int> heapSort(vector<int>& array) {
    buildMaxHeap(array);
    for (int endIdx = array.size() - 1; endIdx > 0; --endIdx) {
        swap(0, endIdx, array);
        heapify(0, endIdx - 1, array);
    }
    return array;
}

int main() {
    vector<int> array = {1, -15, 22, 40, 9, 91};
    array = heapSort(array);
    for (int num : array) {
        cout << num << " ";
    }
    return 0;
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    heapSort(arr, N);

    cout << "Sorted array is \n";
    printArray(arr, N);
}

