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
struct TYPE_2__ {int /*<<< orphan*/  status; } ;
struct msgbuf_gen_status {TYPE_1__ compl_hdr; } ;
struct brcmf_pub {int dummy; } ;
struct brcmf_msgbuf {struct brcmf_pub* drvr; } ;

/* Variables and functions */
 int /*<<< orphan*/  bphy_err (struct brcmf_pub*,char*,int) ; 
 int le16_to_cpu (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void brcmf_msgbuf_process_gen_status(struct brcmf_msgbuf *msgbuf,
					    void *buf)
{
	struct msgbuf_gen_status *gen_status = buf;
	struct brcmf_pub *drvr = msgbuf->drvr;
	int err;

	err = le16_to_cpu(gen_status->compl_hdr.status);
	if (err)
		bphy_err(drvr, "Firmware reported general error: %d\n", err);
}