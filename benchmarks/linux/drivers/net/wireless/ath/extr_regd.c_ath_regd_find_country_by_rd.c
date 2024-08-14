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
struct country_code_to_enum_rd {int regDmnEnum; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct country_code_to_enum_rd*) ; 
 struct country_code_to_enum_rd* allCountries ; 

__attribute__((used)) static struct country_code_to_enum_rd*
ath_regd_find_country_by_rd(int regdmn)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(allCountries); i++) {
		if (allCountries[i].regDmnEnum == regdmn)
			return &allCountries[i];
	}
	return NULL;
}