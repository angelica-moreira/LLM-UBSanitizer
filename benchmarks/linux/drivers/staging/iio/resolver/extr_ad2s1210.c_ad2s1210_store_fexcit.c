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
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct ad2s1210_state {unsigned int fexcit; int /*<<< orphan*/  lock; } ;
typedef  int ssize_t ;

/* Variables and functions */
 unsigned int AD2S1210_MAX_EXCIT ; 
 unsigned int AD2S1210_MIN_EXCIT ; 
 int EINVAL ; 
 int ad2s1210_soft_reset (struct ad2s1210_state*) ; 
 int ad2s1210_update_frequency_control_word (struct ad2s1210_state*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 int /*<<< orphan*/  dev_to_iio_dev (struct device*) ; 
 struct ad2s1210_state* iio_priv (int /*<<< orphan*/ ) ; 
 int kstrtouint (char const*,int,unsigned int*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static ssize_t ad2s1210_store_fexcit(struct device *dev,
				     struct device_attribute *attr,
				     const char *buf, size_t len)
{
	struct ad2s1210_state *st = iio_priv(dev_to_iio_dev(dev));
	unsigned int fexcit;
	int ret;

	ret = kstrtouint(buf, 10, &fexcit);
	if (ret < 0)
		return ret;
	if (fexcit < AD2S1210_MIN_EXCIT || fexcit > AD2S1210_MAX_EXCIT) {
		dev_err(dev,
			"ad2s1210: excitation frequency out of range\n");
		return -EINVAL;
	}
	mutex_lock(&st->lock);
	st->fexcit = fexcit;
	ret = ad2s1210_update_frequency_control_word(st);
	if (ret < 0)
		goto error_ret;
	ret = ad2s1210_soft_reset(st);
error_ret:
	mutex_unlock(&st->lock);

	return ret < 0 ? ret : len;
}