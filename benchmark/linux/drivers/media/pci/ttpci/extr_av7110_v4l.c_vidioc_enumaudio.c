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
struct v4l2_audio {scalar_t__ index; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  dprintk (int,char*,scalar_t__) ; 
 struct v4l2_audio msp3400_v4l2_audio ; 

__attribute__((used)) static int vidioc_enumaudio(struct file *file, void *fh, struct v4l2_audio *a)
{
	dprintk(2, "VIDIOC_G_AUDIO: %d\n", a->index);
	if (a->index != 0)
		return -EINVAL;
	*a = msp3400_v4l2_audio;
	return 0;
}