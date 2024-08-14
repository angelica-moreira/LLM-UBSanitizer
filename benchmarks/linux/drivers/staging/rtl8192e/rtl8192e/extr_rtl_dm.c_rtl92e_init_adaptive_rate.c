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
struct rate_adaptive {int ping_rssi_enable; int ping_rssi_thresh_for_ra; int upper_rssi_threshold_ratr; int middle_rssi_threshold_ratr; int low_rssi_threshold_ratr; int low_rssi_threshold_ratr_40M; int low_rssi_threshold_ratr_20M; int ping_rssi_ratr; void* low_rssi_thresh_for_ra40M; void* low_rssi_thresh_for_ra20M; void* high_rssi_thresh_for_ra; void* low2high_rssi_thresh_for_ra40M; void* low2high_rssi_thresh_for_ra20M; void* high2low_rssi_thresh_for_ra; int /*<<< orphan*/  ratr_state; } ;
struct r8192_priv {scalar_t__ CustomerID; scalar_t__ rf_type; struct rate_adaptive rate_adaptive; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DM_RATR_STA_MAX ; 
 scalar_t__ RF_1T2R ; 
 scalar_t__ RF_2T4R ; 
 scalar_t__ RT_CID_819x_Netcore ; 
 void* RateAdaptiveTH_High ; 
 void* RateAdaptiveTH_Low_20M ; 
 void* RateAdaptiveTH_Low_40M ; 
 struct r8192_priv* rtllib_priv (struct net_device*) ; 

void rtl92e_init_adaptive_rate(struct net_device *dev)
{

	struct r8192_priv *priv = rtllib_priv(dev);
	struct rate_adaptive *pra = &priv->rate_adaptive;

	pra->ratr_state = DM_RATR_STA_MAX;
	pra->high2low_rssi_thresh_for_ra = RateAdaptiveTH_High;
	pra->low2high_rssi_thresh_for_ra20M = RateAdaptiveTH_Low_20M+5;
	pra->low2high_rssi_thresh_for_ra40M = RateAdaptiveTH_Low_40M+5;

	pra->high_rssi_thresh_for_ra = RateAdaptiveTH_High+5;
	pra->low_rssi_thresh_for_ra20M = RateAdaptiveTH_Low_20M;
	pra->low_rssi_thresh_for_ra40M = RateAdaptiveTH_Low_40M;

	if (priv->CustomerID == RT_CID_819x_Netcore)
		pra->ping_rssi_enable = 1;
	else
		pra->ping_rssi_enable = 0;
	pra->ping_rssi_thresh_for_ra = 15;


	if (priv->rf_type == RF_2T4R) {
		pra->upper_rssi_threshold_ratr		=	0x8f0f0000;
		pra->middle_rssi_threshold_ratr		=	0x8f0ff000;
		pra->low_rssi_threshold_ratr		=	0x8f0ff001;
		pra->low_rssi_threshold_ratr_40M	=	0x8f0ff005;
		pra->low_rssi_threshold_ratr_20M	=	0x8f0ff001;
		pra->ping_rssi_ratr	=	0x0000000d;
	} else if (priv->rf_type == RF_1T2R) {
		pra->upper_rssi_threshold_ratr		=	0x000fc000;
		pra->middle_rssi_threshold_ratr		=	0x000ff000;
		pra->low_rssi_threshold_ratr		=	0x000ff001;
		pra->low_rssi_threshold_ratr_40M	=	0x000ff005;
		pra->low_rssi_threshold_ratr_20M	=	0x000ff001;
		pra->ping_rssi_ratr	=	0x0000000d;
	}

}