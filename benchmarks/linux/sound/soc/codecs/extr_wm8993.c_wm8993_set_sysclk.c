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
struct wm8993_priv {unsigned int mclk_rate; int sysclk_source; } ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
#define  WM8993_SYSCLK_FLL 129 
#define  WM8993_SYSCLK_MCLK 128 
 struct wm8993_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 

__attribute__((used)) static int wm8993_set_sysclk(struct snd_soc_dai *codec_dai,
			     int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_component *component = codec_dai->component;
	struct wm8993_priv *wm8993 = snd_soc_component_get_drvdata(component);

	switch (clk_id) {
	case WM8993_SYSCLK_MCLK:
		wm8993->mclk_rate = freq;
		/* fall through */
	case WM8993_SYSCLK_FLL:
		wm8993->sysclk_source = clk_id;
		break;

	default:
		return -EINVAL;
	}

	return 0;
}