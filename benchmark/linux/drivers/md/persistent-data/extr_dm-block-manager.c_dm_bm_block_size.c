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
struct dm_block_manager {int /*<<< orphan*/  bufio; } ;

/* Variables and functions */
 int dm_bufio_get_block_size (int /*<<< orphan*/ ) ; 

unsigned dm_bm_block_size(struct dm_block_manager *bm)
{
	return dm_bufio_get_block_size(bm->bufio);
}