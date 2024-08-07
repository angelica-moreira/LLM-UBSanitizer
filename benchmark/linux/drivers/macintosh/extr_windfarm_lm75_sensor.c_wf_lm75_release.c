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
struct wf_sensor {int dummy; } ;
struct wf_lm75_sensor {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct wf_lm75_sensor*) ; 
 struct wf_lm75_sensor* wf_to_lm75 (struct wf_sensor*) ; 

__attribute__((used)) static void wf_lm75_release(struct wf_sensor *sr)
{
	struct wf_lm75_sensor *lm = wf_to_lm75(sr);

	kfree(lm);
}