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
struct pi_desc {scalar_t__ pir; } ;

/* Variables and functions */
 int /*<<< orphan*/  NR_VECTORS ; 
 int bitmap_empty (unsigned long*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool pi_is_pir_empty(struct pi_desc *pi_desc)
{
	return bitmap_empty((unsigned long *)pi_desc->pir, NR_VECTORS);
}