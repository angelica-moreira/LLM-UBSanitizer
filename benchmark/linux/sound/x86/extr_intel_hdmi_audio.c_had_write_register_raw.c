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
typedef  scalar_t__ u32 ;
struct snd_intelhad_card {scalar_t__ mmio_start; } ;

/* Variables and functions */
 scalar_t__ had_config_offset (int) ; 
 int /*<<< orphan*/  iowrite32 (scalar_t__,scalar_t__) ; 

__attribute__((used)) static void had_write_register_raw(struct snd_intelhad_card *card_ctx,
				   int pipe, u32 reg, u32 val)
{
	iowrite32(val, card_ctx->mmio_start + had_config_offset(pipe) + reg);
}