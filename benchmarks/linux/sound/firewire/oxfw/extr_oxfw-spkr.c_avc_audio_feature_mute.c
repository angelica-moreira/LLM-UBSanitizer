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
typedef  int u8 ;
struct fw_unit {int /*<<< orphan*/  device; } ;
typedef  enum control_action { ____Placeholder_control_action } control_action ;

/* Variables and functions */
 int CTL_READ ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int fcp_avc_transaction (struct fw_unit*,int*,int,int*,int,int) ; 
 int /*<<< orphan*/  kfree (int*) ; 
 int* kmalloc (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int avc_audio_feature_mute(struct fw_unit *unit, u8 fb_id, bool *value,
				  enum control_action action)
{
	u8 *buf;
	u8 response_ok;
	int err;

	buf = kmalloc(11, GFP_KERNEL);
	if (!buf)
		return -ENOMEM;

	if (action == CTL_READ) {
		buf[0] = 0x01;		/* AV/C, STATUS */
		response_ok = 0x0c;	/*       STABLE */
	} else {
		buf[0] = 0x00;		/* AV/C, CONTROL */
		response_ok = 0x09;	/*       ACCEPTED */
	}
	buf[1] = 0x08;			/* audio unit 0 */
	buf[2] = 0xb8;			/* FUNCTION BLOCK */
	buf[3] = 0x81;			/* function block type: feature */
	buf[4] = fb_id;			/* function block ID */
	buf[5] = 0x10;			/* control attribute: current */
	buf[6] = 0x02;			/* selector length */
	buf[7] = 0x00;			/* audio channel number */
	buf[8] = 0x01;			/* control selector: mute */
	buf[9] = 0x01;			/* control data length */
	if (action == CTL_READ)
		buf[10] = 0xff;
	else
		buf[10] = *value ? 0x70 : 0x60;

	err = fcp_avc_transaction(unit, buf, 11, buf, 11, 0x3fe);
	if (err < 0)
		goto error;
	if (err < 11) {
		dev_err(&unit->device, "short FCP response\n");
		err = -EIO;
		goto error;
	}
	if (buf[0] != response_ok) {
		dev_err(&unit->device, "mute command failed\n");
		err = -EIO;
		goto error;
	}
	if (action == CTL_READ)
		*value = buf[10] == 0x70;

	err = 0;

error:
	kfree(buf);

	return err;
}