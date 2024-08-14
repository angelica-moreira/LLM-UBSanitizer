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

/* Variables and functions */
 int crypto_tfm_ctx_alignment () ; 

__attribute__((used)) static inline unsigned int ahash_align_buffer_size(unsigned len,
						   unsigned long mask)
{
	return len + (mask & ~(crypto_tfm_ctx_alignment() - 1));
}