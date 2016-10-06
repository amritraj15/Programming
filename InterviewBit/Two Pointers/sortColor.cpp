/*
Given an array with n objects colored red, white or blue, 
sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: Using library sort function is not allowed.

Example :

Input : [0 1 2 0 1 2]
Modify array so that it becomes : [0 0 1 1 2 2]


class Solution {
    public:
        void sortColors(int A[], int n)  {     
            int n = A.size(); 
            int k = n - 1;
            int i = 0;
            for (; i < n; ++i)
            {
                if (A[i] != 0)
                {
                    break;
                }
            }

            int j = i;
            for (; i <= k; ++i)
            {
                if (A[i] == 0)
                {
                    swap(A[j++], A[i]);
                }
                else if (A[i] == 2)
                {
                    swap(A[i--], A[k--]);
                }
            }
        }
};


*/


typedef std::vector<int>::iterator vec_it;
void merge(vec_it left, vec_it left_end, vec_it right, vec_it right_end, vec_it numbers)
{
    while (left != left_end) {
        if (*left < *right || right == right_end) {
            *numbers = *left;
            ++left;
        } else {
            *numbers = *right;
            ++right;
        }

        ++numbers;
    }

    while (right != right_end) {
        *numbers = *right;
        ++right;
        ++numbers;
    }
}

void merge_sort(vector<int>& numbers)
{
    if (numbers.size() <= 1) {
        return;
    }

    vector<int>::size_type middle = numbers.size() / 2;
    vector<int> left(numbers.begin(), numbers.begin() + middle);
    vector<int> right(numbers.begin() + middle, numbers.end());

    merge_sort(left);
    merge_sort(right);

    merge(left.begin(), left.end(), right.begin(), right.end(), numbers.begin());
}



void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    merge_sort(A);
}
