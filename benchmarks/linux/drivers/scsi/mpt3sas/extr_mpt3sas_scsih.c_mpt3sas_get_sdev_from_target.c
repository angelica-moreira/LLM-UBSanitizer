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
struct _sas_device {int dummy; } ;
struct MPT3SAS_TARGET {int dummy; } ;
struct MPT3SAS_ADAPTER {int /*<<< orphan*/  sas_device_lock; } ;

/* Variables and functions */
 struct _sas_device* __mpt3sas_get_sdev_from_target (struct MPT3SAS_ADAPTER*,struct MPT3SAS_TARGET*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static struct _sas_device *
mpt3sas_get_sdev_from_target(struct MPT3SAS_ADAPTER *ioc,
		struct MPT3SAS_TARGET *tgt_priv)
{
	struct _sas_device *ret;
	unsigned long flags;

	spin_lock_irqsave(&ioc->sas_device_lock, flags);
	ret = __mpt3sas_get_sdev_from_target(ioc, tgt_priv);
	spin_unlock_irqrestore(&ioc->sas_device_lock, flags);

	return ret;
}