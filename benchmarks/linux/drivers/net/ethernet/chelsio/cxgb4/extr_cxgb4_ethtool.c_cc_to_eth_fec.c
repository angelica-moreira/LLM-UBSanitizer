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

/* Variables and functions */
 unsigned int ETHTOOL_FEC_AUTO ; 
 unsigned int ETHTOOL_FEC_BASER ; 
 unsigned int ETHTOOL_FEC_OFF ; 
 unsigned int ETHTOOL_FEC_RS ; 
 unsigned int FEC_AUTO ; 
 unsigned int FEC_BASER_RS ; 
 unsigned int FEC_RS ; 

__attribute__((used)) static inline unsigned int cc_to_eth_fec(unsigned int cc_fec)
{
	unsigned int eth_fec = 0;

	if (cc_fec & FEC_AUTO)
		eth_fec |= ETHTOOL_FEC_AUTO;
	if (cc_fec & FEC_RS)
		eth_fec |= ETHTOOL_FEC_RS;
	if (cc_fec & FEC_BASER_RS)
		eth_fec |= ETHTOOL_FEC_BASER;

	/* if nothing is set, then FEC is off */
	if (!eth_fec)
		eth_fec = ETHTOOL_FEC_OFF;

	return eth_fec;
}