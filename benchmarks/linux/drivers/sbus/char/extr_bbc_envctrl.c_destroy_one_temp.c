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
struct bbc_cpu_temperature {int /*<<< orphan*/  client; } ;

/* Variables and functions */
 int /*<<< orphan*/  bbc_i2c_detach (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct bbc_cpu_temperature*) ; 

__attribute__((used)) static void destroy_one_temp(struct bbc_cpu_temperature *tp)
{
	bbc_i2c_detach(tp->client);
	kfree(tp);
}