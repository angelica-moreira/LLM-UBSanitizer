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
struct hist_entry {int dummy; } ;

/* Variables and functions */
 void* zalloc (size_t) ; 

__attribute__((used)) static void *hist_entry__zalloc(size_t size)
{
	return zalloc(size + sizeof(struct hist_entry));
}