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
struct madera {int type; int num_micbias; int* num_childbias; } ;

/* Variables and functions */
#define  CS42L92 136 
#define  CS47L15 135 
#define  CS47L35 134 
#define  CS47L85 133 
#define  CS47L90 132 
#define  CS47L91 131 
#define  CS47L92 130 
#define  CS47L93 129 
#define  WM1840 128 

__attribute__((used)) static void madera_set_micbias_info(struct madera *madera)
{
	/*
	 * num_childbias is an array because future codecs can have different
	 * childbiases for each micbias. Unspecified values default to 0.
	 */
	switch (madera->type) {
	case CS47L15:
		madera->num_micbias = 1;
		madera->num_childbias[0] = 3;
		return;
	case CS47L35:
		madera->num_micbias = 2;
		madera->num_childbias[0] = 2;
		madera->num_childbias[1] = 2;
		return;
	case CS47L85:
	case WM1840:
		madera->num_micbias = 4;
		/* no child biases */
		return;
	case CS47L90:
	case CS47L91:
		madera->num_micbias = 2;
		madera->num_childbias[0] = 4;
		madera->num_childbias[1] = 4;
		return;
	case CS42L92:
	case CS47L92:
	case CS47L93:
		madera->num_micbias = 2;
		madera->num_childbias[0] = 4;
		madera->num_childbias[1] = 2;
		return;
	default:
		return;
	}
}