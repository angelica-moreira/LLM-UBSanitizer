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
typedef  int uint32_t ;

/* Variables and functions */
 int LOG2_E_100X ; 
 int intlog2 (int) ; 

__attribute__((used)) static uint32_t sony_log(uint32_t x)
{
	return (((10000>>8)*(intlog2(x)>>16) + LOG2_E_100X/2)/LOG2_E_100X);
}