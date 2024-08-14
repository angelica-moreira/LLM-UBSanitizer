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
typedef  size_t u8 ;
struct usb_ftdi {scalar_t__ disconnected; scalar_t__ initialized; int command_next; int command_head; int /*<<< orphan*/  u132_lock; struct u132_command* command; struct u132_target* target; } ;
struct urb {int /*<<< orphan*/  setup_packet; int /*<<< orphan*/  pipe; int /*<<< orphan*/  dev; } ;
struct u132_target {void (* callback ) (void*,struct urb*,size_t*,int,int,int,int,int,int,int,int,int) ;int active; struct urb* urb; void* endp; } ;
struct u132_command {int header; int length; size_t address; int follows; int /*<<< orphan*/  buffer; scalar_t__ value; int /*<<< orphan*/  width; } ;

/* Variables and functions */
 size_t COMMAND_MASK ; 
 int COMMAND_SIZE ; 
 int ENODEV ; 
 int /*<<< orphan*/  ftdi_elan_kick_command_queue (struct usb_ftdi*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usb_maxpacket (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_pipeout (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ftdi_elan_edset_setup(struct usb_ftdi *ftdi, u8 ed_number,
				 void *endp, struct urb *urb, u8 address, u8 ep_number, u8 toggle_bits,
				 void (*callback) (void *endp, struct urb *urb, u8 *buf, int len,
						   int toggle_bits, int error_count, int condition_code, int repeat_number,
						   int halted, int skipped, int actual, int non_null))
{
	u8 ed = ed_number - 1;
wait:if (ftdi->disconnected > 0) {
		return -ENODEV;
	} else if (ftdi->initialized == 0) {
		return -ENODEV;
	} else {
		int command_size;
		mutex_lock(&ftdi->u132_lock);
		command_size = ftdi->command_next - ftdi->command_head;
		if (command_size < COMMAND_SIZE) {
			struct u132_target *target = &ftdi->target[ed];
			struct u132_command *command = &ftdi->command[
				COMMAND_MASK & ftdi->command_next];
			command->header = 0x80 | (ed << 5);
			command->length = 0x8007;
			command->address = (toggle_bits << 6) | (ep_number << 2)
				| (address << 0);
			command->width = usb_maxpacket(urb->dev, urb->pipe,
						       usb_pipeout(urb->pipe));
			command->follows = 8;
			command->value = 0;
			command->buffer = urb->setup_packet;
			target->callback = callback;
			target->endp = endp;
			target->urb = urb;
			target->active = 1;
			ftdi->command_next += 1;
			ftdi_elan_kick_command_queue(ftdi);
			mutex_unlock(&ftdi->u132_lock);
			return 0;
		} else {
			mutex_unlock(&ftdi->u132_lock);
			msleep(100);
			goto wait;
		}
	}
}