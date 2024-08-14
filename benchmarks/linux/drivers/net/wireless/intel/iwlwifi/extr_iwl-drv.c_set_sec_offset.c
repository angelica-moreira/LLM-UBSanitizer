#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct iwl_firmware_pieces {TYPE_2__* img; } ;
typedef  enum iwl_ucode_type { ____Placeholder_iwl_ucode_type } iwl_ucode_type ;
struct TYPE_4__ {TYPE_1__* sec; } ;
struct TYPE_3__ {int /*<<< orphan*/  offset; } ;

/* Variables and functions */
 int /*<<< orphan*/  alloc_sec_data (struct iwl_firmware_pieces*,int,int) ; 

__attribute__((used)) static void set_sec_offset(struct iwl_firmware_pieces *pieces,
			   enum iwl_ucode_type type,
			   int sec,
			   u32 offset)
{
	alloc_sec_data(pieces, type, sec);

	pieces->img[type].sec[sec].offset = offset;
}