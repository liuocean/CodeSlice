#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

int
min(int arr[], int n)
{
    if (arr == NULL || n <= 0) {
        std::cerr << "The array is NULL or empty.\n";
        exit(1);
    }
    int left = 0;
    int right = n - 1;
	int mid;
	int mini=INT_MAX;
    if (arr[right] > arr[left]) {   //判断数组是不是递增的
        return arr[left];
    }
    while (left < right - 1) { //防止死循环 int mid = (left + right) / 2;
		mid=left +( (right - left)>>1 );
        if (arr[left] == arr[mid] && arr[mid] == arr[right]) { 
       //注意这里也可以使用 high--;continue;其实low--也可以 int mini = arr[left];
            for (int i = left + 1; i <= right; ++i) {
                if (arr[i] < mini) {
                    mini = arr[i];
                    break;
                }
            }
            return mini;
        }
        if (arr[mid] >= arr[left]) {
            left = mid;
        }

        else if (arr[mid] <= arr[right]) {
            right = mid;
        }
		else return arr[right];
    }
    return arr[right];
}

int
main(){
	int array[]={5, 4,3,2,1};
	int result=min(array, sizeof(array)/sizeof(int));
	cout<<result<<endl;
	return 0;
}
