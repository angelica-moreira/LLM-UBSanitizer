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
struct serio {int dummy; } ;
struct iforce {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  iforce_serio_xmit (struct iforce*) ; 
 struct iforce* serio_get_drvdata (struct serio*) ; 

__attribute__((used)) static void iforce_serio_write_wakeup(struct serio *serio)
{
	struct iforce *iforce = serio_get_drvdata(serio);

	iforce_serio_xmit(iforce);
}