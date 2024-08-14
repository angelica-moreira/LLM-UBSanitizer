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
struct cc_hw_desc {int /*<<< orphan*/ * word; } ;

/* Variables and functions */
 int /*<<< orphan*/  FIELD_PREP (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  WORD4_BYTES_SWAP ; 

__attribute__((used)) static inline void set_bytes_swap(struct cc_hw_desc *pdesc, bool config)
{
	pdesc->word[4] |= FIELD_PREP(WORD4_BYTES_SWAP, config);
}