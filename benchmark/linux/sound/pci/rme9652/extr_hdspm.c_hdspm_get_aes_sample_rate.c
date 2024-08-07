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
struct hdspm {int io_type; } ;

/* Variables and functions */
#define  AES32 128 
 int /*<<< orphan*/  HDSPM_timecodeRegister ; 
 int hdspm_read (struct hdspm*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int hdspm_get_aes_sample_rate(struct hdspm *hdspm, int index)
{
	int timecode;

	switch (hdspm->io_type) {
	case AES32:
		timecode = hdspm_read(hdspm, HDSPM_timecodeRegister);
		return (timecode >> (4*index)) & 0xF;
		break;
	default:
		break;
	}
	return 0;
}