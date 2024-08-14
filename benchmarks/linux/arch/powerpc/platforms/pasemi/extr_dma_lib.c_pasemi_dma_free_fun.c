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

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int MAX_FLAGS ; 
 int /*<<< orphan*/  fun_free ; 
 int /*<<< orphan*/  set_bit (int,int /*<<< orphan*/ ) ; 
 int test_bit (int,int /*<<< orphan*/ ) ; 

void pasemi_dma_free_fun(int fun)
{
	BUG_ON(test_bit(fun, fun_free));
	BUG_ON(fun >= MAX_FLAGS);
	set_bit(fun, fun_free);
}