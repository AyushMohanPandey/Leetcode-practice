/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let newArr= [];
    let temp =0;
    for(let i=0; i<arr.length ; i++)
    {
        if(fn(arr[i],i))
        newArr[temp++] = arr[i];
    }
    return newArr;
};