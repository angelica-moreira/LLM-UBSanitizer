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
struct kcore_extract {int /*<<< orphan*/  extract_filename; } ;

/* Variables and functions */
 int /*<<< orphan*/  unlink (int /*<<< orphan*/ ) ; 

void kcore_extract__delete(struct kcore_extract *kce)
{
	unlink(kce->extract_filename);
}