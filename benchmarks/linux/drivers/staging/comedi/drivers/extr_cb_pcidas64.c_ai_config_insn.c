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
struct comedi_subdevice {int dummy; } ;
struct comedi_insn {int dummy; } ;
struct comedi_device {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
#define  INSN_CONFIG_ALT_SOURCE 130 
#define  INSN_CONFIG_BLOCK_SIZE 129 
#define  INSN_CONFIG_TIMER_1 128 
 int ai_config_block_size (struct comedi_device*,unsigned int*) ; 
 int ai_config_calibration_source (struct comedi_device*,unsigned int*) ; 
 int ai_config_master_clock (struct comedi_device*,unsigned int*) ; 

__attribute__((used)) static int ai_config_insn(struct comedi_device *dev, struct comedi_subdevice *s,
			  struct comedi_insn *insn, unsigned int *data)
{
	int id = data[0];

	switch (id) {
	case INSN_CONFIG_ALT_SOURCE:
		return ai_config_calibration_source(dev, data);
	case INSN_CONFIG_BLOCK_SIZE:
		return ai_config_block_size(dev, data);
	case INSN_CONFIG_TIMER_1:
		return ai_config_master_clock(dev, data);
	default:
		return -EINVAL;
	}
	return -EINVAL;
}