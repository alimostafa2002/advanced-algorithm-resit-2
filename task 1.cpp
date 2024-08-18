#include <iostream>
#include <vector>

using namespace std;

void rearrange(vector<int>& A, int k, int start, int end) {
    if (start >= end) return;

    while (start <= end && A[start] <= k) start++;
    while (start <= end && A[end] > k) end--;

    if (start < end) {
        swap(A[start], A[end]);
        rearrange(A, k, start, end);
    }
}

int main() {
    vector<int> A = {3, 5, 2, 8, 6, 1, 4};
    int k = 4;

    rearrange(A, k, 0, A.size() - 1);

    for (int num : A) {
        cout << num << " ";
    }
    return 0;
}