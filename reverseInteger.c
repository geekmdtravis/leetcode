#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int reverse(int x);

int main() {
    int result = reverse(-2147483412);
    printf("Result: %d", result);
    return 0;
}

int reverse(int x) {
    char *tmp = malloc(12 * sizeof(char));
    sprintf(tmp, "%d\n", x);

    int numChars = 0;
    for (numChars = 0; tmp[numChars] != '\n'; numChars++);

    short isNegative = x < 0 ? 1 : 0;
    int numDigits = isNegative ? numChars - 1 : numChars;

    char reversedString[numChars + 1];
    memset(reversedString, '\0', numChars);

    if (isNegative) 
        reversedString[0] = '-';

    int indexOffest = isNegative ? 1 : 0;
    for (int i = 0 ; i < numDigits ; i++) {
        reversedString[i + indexOffest] = tmp[numChars - 1 - i];
    }

    long reversed = atol(reversedString);
    return (reversed > INT_MAX || reversed < INT_MIN) ? 0 : (int)(reversed);
}


// =================================================================
// ==31==ERROR: AddressSanitizer: dynamic-stack-buffer-overflow on address 0x7fffafe8fd63 at pc 0x7fadf543d630 bp 0x7fffafe8fce0 sp 0x7fffafe8f488
// READ of size 4 at 0x7fffafe8fd63 thread T0
//     #0 0x7fadf543d62f  (/lib/x86_64-linux-gnu/libasan.so.5+0x5662f)
//     #1 0x7fadf543dd90 in strtol (/lib/x86_64-linux-gnu/libasan.so.5+0x56d90)
//     #4 0x7fadf48af0b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
// Address 0x7fffafe8fd63 is located in stack of thread T0
// SUMMARY: AddressSanitizer: dynamic-stack-buffer-overflow (/lib/x86_64-linux-gnu/libasan.so.5+0x5662f) 
// Shadow bytes around the buggy address:
//   0x100075fc9f50: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x100075fc9f60: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x100075fc9f70: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x100075fc9f80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x100075fc9f90: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
// =>0x100075fc9fa0: 00 00 00 00 00 00 00 00 ca ca ca ca[03]cb cb cb
//   0x100075fc9fb0: cb cb cb cb 00 00 00 00 00 00 00 00 00 00 00 00
//   0x100075fc9fc0: 00 00 00 00 f1 f1 f1 f1 00 04 f2 f2 00 00 00 00
//   0x100075fc9fd0: 00 00 00 00 00 00 00 00 00 00 00 00 f1 f1 f1 f1
//   0x100075fc9fe0: 00 f2 f2 f2 f2 f2 f2 f2 00 f2 f2 f2 f2 f2 f2 f2
//   0x100075fc9ff0: 04 f2 f2 f2 00 00 00 00 00 00 00 00 00 00 00 00
// Shadow byte legend (one shadow byte represents 8 application bytes):
//   Addressable:           00
//   Partially addressable: 01 02 03 04 05 06 07 
//   Heap left redzone:       fa
//   Freed heap region:       fd
//   Stack left redzone:      f1
//   Stack mid redzone:       f2
//   Stack right redzone:     f3
//   Stack after return:      f5
//   Stack use after scope:   f8
//   Global redzone:          f9
//   Global init order:       f6
//   Poisoned by user:        f7
//   Container overflow:      fc
//   Array cookie:            ac
//   Intra object redzone:    bb
//   ASan internal:           fe
//   Left alloca redzone:     ca
//   Right alloca redzone:    cb
//   Shadow gap:              cc
// ==31==ABORTING