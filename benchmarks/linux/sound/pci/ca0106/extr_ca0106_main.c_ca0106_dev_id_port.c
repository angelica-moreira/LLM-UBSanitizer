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
struct snd_ca0106 {int port; } ;

/* Variables and functions */

__attribute__((used)) static int ca0106_dev_id_port(void *dev_id)
{
	return ((struct snd_ca0106 *)dev_id)->port;
}