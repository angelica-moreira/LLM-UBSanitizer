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
struct dma_buf {int /*<<< orphan*/  priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  vb2_dc_put (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void vb2_dc_dmabuf_ops_release(struct dma_buf *dbuf)
{
	/* drop reference obtained in vb2_dc_get_dmabuf */
	vb2_dc_put(dbuf->priv);
}