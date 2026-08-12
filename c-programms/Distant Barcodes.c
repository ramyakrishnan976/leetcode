#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeBarcodes(int* barcodes, int barcodesSize, int* returnSize) {
    // Step 1: Create a frequency map based on constraints (1 <= barcodes[i] <= 10000)
    int count[10005] = {0};
    int max_freq = 0;
    int max_barcode = 0;
    
    for (int i = 0; i < barcodesSize; i++) {
        count[barcodes[i]]++;
        // Keep track of the absolute most frequent barcode
        if (count[barcodes[i]] > max_freq) {
            max_freq = count[barcodes[i]];
            max_barcode = barcodes[i];
        }
    }
    
    // Allocate memory for the returning rearranged array
    int* result = (int*)malloc(barcodesSize * sizeof(int));
    int index = 0;
    
    // Step 2: Fill the most frequent barcode first into alternating positions
    for (int i = 0; i < max_freq; i++) {
        result[index] = max_barcode;
        index += 2;
        // Wrap around to odd indices if we hit or exceed the array boundaries
        if (index >= barcodesSize) {
            index = 1;
        }
    }
    
    // Clear its frequency count so we don't process it again
    count[max_barcode] = 0;
    
    // Step 3: Fill the remaining barcodes into the rest of the alternating positions
    for (int b = 1; b <= 10000; b++) {
        while (count[b] > 0) {
            result[index] = b;
            index += 2;
            if (index >= barcodesSize) {
                index = 1;
            }
            count[b]--;
        }
    }
    
    *returnSize = barcodesSize;
    return result;
}
