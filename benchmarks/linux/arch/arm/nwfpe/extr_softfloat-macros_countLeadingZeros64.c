#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  scalar_t__ int8 ;
typedef  int bits64 ;

/* Variables and functions */
 scalar_t__ countLeadingZeros32 (int) ; 

__attribute__((used)) static int8 countLeadingZeros64( bits64 a )
{
    int8 shiftCount;

    shiftCount = 0;
    if ( a < ( (bits64) 1 )<<32 ) {
        shiftCount += 32;
    }
    else {
        a >>= 32;
    }
    shiftCount += countLeadingZeros32( a );
    return shiftCount;

}