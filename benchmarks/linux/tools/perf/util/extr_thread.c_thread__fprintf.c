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
struct thread {int tid; int /*<<< orphan*/  mg; } ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 size_t fprintf (int /*<<< orphan*/ *,char*,int,char*) ; 
 size_t map_groups__fprintf (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 char* thread__comm_str (struct thread*) ; 

size_t thread__fprintf(struct thread *thread, FILE *fp)
{
	return fprintf(fp, "Thread %d %s\n", thread->tid, thread__comm_str(thread)) +
	       map_groups__fprintf(thread->mg, fp);
}