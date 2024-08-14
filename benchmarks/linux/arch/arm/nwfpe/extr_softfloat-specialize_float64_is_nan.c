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
typedef  int float64 ;
typedef  int flag ;
typedef  scalar_t__ bits64 ;

/* Variables and functions */
 scalar_t__ LIT64 (int) ; 

flag float64_is_nan( float64 a )
{

    return ( LIT64( 0xFFE0000000000000 ) < (bits64) ( a<<1 ) );

}