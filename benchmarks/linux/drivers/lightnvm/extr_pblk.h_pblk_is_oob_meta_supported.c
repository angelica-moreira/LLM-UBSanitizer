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
struct pblk_sec_meta {int dummy; } ;
struct pblk {int oob_meta_size; } ;

/* Variables and functions */

__attribute__((used)) static inline int pblk_is_oob_meta_supported(struct pblk *pblk)
{
	return pblk->oob_meta_size >= sizeof(struct pblk_sec_meta);
}