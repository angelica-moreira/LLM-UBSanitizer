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
struct roundingData {int dummy; } ;
typedef  int /*<<< orphan*/  float32 ;
typedef  scalar_t__ flag ;

/* Variables and functions */
 int /*<<< orphan*/  addFloat32Sigs (struct roundingData*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ extractFloat32Sign (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  subFloat32Sigs (struct roundingData*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 

float32 float32_add( struct roundingData *roundData, float32 a, float32 b )
{
    flag aSign, bSign;

    aSign = extractFloat32Sign( a );
    bSign = extractFloat32Sign( b );
    if ( aSign == bSign ) {
        return addFloat32Sigs( roundData, a, b, aSign );
    }
    else {
        return subFloat32Sigs( roundData, a, b, aSign );
    }

}