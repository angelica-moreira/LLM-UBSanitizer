#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct v4l2_input {int /*<<< orphan*/  name; } ;
struct v4l2_audio {int /*<<< orphan*/  name; } ;
struct tveeprom {int dummy; } ;
struct file {int dummy; } ;
struct TYPE_9__ {int /*<<< orphan*/  depth; } ;
struct TYPE_8__ {int /*<<< orphan*/ * v4l2_dev; } ;
struct cx18_stream {int buffers; int bufs_per_mdl; int buf_size; TYPE_4__ q_full; int /*<<< orphan*/  s_flags; int /*<<< orphan*/  name; TYPE_3__ video_dev; } ;
struct TYPE_7__ {int /*<<< orphan*/  name; } ;
struct TYPE_6__ {int /*<<< orphan*/  hdl; } ;
struct cx18 {long long card_name; int hw_flags; long long gpio_dir; long long gpio_val; scalar_t__ vbi_data_inserted; scalar_t__ mpg_data_received; struct cx18_stream* streams; int /*<<< orphan*/  i_flags; TYPE_2__ v4l2_dev; TYPE_1__ cxhdl; int /*<<< orphan*/  gpio_lock; int /*<<< orphan*/  audio_input; int /*<<< orphan*/  active_input; } ;
struct TYPE_10__ {struct cx18* cx; } ;

/* Variables and functions */
 int /*<<< orphan*/  CX18_F_I_RADIO_USER ; 
 int CX18_HW_TVEEPROM ; 
 int /*<<< orphan*/  CX18_INFO (char*,...) ; 
 int CX18_MAX_STREAMS ; 
 long long CX18_VERSION ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  core ; 
 int /*<<< orphan*/  cx18_call_all (struct cx18*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cx18_get_audio_input (struct cx18*,int /*<<< orphan*/ ,struct v4l2_audio*) ; 
 int /*<<< orphan*/  cx18_get_input (struct cx18*,int /*<<< orphan*/ ,struct v4l2_input*) ; 
 int /*<<< orphan*/  cx18_read_eeprom (struct cx18*,struct tveeprom*) ; 
 TYPE_5__* fh2id (void*) ; 
 int /*<<< orphan*/  log_status ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  v4l2_ctrl_handler_log_status (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int cx18_log_status(struct file *file, void *fh)
{
	struct cx18 *cx = fh2id(fh)->cx;
	struct v4l2_input vidin;
	struct v4l2_audio audin;
	int i;

	CX18_INFO("Version: %s  Card: %s\n", CX18_VERSION, cx->card_name);
	if (cx->hw_flags & CX18_HW_TVEEPROM) {
		struct tveeprom tv;

		cx18_read_eeprom(cx, &tv);
	}
	cx18_call_all(cx, core, log_status);
	cx18_get_input(cx, cx->active_input, &vidin);
	cx18_get_audio_input(cx, cx->audio_input, &audin);
	CX18_INFO("Video Input: %s\n", vidin.name);
	CX18_INFO("Audio Input: %s\n", audin.name);
	mutex_lock(&cx->gpio_lock);
	CX18_INFO("GPIO:  direction 0x%08x, value 0x%08x\n",
		cx->gpio_dir, cx->gpio_val);
	mutex_unlock(&cx->gpio_lock);
	CX18_INFO("Tuner: %s\n",
		test_bit(CX18_F_I_RADIO_USER, &cx->i_flags) ?  "Radio" : "TV");
	v4l2_ctrl_handler_log_status(&cx->cxhdl.hdl, cx->v4l2_dev.name);
	CX18_INFO("Status flags: 0x%08lx\n", cx->i_flags);
	for (i = 0; i < CX18_MAX_STREAMS; i++) {
		struct cx18_stream *s = &cx->streams[i];

		if (s->video_dev.v4l2_dev == NULL || s->buffers == 0)
			continue;
		CX18_INFO("Stream %s: status 0x%04lx, %d%% of %d KiB (%d buffers) in use\n",
			  s->name, s->s_flags,
			  atomic_read(&s->q_full.depth) * s->bufs_per_mdl * 100
			   / s->buffers,
			  (s->buffers * s->buf_size) / 1024, s->buffers);
	}
	CX18_INFO("Read MPEG/VBI: %lld/%lld bytes\n",
			(long long)cx->mpg_data_received,
			(long long)cx->vbi_data_inserted);
	return 0;
}