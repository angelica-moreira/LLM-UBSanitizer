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
struct net_device {int dummy; } ;
struct nd_opt_hdr {scalar_t__ nd_opt_type; } ;

/* Variables and functions */
 scalar_t__ ND_OPT_CAPTIVE_PORTAL ; 
 scalar_t__ ND_OPT_DNSSL ; 
 scalar_t__ ND_OPT_RDNSS ; 
 scalar_t__ ndisc_ops_is_useropt (struct net_device const*,scalar_t__) ; 

__attribute__((used)) static inline int ndisc_is_useropt(const struct net_device *dev,
				   struct nd_opt_hdr *opt)
{
	return opt->nd_opt_type == ND_OPT_RDNSS ||
		opt->nd_opt_type == ND_OPT_DNSSL ||
		opt->nd_opt_type == ND_OPT_CAPTIVE_PORTAL ||
		ndisc_ops_is_useropt(dev, opt->nd_opt_type);
}