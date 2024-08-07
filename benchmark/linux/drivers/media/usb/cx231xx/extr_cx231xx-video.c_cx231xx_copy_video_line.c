#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  scalar_t__ u32 ;
struct cx231xx_dmaqueue {int current_field; scalar_t__ bytes_left_in_line; scalar_t__ lines_completed; scalar_t__ lines_per_field; int is_partial_line; scalar_t__ pos; } ;
struct cx231xx_buffer {int dummy; } ;
struct TYPE_5__ {struct cx231xx_buffer* buf; } ;
struct TYPE_4__ {struct cx231xx_buffer* buf; } ;
struct TYPE_6__ {TYPE_2__ bulk_ctl; TYPE_1__ isoc_ctl; } ;
struct cx231xx {int width; TYPE_3__ video_mode; scalar_t__ USE_ISO; } ;

/* Variables and functions */
 int /*<<< orphan*/  buffer_filled (struct cx231xx*,struct cx231xx_dmaqueue*,struct cx231xx_buffer*) ; 
 int /*<<< orphan*/  cx231xx_do_copy (struct cx231xx*,struct cx231xx_dmaqueue*,int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ cx231xx_is_buffer_done (struct cx231xx*,struct cx231xx_dmaqueue*) ; 
 int /*<<< orphan*/  cx231xx_reset_video_buffer (struct cx231xx*,struct cx231xx_dmaqueue*) ; 

u32 cx231xx_copy_video_line(struct cx231xx *dev,
			    struct cx231xx_dmaqueue *dma_q, u8 *p_line,
			    u32 length, int field_number)
{
	u32 bytes_to_copy;
	struct cx231xx_buffer *buf;
	u32 _line_size = dev->width * 2;

	if (dma_q->current_field != field_number)
		cx231xx_reset_video_buffer(dev, dma_q);

	/* get the buffer pointer */
	if (dev->USE_ISO)
		buf = dev->video_mode.isoc_ctl.buf;
	else
		buf = dev->video_mode.bulk_ctl.buf;

	/* Remember the field number for next time */
	dma_q->current_field = field_number;

	bytes_to_copy = dma_q->bytes_left_in_line;
	if (bytes_to_copy > length)
		bytes_to_copy = length;

	if (dma_q->lines_completed >= dma_q->lines_per_field) {
		dma_q->bytes_left_in_line -= bytes_to_copy;
		dma_q->is_partial_line = (dma_q->bytes_left_in_line == 0) ?
					  0 : 1;
		return 0;
	}

	dma_q->is_partial_line = 1;

	/* If we don't have a buffer, just return the number of bytes we would
	   have copied if we had a buffer. */
	if (!buf) {
		dma_q->bytes_left_in_line -= bytes_to_copy;
		dma_q->is_partial_line = (dma_q->bytes_left_in_line == 0)
					 ? 0 : 1;
		return bytes_to_copy;
	}

	/* copy the data to video buffer */
	cx231xx_do_copy(dev, dma_q, p_line, bytes_to_copy);

	dma_q->pos += bytes_to_copy;
	dma_q->bytes_left_in_line -= bytes_to_copy;

	if (dma_q->bytes_left_in_line == 0) {
		dma_q->bytes_left_in_line = _line_size;
		dma_q->lines_completed++;
		dma_q->is_partial_line = 0;

		if (cx231xx_is_buffer_done(dev, dma_q) && buf) {
			buffer_filled(dev, dma_q, buf);

			dma_q->pos = 0;
			buf = NULL;
			dma_q->lines_completed = 0;
		}
	}

	return bytes_to_copy;
}