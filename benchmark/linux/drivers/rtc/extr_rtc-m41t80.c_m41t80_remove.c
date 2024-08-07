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
struct m41t80_data {int features; } ;
struct i2c_client {int dummy; } ;

/* Variables and functions */
 int M41T80_FEATURE_HT ; 
 struct m41t80_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  misc_deregister (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  unregister_reboot_notifier (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wdt_dev ; 
 int /*<<< orphan*/  wdt_notifier ; 

__attribute__((used)) static int m41t80_remove(struct i2c_client *client)
{
#ifdef CONFIG_RTC_DRV_M41T80_WDT
	struct m41t80_data *clientdata = i2c_get_clientdata(client);

	if (clientdata->features & M41T80_FEATURE_HT) {
		misc_deregister(&wdt_dev);
		unregister_reboot_notifier(&wdt_notifier);
	}
#endif

	return 0;
}