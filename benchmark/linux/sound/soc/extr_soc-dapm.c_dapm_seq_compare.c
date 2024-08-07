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
struct snd_soc_dapm_widget {size_t id; scalar_t__ subseq; scalar_t__ reg; scalar_t__ dapm; } ;

/* Variables and functions */
 scalar_t__ ARRAY_SIZE (int*) ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 scalar_t__ SND_SOC_DAPM_TYPE_COUNT ; 
 int /*<<< orphan*/  WARN_ONCE (int,char*,size_t) ; 
 int* dapm_down_seq ; 
 int* dapm_up_seq ; 

__attribute__((used)) static int dapm_seq_compare(struct snd_soc_dapm_widget *a,
			    struct snd_soc_dapm_widget *b,
			    bool power_up)
{
	int *sort;

	BUILD_BUG_ON(ARRAY_SIZE(dapm_up_seq) != SND_SOC_DAPM_TYPE_COUNT);
	BUILD_BUG_ON(ARRAY_SIZE(dapm_down_seq) != SND_SOC_DAPM_TYPE_COUNT);

	if (power_up)
		sort = dapm_up_seq;
	else
		sort = dapm_down_seq;

	WARN_ONCE(sort[a->id] == 0, "offset a->id %d not initialized\n", a->id);
	WARN_ONCE(sort[b->id] == 0, "offset b->id %d not initialized\n", b->id);

	if (sort[a->id] != sort[b->id])
		return sort[a->id] - sort[b->id];
	if (a->subseq != b->subseq) {
		if (power_up)
			return a->subseq - b->subseq;
		else
			return b->subseq - a->subseq;
	}
	if (a->reg != b->reg)
		return a->reg - b->reg;
	if (a->dapm != b->dapm)
		return (unsigned long)a->dapm - (unsigned long)b->dapm;

	return 0;
}