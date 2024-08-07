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
struct alx_priv {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT_RTNL () ; 
 int /*<<< orphan*/  alx_activate (struct alx_priv*) ; 
 int /*<<< orphan*/  alx_halt (struct alx_priv*) ; 

__attribute__((used)) static void alx_reinit(struct alx_priv *alx)
{
	ASSERT_RTNL();

	alx_halt(alx);
	alx_activate(alx);
}