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
struct file {int dummy; } ;
struct capture_priv {int /*<<< orphan*/  src_sd; } ;

/* Variables and functions */
 int /*<<< orphan*/  querystd ; 
 int v4l2_subdev_call (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  video ; 
 struct capture_priv* video_drvdata (struct file*) ; 

__attribute__((used)) static int capture_querystd(struct file *file, void *fh, v4l2_std_id *std)
{
	struct capture_priv *priv = video_drvdata(file);

	return v4l2_subdev_call(priv->src_sd, video, querystd, std);
}