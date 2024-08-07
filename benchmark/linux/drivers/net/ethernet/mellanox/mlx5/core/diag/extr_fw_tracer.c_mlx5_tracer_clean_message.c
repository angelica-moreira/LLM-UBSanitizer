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
struct tracer_string_format {int /*<<< orphan*/  hlist; } ;

/* Variables and functions */
 int /*<<< orphan*/  hlist_del (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct tracer_string_format*) ; 

__attribute__((used)) static void mlx5_tracer_clean_message(struct tracer_string_format *str_frmt)
{
	hlist_del(&str_frmt->hlist);
	kfree(str_frmt);
}