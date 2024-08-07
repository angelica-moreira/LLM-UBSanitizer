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
struct dm_verity_io {int /*<<< orphan*/  v; } ;
struct dm_verity_fec_io {int dummy; } ;

/* Variables and functions */
 scalar_t__ verity_io_digest_end (int /*<<< orphan*/ ,struct dm_verity_io*) ; 

__attribute__((used)) static inline struct dm_verity_fec_io *fec_io(struct dm_verity_io *io)
{
	return (struct dm_verity_fec_io *) verity_io_digest_end(io->v, io);
}