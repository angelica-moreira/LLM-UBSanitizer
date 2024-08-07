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
struct audit_buffer {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ima_log_string_op (struct audit_buffer*,char*,char*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void ima_log_string(struct audit_buffer *ab, char *key, char *value)
{
	ima_log_string_op(ab, key, value, NULL);
}