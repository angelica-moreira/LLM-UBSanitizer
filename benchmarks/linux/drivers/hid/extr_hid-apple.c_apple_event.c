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
struct hid_usage {scalar_t__ code; int /*<<< orphan*/  type; } ;
struct hid_field {TYPE_1__* hidinput; } ;
struct hid_device {int claimed; } ;
struct apple_sc {int quirks; } ;
typedef  int /*<<< orphan*/  __s32 ;
struct TYPE_2__ {int /*<<< orphan*/  input; } ;

/* Variables and functions */
 int APPLE_HAS_FN ; 
 int APPLE_INVERT_HWHEEL ; 
 int HID_CLAIMED_INPUT ; 
 scalar_t__ REL_HWHEEL ; 
 struct apple_sc* hid_get_drvdata (struct hid_device*) ; 
 scalar_t__ hidinput_apple_event (struct hid_device*,int /*<<< orphan*/ ,struct hid_usage*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_event (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int apple_event(struct hid_device *hdev, struct hid_field *field,
		struct hid_usage *usage, __s32 value)
{
	struct apple_sc *asc = hid_get_drvdata(hdev);

	if (!(hdev->claimed & HID_CLAIMED_INPUT) || !field->hidinput ||
			!usage->type)
		return 0;

	if ((asc->quirks & APPLE_INVERT_HWHEEL) &&
			usage->code == REL_HWHEEL) {
		input_event(field->hidinput->input, usage->type, usage->code,
				-value);
		return 1;
	}

	if ((asc->quirks & APPLE_HAS_FN) &&
			hidinput_apple_event(hdev, field->hidinput->input,
				usage, value))
		return 1;


	return 0;
}