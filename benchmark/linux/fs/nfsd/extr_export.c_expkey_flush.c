#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {TYPE_1__* nsproxy; } ;
struct TYPE_3__ {int /*<<< orphan*/  net_ns; } ;

/* Variables and functions */
 TYPE_2__* current ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nfsd_file_cache_purge (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nfsd_mutex ; 

__attribute__((used)) static void expkey_flush(void)
{
	/*
	 * Take the nfsd_mutex here to ensure that the file cache is not
	 * destroyed while we're in the middle of flushing.
	 */
	mutex_lock(&nfsd_mutex);
	nfsd_file_cache_purge(current->nsproxy->net_ns);
	mutex_unlock(&nfsd_mutex);
}