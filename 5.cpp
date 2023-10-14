#include <iostream>
#include <math.h>
using namespace std;

// Question : Count Perfect Number in K subarray
bool perfect(int n){
    int sum = 1;
    for (int i = 2; i < n; i++){
        if (n % i == 0){
            sum += i;
        }
    }

    if (sum == n && n != 1){
        return true;
    }

    return false;
}

int countPerfectNumber(int arr[], int n, int k){

    int sum = 0;
    //count perfect number in  first k subarray.
    for (int i = 0; i < k; i++){ // time o(k);
        if (arr[i] == 1){
            sum += 1;
        }
    }
    if (sum == k){ // extra.. if our perfect number is equal to k thats mean this is the max number in k subarray..becauge we have k size subarray and k times perfect number that means every idx have perfect number in k size subarray..
        return sum; // if return here then time will be O(k);
    }

    // find max perfect number in k subarray in all array
    int ans = sum;

    for (int i = k; i < n; i++){ // time O(n - k);
        sum = sum - arr[i - k] + arr[i];
        ans = max(sum, ans);
    }
    return ans; // if return here time will be O(k) + O(n - k) -> O(n);
}

int perfectNumber(int arr[], int n, int k){;

    // formed arr in binary ..... 1 is for perfect number and 0 is for non perfect number..
    for (int i = 0; i < n; i++){ // time O(n * max(arr[i])) .. becauge perfect function have a loop which run in arr[i]..;;
        if (perfect(arr[i])){
            arr[i] = 1;
        } 
        else {;
            arr[i] = 0;
        }
    }
 
    int ans = countPerfectNumber(arr, n, k); // time best case : O(k) and worst case: O(n);
    return ans; 
    // total time complexity is : worst case :  O(n * max(arr[i])) + O(n)
    // best case : O(n * max(arr[i])) + O(k)

}


int main()
{
    int arr[] = {28,2,3,6,496,99,8128,24};
    // int arr[] = {6,2,6,4,3,8,9,28,28,28};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int result = perfectNumber(arr, n, k);
    if (result == 0){
        cout << "This array have no Perfect Number";
    } else {
        cout << result;
    }



    return 0;
}