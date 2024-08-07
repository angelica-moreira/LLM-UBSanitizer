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
typedef  int u8 ;
struct ieee80211_if_managed {int uapsd_queues; } ;
struct TYPE_2__ {struct ieee80211_if_managed mgd; } ;
struct ieee80211_sub_if_data {TYPE_1__ u; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int ERANGE ; 
 int IEEE80211_WMM_IE_STA_QOSINFO_AC_MASK ; 
 int kstrtou8 (char const*,int /*<<< orphan*/ ,int*) ; 

__attribute__((used)) static ssize_t ieee80211_if_parse_uapsd_queues(
	struct ieee80211_sub_if_data *sdata, const char *buf, int buflen)
{
	struct ieee80211_if_managed *ifmgd = &sdata->u.mgd;
	u8 val;
	int ret;

	ret = kstrtou8(buf, 0, &val);
	if (ret)
		return ret;

	if (val & ~IEEE80211_WMM_IE_STA_QOSINFO_AC_MASK)
		return -ERANGE;

	ifmgd->uapsd_queues = val;

	return buflen;
}