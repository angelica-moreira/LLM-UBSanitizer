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
struct sh_fpu_soft_struct {int dummy; } ;

/* Variables and functions */
 int FRn ; 
 int _FP_W_TYPE_SIZE ; 

__attribute__((used)) static int fabs(struct sh_fpu_soft_struct *fregs, int n)
{
	FRn &= ~(1 << (_FP_W_TYPE_SIZE - 1));
	return 0;
}