#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  s64 ;
struct TYPE_2__ {scalar_t__ nan2008; } ;

/* Variables and functions */
 int /*<<< orphan*/  S64_MAX ; 
 TYPE_1__ ieee754_csr ; 

__attribute__((used)) static inline s64 ieee754di_indef(void)
{
	return ieee754_csr.nan2008 ? 0 : S64_MAX;
}