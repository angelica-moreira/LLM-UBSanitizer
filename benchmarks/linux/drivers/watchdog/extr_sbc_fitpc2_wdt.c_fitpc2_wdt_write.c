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
struct file {int dummy; } ;
typedef  size_t ssize_t ;
typedef  int /*<<< orphan*/  loff_t ;

/* Variables and functions */
 size_t EFAULT ; 
 int /*<<< orphan*/  WDT_OK_TO_CLOSE ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ get_user (char,char const*) ; 
 scalar_t__ nowayout ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wdt_enable () ; 
 int /*<<< orphan*/  wdt_status ; 

__attribute__((used)) static ssize_t fitpc2_wdt_write(struct file *file, const char *data,
						size_t len, loff_t *ppos)
{
	size_t i;

	if (!len)
		return 0;

	if (nowayout) {
		len = 0;
		goto out;
	}

	clear_bit(WDT_OK_TO_CLOSE, &wdt_status);

	for (i = 0; i != len; i++) {
		char c;

		if (get_user(c, data + i))
			return -EFAULT;

		if (c == 'V')
			set_bit(WDT_OK_TO_CLOSE, &wdt_status);
	}

out:
	wdt_enable();

	return len;
}