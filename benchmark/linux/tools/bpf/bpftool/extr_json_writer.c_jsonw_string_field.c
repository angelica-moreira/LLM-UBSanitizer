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
 int /*<<< orphan*/  jsonw_name (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  jsonw_string (int /*<<< orphan*/ *,char const*) ; 

void jsonw_string_field(json_writer_t *self, const char *prop, const char *val)
{
	jsonw_name(self, prop);
	jsonw_string(self, val);
}