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
struct snd_ice1712 {struct psc724_spec* spec; } ;
struct psc724_spec {int jack_detect; } ;

/* Variables and functions */

__attribute__((used)) static bool psc724_get_jack_detection(struct snd_ice1712 *ice)
{
	struct psc724_spec *spec = ice->spec;

	return spec->jack_detect;
}