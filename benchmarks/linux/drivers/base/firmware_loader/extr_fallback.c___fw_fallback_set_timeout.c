#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int loading_timeout; } ;

/* Variables and functions */
 TYPE_1__ fw_fallback_config ; 

__attribute__((used)) static void __fw_fallback_set_timeout(int timeout)
{
	fw_fallback_config.loading_timeout = timeout;
}