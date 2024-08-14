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
struct atkbd {int /*<<< orphan*/  force_release_mask; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  ATKBD_KEYMAP_SIZE ; 
 scalar_t__ PAGE_SIZE ; 
 size_t scnprintf (char*,scalar_t__,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t atkbd_show_force_release(struct atkbd *atkbd, char *buf)
{
	size_t len = scnprintf(buf, PAGE_SIZE - 1, "%*pbl",
			       ATKBD_KEYMAP_SIZE, atkbd->force_release_mask);

	buf[len++] = '\n';
	buf[len] = '\0';

	return len;
}