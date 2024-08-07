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
struct em_sti_priv {int dummy; } ;
struct clocksource {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  USER_CLOCKSOURCE ; 
 struct em_sti_priv* cs_to_em_sti (struct clocksource*) ; 
 int em_sti_start (struct em_sti_priv*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int em_sti_clocksource_enable(struct clocksource *cs)
{
	struct em_sti_priv *p = cs_to_em_sti(cs);

	return em_sti_start(p, USER_CLOCKSOURCE);
}