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
typedef  int /*<<< orphan*/  u16 ;
struct c67x00_sie {int /*<<< orphan*/  sie_num; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  HUSB_SIE_pCurrentTDPtr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hpi_read_word (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

u16 c67x00_ll_husb_get_current_td(struct c67x00_sie *sie)
{
	return hpi_read_word(sie->dev, HUSB_SIE_pCurrentTDPtr(sie->sie_num));
}