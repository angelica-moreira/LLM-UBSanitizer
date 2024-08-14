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
struct hdsp {int /*<<< orphan*/  control_register; } ;

/* Variables and functions */
 int /*<<< orphan*/  HDSP_RPM_Inp12 ; 
 int /*<<< orphan*/  HDSP_RPM_Inp12_Line_0dB ; 
 int /*<<< orphan*/  HDSP_RPM_Inp12_Line_n6dB ; 
 int /*<<< orphan*/  HDSP_RPM_Inp12_Phon_6dB ; 
 int /*<<< orphan*/  HDSP_RPM_Inp12_Phon_n6dB ; 
 int /*<<< orphan*/  HDSP_controlRegister ; 
 int /*<<< orphan*/  hdsp_write (struct hdsp*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int hdsp_set_rpm_input12(struct hdsp *hdsp, int mode)
{
	hdsp->control_register &= ~HDSP_RPM_Inp12;
	switch (mode) {
	case 0:
		hdsp->control_register |= HDSP_RPM_Inp12_Phon_6dB;
		break;
	case 1:
		break;
	case 2:
		hdsp->control_register |= HDSP_RPM_Inp12_Phon_n6dB;
		break;
	case 3:
		hdsp->control_register |= HDSP_RPM_Inp12_Line_0dB;
		break;
	case 4:
		hdsp->control_register |= HDSP_RPM_Inp12_Line_n6dB;
		break;
	default:
		return -1;
	}

	hdsp_write(hdsp, HDSP_controlRegister, hdsp->control_register);
	return 0;
}