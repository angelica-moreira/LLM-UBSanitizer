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
typedef  scalar_t__ u8 ;
typedef  scalar_t__ u16 ;
struct nvkm_bios {int dummy; } ;
struct nvbios_outp {scalar_t__ type; scalar_t__ mask; } ;

/* Variables and functions */
 scalar_t__ nvbios_outp_parse (struct nvkm_bios*,int /*<<< orphan*/ ,scalar_t__*,scalar_t__*,scalar_t__*,scalar_t__*,struct nvbios_outp*) ; 

u16
nvbios_outp_match(struct nvkm_bios *bios, u16 type, u16 mask,
		  u8 *ver, u8 *hdr, u8 *cnt, u8 *len, struct nvbios_outp *info)
{
	u16 data, idx = 0;
	while ((data = nvbios_outp_parse(bios, idx++, ver, hdr, cnt, len, info)) || *ver) {
		if (data && info->type == type) {
			if ((info->mask & mask) == mask)
				break;
		}
	}
	return data;
}