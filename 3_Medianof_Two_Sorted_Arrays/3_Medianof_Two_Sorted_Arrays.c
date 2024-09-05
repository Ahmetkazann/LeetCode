#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int nums3Size = nums1Size + nums2Size;
    int nums3[nums3Size];

    int i = 0, j = 0, counter = 0;

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] <= nums2[j]) {
            nums3[counter++] = nums1[i++];
        } else {
            nums3[counter++] = nums2[j++];
        }
    }
    // ADD REST OF THE ELEMENT FROM AN ARRAY
    while (i < nums1Size) {
        nums3[counter++] = nums1[i++];
    }

    while (j < nums2Size) {
        nums3[counter++] = nums2[j++];
    }

    if (nums3Size % 2 == 1) {
        return nums3[nums3Size / 2];
    } else {
        return (nums3[nums3Size / 2 - 1] + nums3[nums3Size / 2]) / 2.0;
    }
}

int main()
{
    int nums1[2] = {1,2};
    int nums2[2] = {3,4};


    printf("%f",findMedianSortedArrays(nums1, 2, nums2, 2));
    return 0;
}
