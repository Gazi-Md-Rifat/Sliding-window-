#include <iostream>
using namespace std;

// Question : Max Sum Subarray. 30.1

int maxSumSubarray(int arr[], int n, int x, int k)
{

    int sum = 0, ans = 0;
    // in one loop ..  time complexity is O(N);

    // for (int i = 0; i < n; i++){ // O(n);
    //     if (i < k){
    //         sum += arr[i];
    //            if(sum < x){
    //                 ans = sum;
    //             }
    //         continue;
    //     }
    //     else {
    //         sum = sum - arr[i - k] + arr[i];
    //         if (sum < x && sum > ans){
    //                 ans = sum;
    //         }
    //     }
    // }

    // int two loop but time complexity is O(n);

    for (int i = 0; i < k; i++){ // O(k);
        sum += arr[i];
    }
    if (sum < x && sum > ans){
        ans = sum;
    }
    for (int i = k; i < n; i++){ // O(n - k) total is O(k + n - k) == O(N);
        sum = sum - arr[i - k] + arr[i];
        if (sum < x && sum > ans){
            ans = sum;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {2, 5, 3, 6, 7, 4, 3, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 20;
    int k = 3;

    int result = maxSumSubarray(arr, n, x, k);
    cout << result;

    return 0;
}