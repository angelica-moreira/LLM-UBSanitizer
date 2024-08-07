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
struct hl_ctx_mgr {int /*<<< orphan*/  ctx_handles; int /*<<< orphan*/  ctx_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  idr_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 

void hl_ctx_mgr_init(struct hl_ctx_mgr *mgr)
{
	mutex_init(&mgr->ctx_lock);
	idr_init(&mgr->ctx_handles);
}