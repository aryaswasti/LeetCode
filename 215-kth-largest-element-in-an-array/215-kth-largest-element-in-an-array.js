/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */

const quickSelect = function(arr, left, right, numToFind)
{
    let piv = partition(arr, left, right);
    if(piv === numToFind)
    {
        return arr[numToFind];   
    }
    else if(numToFind < piv)
    {
        return quickSelect(arr, left, piv - 1, numToFind);   
    }
    else
    {
        return quickSelect(arr, piv + 1, right, numToFind);   
    }
};

const partition = function(arr, left, right)
{
    let i = left;
    
    for(let j = left; j <= right; j++)
    {
        if(arr[j] <= arr[right])
        {
            swap(arr, i, j);
            i++;
        }
    }
    
    return i - 1;
};


const swap = function(arr, i, j)
{
    let temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
};

var findKthLargest = function(nums, k) {
    const numToFind = nums.length - k;
    return quickSelect(nums, 0, nums.length - 1, numToFind);
};