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
struct ipu_ic_priv {scalar_t__ use_count; int /*<<< orphan*/  lock; int /*<<< orphan*/  ipu; } ;
struct ipu_ic {int rotation; int graphics; struct ipu_ic_priv* priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  IPU_CONF_IC_EN ; 
 int /*<<< orphan*/  ipu_irt_disable (struct ipu_ic*) ; 
 int /*<<< orphan*/  ipu_module_disable (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

int ipu_ic_disable(struct ipu_ic *ic)
{
	struct ipu_ic_priv *priv = ic->priv;
	unsigned long flags;

	spin_lock_irqsave(&priv->lock, flags);

	priv->use_count--;

	if (!priv->use_count)
		ipu_module_disable(priv->ipu, IPU_CONF_IC_EN);

	if (priv->use_count < 0)
		priv->use_count = 0;

	if (ic->rotation)
		ipu_irt_disable(ic);

	ic->rotation = ic->graphics = false;

	spin_unlock_irqrestore(&priv->lock, flags);

	return 0;
}