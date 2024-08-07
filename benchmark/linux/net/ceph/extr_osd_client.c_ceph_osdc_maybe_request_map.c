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
struct ceph_osd_client {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  down_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  maybe_request_map (struct ceph_osd_client*) ; 
 int /*<<< orphan*/  up_read (int /*<<< orphan*/ *) ; 

void ceph_osdc_maybe_request_map(struct ceph_osd_client *osdc)
{
	down_read(&osdc->lock);
	maybe_request_map(osdc);
	up_read(&osdc->lock);
}