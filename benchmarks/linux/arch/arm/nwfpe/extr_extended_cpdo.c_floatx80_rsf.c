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
typedef  int /*<<< orphan*/  floatx80 ;

/* Variables and functions */
 int /*<<< orphan*/  floatx80_sub (struct roundingData*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static floatx80 floatx80_rsf(struct roundingData *roundData, floatx80 rFn, floatx80 rFm)
{
	return floatx80_sub(roundData, rFm, rFn);
}