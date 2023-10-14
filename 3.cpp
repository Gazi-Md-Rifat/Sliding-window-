#include <iostream>
using namespace std;

// Question : Number formed from subarray of size k, which is divisible by x; vide0 is 30.3;

void numberFormedDivisible(int arr[], int n, int x, int k){

    int sum = 0;
    pair<int, int> range; // store subarray starting point and end point for valid condition;
    bool found = false;
    for (int i = 0; i < k; i++){ // time is O(k);
        sum = sum + arr[i];
    }
    if (sum % x == 0){
        range = make_pair(0,k - 1); //for if first subarry is valid 
        found = !found;
    }
    else { // for not valid first subarray..
        for (int i = k; i < n; i++){ // time is O(n - k);
            sum = sum - arr[i - k] + arr[i];
            if (sum % x == 0){
                range = make_pair(i - k + 1, i);// i - k is element that is (start subarray - 1)..so start is (i - k + 1)
                found = !found;
                break;
            }
            
        }
    }
    //.................................... Time ................................
    // maximum case is O(k) + O(n - k) -> O(n);
    // minimum case is O(k); .. becauge if i found validation in first subarray then we don't need to travel next subarray..

    //  print funtion have O(k) time..becauge we print K X element..

    // if i haven't valid subarray which is divisible by x..so default is;
    if (found){
        for (int i = range.first; i <= range.second; i++){
            cout << arr[i] << " ";
        }
    }
    else {
        cout << "This is Invalid situation";
    }
}

int main()
{
    int arr[] = {2, 5, 3, 6, 7, 4, 3, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    int k = 4;

    numberFormedDivisible(arr, n, x, k);


    return 0;
}