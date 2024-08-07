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
struct v4l2_input {int /*<<< orphan*/  capabilities; int /*<<< orphan*/  status; scalar_t__ std; int /*<<< orphan*/  tuner; int /*<<< orphan*/  audioset; int /*<<< orphan*/  type; int /*<<< orphan*/  name; int /*<<< orphan*/  index; } ;

/* Variables and functions */
 int /*<<< orphan*/  pr_cont (char*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned long long,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void v4l_print_enuminput(const void *arg, bool write_only)
{
	const struct v4l2_input *p = arg;

	pr_cont("index=%u, name=%.*s, type=%u, audioset=0x%x, tuner=%u, std=0x%08Lx, status=0x%x, capabilities=0x%x\n",
		p->index, (int)sizeof(p->name), p->name, p->type, p->audioset,
		p->tuner, (unsigned long long)p->std, p->status,
		p->capabilities);
}