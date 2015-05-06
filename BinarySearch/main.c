//
//  main.c
//  BinarySearch
//
//  Created by Vineet Tiwari on 2015-05-05.
//  Copyright (c) 2015 vinny.co. All rights reserved.
//

#include <stdio.h>

typedef struct {

  int startIndex;
  int count;

} Range;

Range binarySearch( Range, int, int[], int, int);

int findMidIndexPoint(int, int) ;


int main() {

  int numbers[] = {1,2,3,4,5,6,7,7,7,7,8,9,10};

  int lengthArray = sizeof(numbers)/ sizeof(int);

  Range range;

  Range result = binarySearch(range, 7, numbers, 0, lengthArray);

  printf("the start index is %d, count is %d", result.startIndex, result.count);

  return 0;
}


//int binarySearch(int value, int array[], int minimum, int maximum) {
//
//    if (minimum > maximum) {
//      return -1;
//    }
//
//    int midIndex = findMidIndexPoint(minimum, maximum);
//
//    if (value > array[midIndex]) {
//
//      return binarySearch(value, array, (midIndex + 1), maximum);
//
//    } else if (value < array[midIndex]){
//
//      return binarySearch(value, array, minimum, (midIndex - 1));
//
//    } else {
//
//      return midIndex;
//    }
//}


Range binarySearch( Range range, int value, int array[], int minimum, int maximum) {

  if (minimum > maximum) {
    range.startIndex = -1;
    range.count = 0;
    return range ;
  }

  int midIndex = findMidIndexPoint(minimum, maximum);

  if (value > array[midIndex]) {

    return binarySearch(range, value, array, (midIndex + 1), maximum);

  } else if (value < array[midIndex]){

    return binarySearch(range, value, array, minimum, (midIndex - 1));

  } else {
    while (array[midIndex-1] == value) {
      midIndex--;
    }
    range.startIndex = midIndex;
    range.count = 1;
    while (array[midIndex + 1] == value) {
      range.count++;
      midIndex++;
    }
    return range ;
  }
}


int findMidIndexPoint(int minIndex, int maxIndex) {

  return (( maxIndex + minIndex) / 2);
}

























