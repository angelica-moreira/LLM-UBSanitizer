#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u64 ;
struct TYPE_5__ {TYPE_1__* device; } ;
struct nvkm_mxm {TYPE_2__ subdev; } ;
struct nvkm_bios {int dummy; } ;
struct TYPE_6__ {int outp_type; int conn_type; int /*<<< orphan*/  dig_conn; } ;
struct context {int* outp; TYPE_3__ desc; } ;
struct TYPE_4__ {struct nvkm_bios* bios; } ;

/* Variables and functions */
 int /*<<< orphan*/  mxm_match_tmds_partner ; 
 int mxm_sor_map (struct nvkm_bios*,int /*<<< orphan*/ ) ; 
 scalar_t__ mxms_foreach (struct nvkm_mxm*,int,int /*<<< orphan*/ ,struct context*) ; 
 int /*<<< orphan*/  mxms_output_device (struct nvkm_mxm*,int*,TYPE_3__*) ; 

__attribute__((used)) static bool
mxm_match_dcb(struct nvkm_mxm *mxm, u8 *data, void *info)
{
	struct nvkm_bios *bios = mxm->subdev.device->bios;
	struct context *ctx = info;
	u64 desc = *(u64 *)data;

	mxms_output_device(mxm, data, &ctx->desc);

	/* match dcb encoder type to mxm-ods device type */
	if ((ctx->outp[0] & 0x0000000f) != ctx->desc.outp_type)
		return true;

	/* digital output, have some extra stuff to match here, there's a
	 * table in the vbios that provides a mapping from the mxm digital
	 * connection enum values to SOR/link
	 */
	if ((desc & 0x00000000000000f0) >= 0x20) {
		/* check against sor index */
		u8 link = mxm_sor_map(bios, ctx->desc.dig_conn);
		if ((ctx->outp[0] & 0x0f000000) != (link & 0x0f) << 24)
			return true;

		/* check dcb entry has a compatible link field */
		link = (link & 0x30) >> 4;
		if ((link & ((ctx->outp[1] & 0x00000030) >> 4)) != link)
			return true;
	}

	/* mark this descriptor accounted for by setting invalid device type,
	 * except of course some manufactures don't follow specs properly and
	 * we need to avoid killing off the TMDS function on DP connectors
	 * if MXM-SIS is missing an entry for it.
	 */
	data[0] &= ~0xf0;
	if (ctx->desc.outp_type == 6 && ctx->desc.conn_type == 6 &&
	    mxms_foreach(mxm, 0x01, mxm_match_tmds_partner, ctx)) {
		data[0] |= 0x20; /* modify descriptor to match TMDS now */
	} else {
		data[0] |= 0xf0;
	}

	return false;
}