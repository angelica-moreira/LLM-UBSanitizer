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
typedef  int /*<<< orphan*/  u32 ;
struct adapter {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  TP_RSS_SECRET_KEY0_A ; 
 int /*<<< orphan*/  t4_tp_pio_read (struct adapter*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int) ; 

void t4_read_rss_key(struct adapter *adap, u32 *key, bool sleep_ok)
{
	t4_tp_pio_read(adap, key, 10, TP_RSS_SECRET_KEY0_A, sleep_ok);
}