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
typedef  int u8 ;
struct snd_usb_midi_out_endpoint {int dummy; } ;
typedef  int /*<<< orphan*/  init_data ;

/* Variables and functions */
 int /*<<< orphan*/  send_bulk_static_data (struct snd_usb_midi_out_endpoint*,int const*,int) ; 

__attribute__((used)) static void snd_usbmidi_emagic_init_out(struct snd_usb_midi_out_endpoint *ep)
{
	static const u8 init_data[] = {
		/* initialization magic: "get version" */
		0xf0,
		0x00, 0x20, 0x31,	/* Emagic */
		0x64,			/* Unitor8 */
		0x0b,			/* version number request */
		0x00,			/* command version */
		0x00,			/* EEPROM, box 0 */
		0xf7
	};
	send_bulk_static_data(ep, init_data, sizeof(init_data));
	/* while we're at it, pour on more magic */
	send_bulk_static_data(ep, init_data, sizeof(init_data));
}