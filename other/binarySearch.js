let array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
let result = binarySearch(array, array.length / 2, 9);
console.log(result);

function binarySearch(arr, n, target) {
  console.log('next iteration');
  if (arr[n] == target) return true;
  if (arr[n] <= target) binarySearch(arr, n/2, target);
  if (arr[n] <= target) binarySearch(arr, n-1, target);
  return false;
};
