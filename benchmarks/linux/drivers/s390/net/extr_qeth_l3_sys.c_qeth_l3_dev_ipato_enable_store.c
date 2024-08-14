#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int enabled; } ;
struct qeth_card {scalar_t__ state; int /*<<< orphan*/  conf_mutex; int /*<<< orphan*/  ip_lock; TYPE_1__ ipato; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 scalar_t__ CARD_STATE_DOWN ; 
 int EINVAL ; 
 int EPERM ; 
 struct qeth_card* dev_get_drvdata (struct device*) ; 
 scalar_t__ kstrtobool (char const*,int*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  qeth_l3_update_ipato (struct qeth_card*) ; 
 scalar_t__ sysfs_streq (char const*,char*) ; 

__attribute__((used)) static ssize_t qeth_l3_dev_ipato_enable_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	struct qeth_card *card = dev_get_drvdata(dev);
	bool enable;
	int rc = 0;

	if (!card)
		return -EINVAL;

	mutex_lock(&card->conf_mutex);
	if (card->state != CARD_STATE_DOWN) {
		rc = -EPERM;
		goto out;
	}

	if (sysfs_streq(buf, "toggle")) {
		enable = !card->ipato.enabled;
	} else if (kstrtobool(buf, &enable)) {
		rc = -EINVAL;
		goto out;
	}

	if (card->ipato.enabled != enable) {
		card->ipato.enabled = enable;
		mutex_lock(&card->ip_lock);
		qeth_l3_update_ipato(card);
		mutex_unlock(&card->ip_lock);
	}
out:
	mutex_unlock(&card->conf_mutex);
	return rc ? rc : count;
}