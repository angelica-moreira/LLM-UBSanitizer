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
struct extended_attribute {int namelen; } ;

/* Variables and functions */
 int ea_valuelen (struct extended_attribute*) ; 

__attribute__((used)) static inline struct extended_attribute *next_ea(struct extended_attribute *ea)
{
	return (struct extended_attribute *)((char *)ea + 5 + ea->namelen + ea_valuelen(ea));
}