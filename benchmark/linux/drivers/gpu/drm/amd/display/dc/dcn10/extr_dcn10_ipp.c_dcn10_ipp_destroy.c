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
struct input_pixel_processor {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  TO_DCN10_IPP (struct input_pixel_processor*) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void dcn10_ipp_destroy(struct input_pixel_processor **ipp)
{
	kfree(TO_DCN10_IPP(*ipp));
	*ipp = NULL;
}