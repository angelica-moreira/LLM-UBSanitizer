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
struct brcmf_pub {int /*<<< orphan*/  proto_block; int /*<<< orphan*/  proto_buf; } ;
struct brcmf_if {int /*<<< orphan*/  bsscfgidx; int /*<<< orphan*/  ifidx; struct brcmf_pub* drvr; } ;
typedef  int /*<<< orphan*/  s32 ;

/* Variables and functions */
 int /*<<< orphan*/  BRCMF_C_GET_VAR ; 
 int /*<<< orphan*/  BRCMF_FIL_ON () ; 
 int /*<<< orphan*/  EPERM ; 
 int /*<<< orphan*/  FIL ; 
 int /*<<< orphan*/  MAX_HEX_DUMP_LEN ; 
 int /*<<< orphan*/  bphy_err (struct brcmf_pub*,char*) ; 
 scalar_t__ brcmf_create_bsscfg (int /*<<< orphan*/ ,char*,void*,scalar_t__,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  brcmf_dbg (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,scalar_t__) ; 
 int /*<<< orphan*/  brcmf_dbg_hex_dump (int /*<<< orphan*/ ,void*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  brcmf_fil_cmd_data (struct brcmf_if*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int) ; 
 int /*<<< orphan*/  memcpy (void*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  min_t (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uint ; 

s32
brcmf_fil_bsscfg_data_get(struct brcmf_if *ifp, char *name,
			  void *data, u32 len)
{
	struct brcmf_pub *drvr = ifp->drvr;
	s32 err;
	u32 buflen;

	mutex_lock(&drvr->proto_block);

	buflen = brcmf_create_bsscfg(ifp->bsscfgidx, name, data, len,
				     drvr->proto_buf, sizeof(drvr->proto_buf));
	if (buflen) {
		err = brcmf_fil_cmd_data(ifp, BRCMF_C_GET_VAR, drvr->proto_buf,
					 buflen, false);
		if (err == 0)
			memcpy(data, drvr->proto_buf, len);
	} else {
		err = -EPERM;
		bphy_err(drvr, "Creating bsscfg failed\n");
	}
	brcmf_dbg(FIL, "ifidx=%d, bsscfgidx=%d, name=%s, len=%d\n", ifp->ifidx,
		  ifp->bsscfgidx, name, len);
	brcmf_dbg_hex_dump(BRCMF_FIL_ON(), data,
			   min_t(uint, len, MAX_HEX_DUMP_LEN), "data\n");

	mutex_unlock(&drvr->proto_block);
	return err;

}