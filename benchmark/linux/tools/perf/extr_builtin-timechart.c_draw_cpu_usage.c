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
struct timechart {struct per_pid* all_data; } ;
struct per_pidcomm {struct per_pidcomm* next; int /*<<< orphan*/  comm; struct cpu_sample* samples; } ;
struct per_pid {struct per_pid* next; int /*<<< orphan*/  pid; struct per_pidcomm* all; } ;
struct cpu_sample {scalar_t__ type; struct cpu_sample* next; int /*<<< orphan*/  backtrace; int /*<<< orphan*/  end_time; int /*<<< orphan*/  start_time; int /*<<< orphan*/  cpu; } ;

/* Variables and functions */
 scalar_t__ TYPE_RUNNING ; 
 int /*<<< orphan*/  svg_process (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void draw_cpu_usage(struct timechart *tchart)
{
	struct per_pid *p;
	struct per_pidcomm *c;
	struct cpu_sample *sample;
	p = tchart->all_data;
	while (p) {
		c = p->all;
		while (c) {
			sample = c->samples;
			while (sample) {
				if (sample->type == TYPE_RUNNING) {
					svg_process(sample->cpu,
						    sample->start_time,
						    sample->end_time,
						    p->pid,
						    c->comm,
						    sample->backtrace);
				}

				sample = sample->next;
			}
			c = c->next;
		}
		p = p->next;
	}
}