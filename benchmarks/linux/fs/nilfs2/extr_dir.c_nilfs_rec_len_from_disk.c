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
typedef  int /*<<< orphan*/  __le16 ;

/* Variables and functions */
 unsigned int NILFS_MAX_REC_LEN ; 
 unsigned int le16_to_cpu (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline unsigned int nilfs_rec_len_from_disk(__le16 dlen)
{
	unsigned int len = le16_to_cpu(dlen);

#if (PAGE_SIZE >= 65536)
	if (len == NILFS_MAX_REC_LEN)
		return 1 << 16;
#endif
	return len;
}