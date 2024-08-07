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
struct TYPE_2__ {int flags; int /*<<< orphan*/  value; scalar_t__ disabled; } ;
union iwreq_data {TYPE_1__ retry; } ;
struct r8192_priv {int /*<<< orphan*/  retry_data; int /*<<< orphan*/  retry_rts; } ;
struct net_device {int dummy; } ;
struct iw_request_info {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int IW_RETRY_LIFETIME ; 
 int IW_RETRY_LIMIT ; 
 int IW_RETRY_MAX ; 
 int IW_RETRY_MIN ; 
 int IW_RETRY_TYPE ; 
 struct r8192_priv* rtllib_priv (struct net_device*) ; 

__attribute__((used)) static int _rtl92e_wx_get_retry(struct net_device *dev,
				struct iw_request_info *info,
				union iwreq_data *wrqu, char *extra)
{
	struct r8192_priv *priv = rtllib_priv(dev);

	wrqu->retry.disabled = 0; /* can't be disabled */

	if ((wrqu->retry.flags & IW_RETRY_TYPE) ==
	    IW_RETRY_LIFETIME)
		return -EINVAL;

	if (wrqu->retry.flags & IW_RETRY_MAX) {
		wrqu->retry.flags = IW_RETRY_LIMIT | IW_RETRY_MAX;
		wrqu->retry.value = priv->retry_rts;
	} else {
		wrqu->retry.flags = IW_RETRY_LIMIT | IW_RETRY_MIN;
		wrqu->retry.value = priv->retry_data;
	}
	return 0;
}