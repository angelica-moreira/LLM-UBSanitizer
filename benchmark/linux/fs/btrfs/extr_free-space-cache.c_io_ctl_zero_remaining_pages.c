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
struct btrfs_io_ctl {scalar_t__ cur; scalar_t__ orig; scalar_t__ index; scalar_t__ num_pages; } ;

/* Variables and functions */
 int /*<<< orphan*/  io_ctl_map_page (struct btrfs_io_ctl*,int) ; 
 int /*<<< orphan*/  io_ctl_set_crc (struct btrfs_io_ctl*,scalar_t__) ; 
 int /*<<< orphan*/  io_ctl_unmap_page (struct btrfs_io_ctl*) ; 

__attribute__((used)) static void io_ctl_zero_remaining_pages(struct btrfs_io_ctl *io_ctl)
{
	/*
	 * If we're not on the boundary we know we've modified the page and we
	 * need to crc the page.
	 */
	if (io_ctl->cur != io_ctl->orig)
		io_ctl_set_crc(io_ctl, io_ctl->index - 1);
	else
		io_ctl_unmap_page(io_ctl);

	while (io_ctl->index < io_ctl->num_pages) {
		io_ctl_map_page(io_ctl, 1);
		io_ctl_set_crc(io_ctl, io_ctl->index - 1);
	}
}