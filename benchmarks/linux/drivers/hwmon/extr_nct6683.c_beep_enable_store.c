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
typedef  int /*<<< orphan*/  u8 ;
struct nct6683_data {int /*<<< orphan*/  update_lock; int /*<<< orphan*/  sioreg; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 size_t EINVAL ; 
 int /*<<< orphan*/  NCT6683_CR_BEEP_MASK ; 
 int /*<<< orphan*/  NCT6683_LD_HWM ; 
 int /*<<< orphan*/  NCT6683_REG_CR_BEEP ; 
 struct nct6683_data* dev_get_drvdata (struct device*) ; 
 scalar_t__ kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int superio_enter (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  superio_exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  superio_inb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  superio_outb (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  superio_select (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t
beep_enable_store(struct device *dev, struct device_attribute *attr,
		  const char *buf, size_t count)
{
	struct nct6683_data *data = dev_get_drvdata(dev);
	unsigned long val;
	u8 reg;
	int ret;

	if (kstrtoul(buf, 10, &val) || (val != 0 && val != 1))
		return -EINVAL;

	mutex_lock(&data->update_lock);

	ret = superio_enter(data->sioreg);
	if (ret) {
		count = ret;
		goto error;
	}

	superio_select(data->sioreg, NCT6683_LD_HWM);
	reg = superio_inb(data->sioreg, NCT6683_REG_CR_BEEP);
	if (val)
		reg |= NCT6683_CR_BEEP_MASK;
	else
		reg &= ~NCT6683_CR_BEEP_MASK;
	superio_outb(data->sioreg, NCT6683_REG_CR_BEEP, reg);
	superio_exit(data->sioreg);
error:
	mutex_unlock(&data->update_lock);
	return count;
}