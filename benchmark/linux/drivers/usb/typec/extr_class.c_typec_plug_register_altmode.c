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
struct typec_plug {int /*<<< orphan*/  dev; } ;
struct typec_altmode_desc {int dummy; } ;
struct typec_altmode {int dummy; } ;

/* Variables and functions */
 struct typec_altmode* typec_register_altmode (int /*<<< orphan*/ *,struct typec_altmode_desc const*) ; 

struct typec_altmode *
typec_plug_register_altmode(struct typec_plug *plug,
			    const struct typec_altmode_desc *desc)
{
	return typec_register_altmode(&plug->dev, desc);
}