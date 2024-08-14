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
struct iio_dma_buffer_block {int /*<<< orphan*/  kref; } ;

/* Variables and functions */
 int /*<<< orphan*/  iio_buffer_block_release_atomic ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void iio_buffer_block_put_atomic(struct iio_dma_buffer_block *block)
{
	kref_put(&block->kref, iio_buffer_block_release_atomic);
}