#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
struct hl_ctx {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  num_of_ptes; } ;

/* Variables and functions */
 TYPE_1__* get_pgt_info (struct hl_ctx*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void get_pte(struct hl_ctx *ctx, u64 hop_addr)
{
	get_pgt_info(ctx, hop_addr)->num_of_ptes++;
}