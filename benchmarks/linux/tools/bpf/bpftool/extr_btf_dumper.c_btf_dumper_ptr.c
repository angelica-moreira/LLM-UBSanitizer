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
typedef  int /*<<< orphan*/  json_writer_t ;

/* Variables and functions */
 int /*<<< orphan*/  jsonw_printf (int /*<<< orphan*/ *,char*,unsigned long) ; 

__attribute__((used)) static void btf_dumper_ptr(const void *data, json_writer_t *jw,
			   bool is_plain_text)
{
	if (is_plain_text)
		jsonw_printf(jw, "%p", data);
	else
		jsonw_printf(jw, "%lu", *(unsigned long *)data);
}