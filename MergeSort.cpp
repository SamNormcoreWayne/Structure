#include <iostream>
#include <vector>


using namespace std;

int main()
{
    vector<int> S;
    MergeSort(S);
}

void MergeSort(vector<int> s)
{
    int n = s.size();
    int half = 1;
    int left = 0, right = 0, mid = 0;
    while (half < n)
    {
        for (int i = 0; i + half < n; i += 2 * half)
        {
            left = i;
            mid = i + half - 1;
            right = half + half - 1;
            if (right > (n - 1))
                right = n - 1;
            MergeFunc(left, mid, right, s);
        }
        half *= 2;
    }
}


/**
 * MergeFunc
 * To compare the differences bwtween elements in each divided parts
 * and merge them together by their amounts from low to high.
 * @param int left {the left side of a partition}
 * @param int mid {the middle of a partition}
 * @param int right {the right side of a partition}
 * @param vector<int> s {the array needs to be sorted}
 */
void MergeFunc(int left, int mid, int right, vector<int> s)
{
    vector<int> tmp = s;
    int temp = 0;
    int leftIndex = left, rightIndex = mid + 1;
    while (leftIndex < rightIndex && rightIndex < right)
    {
        if (tmp[leftIndex] < tmp[rightIndex])
        {
            if (tmp[rightIndex] < tmp[leftIndex + 1])
            {
                /*
                 * for array, every element after leftIndex and before rightIndex will be removed into leftIndex + 1.
                 * for linked list, this is a insert operation.
                 */
                temp = s[leftIndex + 1];
                tmp[leftIndex + 1] = tmp[rightIndex];
                for (int i = leftIndex + 2; i < rightIndex; ++i)
                    tmp[i] = tmp[i + 1];
                tmp[rightIndex] = temp;
                rightIndex++;
                continue;
            }
            else
            {
                leftIndex++;
                continue;
            }
        }
    }
}