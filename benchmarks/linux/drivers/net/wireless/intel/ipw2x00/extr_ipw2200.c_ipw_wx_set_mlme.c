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
typedef  union iwreq_data {int dummy; } iwreq_data ;
struct net_device {int dummy; } ;
struct iw_request_info {int dummy; } ;
struct iw_mlme {int cmd; int /*<<< orphan*/  reason_code; } ;
struct ipw_priv {int dummy; } ;
typedef  int /*<<< orphan*/  __le16 ;

/* Variables and functions */
 int EOPNOTSUPP ; 
#define  IW_MLME_DEAUTH 129 
#define  IW_MLME_DISASSOC 128 
 int /*<<< orphan*/  cpu_to_le16 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ipw_disassociate (struct ipw_priv*) ; 
 struct ipw_priv* libipw_priv (struct net_device*) ; 

__attribute__((used)) static int ipw_wx_set_mlme(struct net_device *dev,
			   struct iw_request_info *info,
			   union iwreq_data *wrqu, char *extra)
{
	struct ipw_priv *priv = libipw_priv(dev);
	struct iw_mlme *mlme = (struct iw_mlme *)extra;
	__le16 reason;

	reason = cpu_to_le16(mlme->reason_code);

	switch (mlme->cmd) {
	case IW_MLME_DEAUTH:
		/* silently ignore */
		break;

	case IW_MLME_DISASSOC:
		ipw_disassociate(priv);
		break;

	default:
		return -EOPNOTSUPP;
	}
	return 0;
}