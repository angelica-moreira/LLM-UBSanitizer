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
struct usb_audio_term {int dummy; } ;
struct mixer_build {struct usb_audio_term* termbitmap; } ;

/* Variables and functions */
 int __check_input_term (struct mixer_build*,int,struct usb_audio_term*) ; 
 int /*<<< orphan*/  memset (struct usb_audio_term*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int check_input_term(struct mixer_build *state, int id,
			    struct usb_audio_term *term)
{
	memset(term, 0, sizeof(*term));
	memset(state->termbitmap, 0, sizeof(state->termbitmap));
	return __check_input_term(state, id, term);
}