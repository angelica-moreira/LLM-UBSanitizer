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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */
 int /*<<< orphan*/  put_unaligned_le32 (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void btrfs_crc32c_final(u32 crc, u8 *result)
{
	put_unaligned_le32(~crc, result);
}