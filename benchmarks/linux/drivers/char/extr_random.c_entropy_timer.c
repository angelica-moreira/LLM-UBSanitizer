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
struct timer_list {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  credit_entropy_bits (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  input_pool ; 

__attribute__((used)) static void entropy_timer(struct timer_list *t)
{
	credit_entropy_bits(&input_pool, 1);
}