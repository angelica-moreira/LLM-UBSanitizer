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

/* Variables and functions */
 int /*<<< orphan*/  bpf_object__close (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  close (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  obj ; 
 int /*<<< orphan*/  outer_map ; 
 int /*<<< orphan*/  reuseport_array ; 

__attribute__((used)) static void cleanup(void)
{
	close(outer_map);
	close(reuseport_array);
	bpf_object__close(obj);
}