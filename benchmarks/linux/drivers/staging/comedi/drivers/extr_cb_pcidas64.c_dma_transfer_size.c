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
typedef  int /*<<< orphan*/  u16 ;
struct pcidas64_private {unsigned int ai_fifo_segment_length; } ;
struct pcidas64_board {TYPE_1__* ai_fifo; } ;
struct comedi_device {struct pcidas64_private* private; struct pcidas64_board* board_ptr; } ;
struct TYPE_2__ {unsigned int sample_packing_ratio; } ;

/* Variables and functions */
 int DMA_BUFFER_SIZE ; 

__attribute__((used)) static inline unsigned int dma_transfer_size(struct comedi_device *dev)
{
	const struct pcidas64_board *board = dev->board_ptr;
	struct pcidas64_private *devpriv = dev->private;
	unsigned int num_samples;

	num_samples = devpriv->ai_fifo_segment_length *
		      board->ai_fifo->sample_packing_ratio;
	if (num_samples > DMA_BUFFER_SIZE / sizeof(u16))
		num_samples = DMA_BUFFER_SIZE / sizeof(u16);

	return num_samples;
}