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
struct zx_tdm_info {int /*<<< orphan*/  dai_wclk; int /*<<< orphan*/  dai_pclk; } ;
struct snd_soc_dai {int /*<<< orphan*/  dev; } ;
struct snd_pcm_substream {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int clk_prepare_enable (int /*<<< orphan*/ ) ; 
 struct zx_tdm_info* dev_get_drvdata (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int zx_tdm_startup(struct snd_pcm_substream *substream,
			  struct snd_soc_dai *dai)
{
	struct zx_tdm_info *zx_tdm = dev_get_drvdata(dai->dev);
	int ret;

	ret = clk_prepare_enable(zx_tdm->dai_wclk);
	if (ret)
		return ret;

	ret = clk_prepare_enable(zx_tdm->dai_pclk);
	if (ret) {
		clk_disable_unprepare(zx_tdm->dai_wclk);
		return ret;
	}

	return 0;
}