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
struct stk_camera {scalar_t__ sequence; int /*<<< orphan*/ * sio_bufs; } ;
struct file {int dummy; } ;
typedef  enum v4l2_buf_type { ____Placeholder_v4l2_buf_type } v4l2_buf_type ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ is_streaming (struct stk_camera*) ; 
 int stk_start_stream (struct stk_camera*) ; 
 struct stk_camera* video_drvdata (struct file*) ; 

__attribute__((used)) static int stk_vidioc_streamon(struct file *filp,
		void *priv, enum v4l2_buf_type type)
{
	struct stk_camera *dev = video_drvdata(filp);
	if (is_streaming(dev))
		return 0;
	if (dev->sio_bufs == NULL)
		return -EINVAL;
	dev->sequence = 0;
	return stk_start_stream(dev);
}