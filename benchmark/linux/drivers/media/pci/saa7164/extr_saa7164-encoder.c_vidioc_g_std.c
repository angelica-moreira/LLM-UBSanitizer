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
typedef  int /*<<< orphan*/  v4l2_std_id ;
struct saa7164_encoder_fh {int /*<<< orphan*/  port; } ;
struct file {struct saa7164_encoder_fh* private_data; } ;

/* Variables and functions */
 int saa7164_g_std (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int vidioc_g_std(struct file *file, void *priv, v4l2_std_id *id)
{
	struct saa7164_encoder_fh *fh = file->private_data;

	return saa7164_g_std(fh->port, id);
}