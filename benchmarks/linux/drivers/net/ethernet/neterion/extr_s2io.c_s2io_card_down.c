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
struct s2io_nic {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  do_s2io_card_down (struct s2io_nic*,int) ; 

__attribute__((used)) static void s2io_card_down(struct s2io_nic *sp)
{
	do_s2io_card_down(sp, 1);
}