#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_6__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
struct TYPE_17__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_3__ dev; } ;
struct madera {int /*<<< orphan*/  regmap; int /*<<< orphan*/  regmap_32bit; int /*<<< orphan*/  dev; int /*<<< orphan*/  irq_dev; } ;
struct TYPE_18__ {int num_inputs; TYPE_1__* adsp; TYPE_3__* dev; struct madera* madera; } ;
struct cs47l35 {TYPE_6__ core; int /*<<< orphan*/  fll; } ;
struct TYPE_16__ {char* part; int num; int rev; int num_mems; int /*<<< orphan*/  mem; int /*<<< orphan*/  base; int /*<<< orphan*/  regmap; int /*<<< orphan*/  dev; int /*<<< orphan*/  type; } ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int /*<<< orphan*/  CS47L35_DIG_VU ; 
 int CS47L35_NUM_ADSP ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ MADERA_FLL1_CONTROL_1 ; 
 int /*<<< orphan*/  MADERA_IRQ_DSP_IRQ1 ; 
 int MADERA_MAX_DAI ; 
 int /*<<< orphan*/  WMFW_ADSP2 ; 
 int /*<<< orphan*/  cs47l35_adsp2_irq ; 
 int /*<<< orphan*/ * cs47l35_dai ; 
 int /*<<< orphan*/ * cs47l35_digital_vu ; 
 int /*<<< orphan*/ * cs47l35_dsp1_regions ; 
 int /*<<< orphan*/ * cs47l35_dsp_regions ; 
 int /*<<< orphan*/  dev_dbg (TYPE_3__*,char*) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,int) ; 
 struct madera* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn (TYPE_3__*,char*,int) ; 
 struct cs47l35* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int devm_snd_soc_register_component (TYPE_3__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  madera_core_free (TYPE_6__*) ; 
 int madera_core_init (TYPE_6__*) ; 
 int /*<<< orphan*/  madera_free_irq (struct madera*,int /*<<< orphan*/ ,struct cs47l35*) ; 
 int /*<<< orphan*/  madera_free_overheat (TYPE_6__*) ; 
 int /*<<< orphan*/  madera_init_dai (TYPE_6__*,int) ; 
 int /*<<< orphan*/  madera_init_fll (struct madera*,int,scalar_t__,int /*<<< orphan*/ *) ; 
 int madera_init_overheat (TYPE_6__*) ; 
 int madera_request_irq (struct madera*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,struct cs47l35*) ; 
 int madera_set_irq_wake (struct madera*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct cs47l35*) ; 
 int /*<<< orphan*/  pm_runtime_disable (TYPE_3__*) ; 
 int /*<<< orphan*/  pm_runtime_enable (TYPE_3__*) ; 
 int /*<<< orphan*/  pm_runtime_idle (TYPE_3__*) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  soc_component_dev_cs47l35 ; 
 int /*<<< orphan*/ * wm_adsp2_control_bases ; 
 int wm_adsp2_init (TYPE_1__*) ; 
 int /*<<< orphan*/  wm_adsp2_remove (TYPE_1__*) ; 

__attribute__((used)) static int cs47l35_probe(struct platform_device *pdev)
{
	struct madera *madera = dev_get_drvdata(pdev->dev.parent);
	struct cs47l35 *cs47l35;
	int i, ret;

	BUILD_BUG_ON(ARRAY_SIZE(cs47l35_dai) > MADERA_MAX_DAI);

	/* quick exit if Madera irqchip driver hasn't completed probe */
	if (!madera->irq_dev) {
		dev_dbg(&pdev->dev, "irqchip driver not ready\n");
		return -EPROBE_DEFER;
	}

	cs47l35 = devm_kzalloc(&pdev->dev, sizeof(struct cs47l35), GFP_KERNEL);
	if (!cs47l35)
		return -ENOMEM;
	platform_set_drvdata(pdev, cs47l35);

	cs47l35->core.madera = madera;
	cs47l35->core.dev = &pdev->dev;
	cs47l35->core.num_inputs = 4;

	ret = madera_core_init(&cs47l35->core);
	if (ret)
		return ret;

	ret = madera_init_overheat(&cs47l35->core);
	if (ret)
		goto error_core;

	ret = madera_request_irq(madera, MADERA_IRQ_DSP_IRQ1,
				 "ADSP2 Compressed IRQ", cs47l35_adsp2_irq,
				 cs47l35);
	if (ret) {
		dev_err(&pdev->dev, "Failed to request DSP IRQ: %d\n", ret);
		goto error_overheat;
	}

	ret = madera_set_irq_wake(madera, MADERA_IRQ_DSP_IRQ1, 1);
	if (ret)
		dev_warn(&pdev->dev, "Failed to set DSP IRQ wake: %d\n", ret);

	for (i = 0; i < CS47L35_NUM_ADSP; i++) {
		cs47l35->core.adsp[i].part = "cs47l35";
		cs47l35->core.adsp[i].num = i + 1;
		cs47l35->core.adsp[i].type = WMFW_ADSP2;
		cs47l35->core.adsp[i].rev = 1;
		cs47l35->core.adsp[i].dev = madera->dev;
		cs47l35->core.adsp[i].regmap = madera->regmap_32bit;

		cs47l35->core.adsp[i].base = wm_adsp2_control_bases[i];
		cs47l35->core.adsp[i].mem = cs47l35_dsp_regions[i];
		cs47l35->core.adsp[i].num_mems =
			ARRAY_SIZE(cs47l35_dsp1_regions);

		ret = wm_adsp2_init(&cs47l35->core.adsp[i]);
		if (ret) {
			for (--i; i >= 0; --i)
				wm_adsp2_remove(&cs47l35->core.adsp[i]);
			goto error_dsp_irq;
		}
	}

	madera_init_fll(madera, 1, MADERA_FLL1_CONTROL_1 - 1, &cs47l35->fll);

	for (i = 0; i < ARRAY_SIZE(cs47l35_dai); i++)
		madera_init_dai(&cs47l35->core, i);

	/* Latch volume update bits */
	for (i = 0; i < ARRAY_SIZE(cs47l35_digital_vu); i++)
		regmap_update_bits(madera->regmap, cs47l35_digital_vu[i],
				   CS47L35_DIG_VU, CS47L35_DIG_VU);

	pm_runtime_enable(&pdev->dev);
	pm_runtime_idle(&pdev->dev);

	ret = devm_snd_soc_register_component(&pdev->dev,
					      &soc_component_dev_cs47l35,
					      cs47l35_dai,
					      ARRAY_SIZE(cs47l35_dai));
	if (ret < 0) {
		dev_err(&pdev->dev, "Failed to register component: %d\n", ret);
		goto error_pm_runtime;
	}

	return ret;

error_pm_runtime:
	pm_runtime_disable(&pdev->dev);

	for (i = 0; i < CS47L35_NUM_ADSP; i++)
		wm_adsp2_remove(&cs47l35->core.adsp[i]);
error_dsp_irq:
	madera_set_irq_wake(madera, MADERA_IRQ_DSP_IRQ1, 0);
	madera_free_irq(madera, MADERA_IRQ_DSP_IRQ1, cs47l35);
error_overheat:
	madera_free_overheat(&cs47l35->core);
error_core:
	madera_core_free(&cs47l35->core);

	return ret;
}