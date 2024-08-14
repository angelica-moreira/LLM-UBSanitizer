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
struct v4l2_tuner {scalar_t__ index; } ;
struct file {int dummy; } ;
struct bttv_fh {struct bttv* btv; } ;
struct bttv {int /*<<< orphan*/  (* audio_mode_gpio ) (struct bttv*,struct v4l2_tuner*,int) ;} ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  bttv_call_all (struct bttv*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct v4l2_tuner const*) ; 
 int /*<<< orphan*/  s_tuner ; 
 int /*<<< orphan*/  stub1 (struct bttv*,struct v4l2_tuner*,int) ; 
 int /*<<< orphan*/  tuner ; 

__attribute__((used)) static int bttv_s_tuner(struct file *file, void *priv,
					const struct v4l2_tuner *t)
{
	struct bttv_fh *fh  = priv;
	struct bttv *btv = fh->btv;

	if (t->index)
		return -EINVAL;

	bttv_call_all(btv, tuner, s_tuner, t);

	if (btv->audio_mode_gpio) {
		struct v4l2_tuner copy = *t;

		btv->audio_mode_gpio(btv, &copy, 1);
	}
	return 0;
}