int search(int arr[], int left, int right, int number) {
  if (right >= left) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == number)
      return mid;

    if (arr[mid] > number)
      return search(arr, left, mid - 1, number);

    return search(arr, mid + 1, right, number);
  }

  return -1;
}