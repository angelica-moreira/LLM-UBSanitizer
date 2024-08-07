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
struct dx_entry {int dummy; } ;
struct dx_countlimit {int /*<<< orphan*/  count; } ;

/* Variables and functions */
 int le16_to_cpu (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline unsigned dx_get_count(struct dx_entry *entries)
{
	return le16_to_cpu(((struct dx_countlimit *) entries)->count);
}