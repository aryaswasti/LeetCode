/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */

const quickSort = function(arr, left, right)
{
    if(left < right)
    {
        const partitionIdx = partition(arr, left, right);
        quickSort(arr, left, partitionIdx - 1);
        quickSort(arr, partitionIdx + 1, right);
    }
}

const partition = function(arr, left, right)
{
    let pivElement = arr[right];
    let i = left;
    
    for(let j = left; j < right; j++)
    {
        if(arr[j] < pivElement)
        {
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, i, right);
    return i;
}

const swap = function(arr, i, j)
{
    let temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

var findKthLargest = function(nums, k) {
    const numToFind = nums.length - k;
    quickSort(nums, 0, nums.length - 1);
    return nums[numToFind];
};