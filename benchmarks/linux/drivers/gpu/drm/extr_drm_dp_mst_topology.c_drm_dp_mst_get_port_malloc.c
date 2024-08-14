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
struct drm_dp_mst_port {int /*<<< orphan*/  malloc_kref; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_DEBUG (char*,struct drm_dp_mst_port*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_read (int /*<<< orphan*/ *) ; 

void
drm_dp_mst_get_port_malloc(struct drm_dp_mst_port *port)
{
	kref_get(&port->malloc_kref);
	DRM_DEBUG("port %p (%d)\n", port, kref_read(&port->malloc_kref));
}