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
struct sg_table {int dummy; } ;
struct dma_buf_attachment {int dummy; } ;
typedef  enum dma_data_direction { ____Placeholder_dma_data_direction } dma_data_direction ;

/* Variables and functions */
 int /*<<< orphan*/  ENOSYS ; 
 struct sg_table* ERR_PTR (int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct sg_table *vmw_prime_map_dma_buf(struct dma_buf_attachment *attach,
					      enum dma_data_direction dir)
{
	return ERR_PTR(-ENOSYS);
}