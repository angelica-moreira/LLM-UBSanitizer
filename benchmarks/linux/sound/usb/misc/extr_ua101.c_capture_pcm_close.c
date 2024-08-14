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
struct ua101 {int /*<<< orphan*/  mutex; int /*<<< orphan*/  states; } ;
struct snd_pcm_substream {struct ua101* private_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  ALSA_CAPTURE_OPEN ; 
 int /*<<< orphan*/  ALSA_PLAYBACK_OPEN ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stop_usb_capture (struct ua101*) ; 
 int /*<<< orphan*/  test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int capture_pcm_close(struct snd_pcm_substream *substream)
{
	struct ua101 *ua = substream->private_data;

	mutex_lock(&ua->mutex);
	clear_bit(ALSA_CAPTURE_OPEN, &ua->states);
	if (!test_bit(ALSA_PLAYBACK_OPEN, &ua->states))
		stop_usb_capture(ua);
	mutex_unlock(&ua->mutex);
	return 0;
}