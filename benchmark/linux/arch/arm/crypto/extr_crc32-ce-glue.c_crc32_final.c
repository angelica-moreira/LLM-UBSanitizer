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
struct shash_desc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  put_unaligned_le32 (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * shash_desc_ctx (struct shash_desc*) ; 

__attribute__((used)) static int crc32_final(struct shash_desc *desc, u8 *out)
{
	u32 *crc = shash_desc_ctx(desc);

	put_unaligned_le32(*crc, out);
	return 0;
}