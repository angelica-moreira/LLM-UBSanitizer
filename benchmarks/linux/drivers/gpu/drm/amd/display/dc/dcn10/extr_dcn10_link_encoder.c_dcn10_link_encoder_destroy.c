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
struct link_encoder {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  TO_DCN10_LINK_ENC (struct link_encoder*) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 

void dcn10_link_encoder_destroy(struct link_encoder **enc)
{
	kfree(TO_DCN10_LINK_ENC(*enc));
	*enc = NULL;
}