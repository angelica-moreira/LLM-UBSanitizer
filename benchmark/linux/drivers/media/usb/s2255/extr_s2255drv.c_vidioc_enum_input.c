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
typedef  int u32 ;
struct v4l2_input {scalar_t__ index; int /*<<< orphan*/  name; scalar_t__ status; int /*<<< orphan*/  std; int /*<<< orphan*/  type; } ;
struct s2255_vc {int idx; struct s2255_dev* dev; } ;
struct s2255_dev {scalar_t__ dsp_fw_ver; int pid; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ S2255_MIN_DSP_STATUS ; 
 int /*<<< orphan*/  S2255_NORMS ; 
 int /*<<< orphan*/  V4L2_INPUT_TYPE_CAMERA ; 
 scalar_t__ V4L2_IN_ST_NO_SIGNAL ; 
 int /*<<< orphan*/  dprintk (struct s2255_dev*,int,char*,int,int) ; 
 int s2255_cmd_status (struct s2255_vc*,int*) ; 
 int /*<<< orphan*/  strscpy (int /*<<< orphan*/ ,char*,int) ; 
 struct s2255_vc* video_drvdata (struct file*) ; 

__attribute__((used)) static int vidioc_enum_input(struct file *file, void *priv,
			     struct v4l2_input *inp)
{
	struct s2255_vc *vc = video_drvdata(file);
	struct s2255_dev *dev = vc->dev;
	u32 status = 0;

	if (inp->index != 0)
		return -EINVAL;
	inp->type = V4L2_INPUT_TYPE_CAMERA;
	inp->std = S2255_NORMS;
	inp->status = 0;
	if (dev->dsp_fw_ver >= S2255_MIN_DSP_STATUS) {
		int rc;
		rc = s2255_cmd_status(vc, &status);
		dprintk(dev, 4, "s2255_cmd_status rc: %d status %x\n",
			rc, status);
		if (rc == 0)
			inp->status =  (status & 0x01) ? 0
				: V4L2_IN_ST_NO_SIGNAL;
	}
	switch (dev->pid) {
	case 0x2255:
	default:
		strscpy(inp->name, "Composite", sizeof(inp->name));
		break;
	case 0x2257:
		strscpy(inp->name, (vc->idx < 2) ? "Composite" : "S-Video",
			sizeof(inp->name));
		break;
	}
	return 0;
}