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
struct watchdog_device {int dummy; } ;
struct rwdt_priv {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  RWTCNT ; 
 int /*<<< orphan*/  rwdt_start (struct watchdog_device*) ; 
 int /*<<< orphan*/  rwdt_write (struct rwdt_priv*,int,int /*<<< orphan*/ ) ; 
 struct rwdt_priv* watchdog_get_drvdata (struct watchdog_device*) ; 

__attribute__((used)) static int rwdt_restart(struct watchdog_device *wdev, unsigned long action,
			void *data)
{
	struct rwdt_priv *priv = watchdog_get_drvdata(wdev);

	rwdt_start(wdev);
	rwdt_write(priv, 0xffff, RWTCNT);
	return 0;
}