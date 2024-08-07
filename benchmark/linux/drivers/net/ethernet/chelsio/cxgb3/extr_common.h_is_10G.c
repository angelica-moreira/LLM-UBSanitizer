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
struct adapter {int dummy; } ;
struct TYPE_2__ {int caps; } ;

/* Variables and functions */
 int SUPPORTED_10000baseT_Full ; 
 TYPE_1__* adapter_info (struct adapter const*) ; 

__attribute__((used)) static inline int is_10G(const struct adapter *adap)
{
	return adapter_info(adap)->caps & SUPPORTED_10000baseT_Full;
}