#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u16 ;
struct echoaudio {int output_clock; TYPE_2__* comm_page; TYPE_1__* card; } ;
struct TYPE_4__ {int /*<<< orphan*/  output_clock; } ;
struct TYPE_3__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  DSP_VC_UPDATE_CLOCKS ; 
#define  ECHO_CLOCK_SUPER 129 
#define  ECHO_CLOCK_WORD 128 
 int EINVAL ; 
 int EIO ; 
 int LAYLA20_OUTPUT_CLOCK_SUPER ; 
 int LAYLA20_OUTPUT_CLOCK_WORD ; 
 int /*<<< orphan*/  clear_handshake (struct echoaudio*) ; 
 int /*<<< orphan*/  cpu_to_le16 (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int send_vector (struct echoaudio*,int /*<<< orphan*/ ) ; 
 scalar_t__ wait_handshake (struct echoaudio*) ; 

__attribute__((used)) static int set_output_clock(struct echoaudio *chip, u16 clock)
{
	switch (clock) {
	case ECHO_CLOCK_SUPER:
		clock = LAYLA20_OUTPUT_CLOCK_SUPER;
		break;
	case ECHO_CLOCK_WORD:
		clock = LAYLA20_OUTPUT_CLOCK_WORD;
		break;
	default:
		dev_err(chip->card->dev, "set_output_clock wrong clock\n");
		return -EINVAL;
	}

	if (wait_handshake(chip))
		return -EIO;

	chip->comm_page->output_clock = cpu_to_le16(clock);
	chip->output_clock = clock;
	clear_handshake(chip);
	return send_vector(chip, DSP_VC_UPDATE_CLOCKS);
}