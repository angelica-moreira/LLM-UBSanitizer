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
struct audit_chunk {int /*<<< orphan*/  head; } ;

/* Variables and functions */
 int /*<<< orphan*/  __put_chunk ; 
 int /*<<< orphan*/  call_rcu (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void audit_mark_put_chunk(struct audit_chunk *chunk)
{
	call_rcu(&chunk->head, __put_chunk);
}