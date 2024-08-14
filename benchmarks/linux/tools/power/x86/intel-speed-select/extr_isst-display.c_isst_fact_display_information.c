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
struct isst_fact_info {int dummy; } ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  _isst_fact_display_information (int,int /*<<< orphan*/ *,int,int,int,struct isst_fact_info*,int) ; 
 int /*<<< orphan*/  format_and_print (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  print_package_info (int,int /*<<< orphan*/ *) ; 

void isst_fact_display_information(int cpu, FILE *outf, int level,
				   int fact_bucket, int fact_avx,
				   struct isst_fact_info *fact_info)
{
	print_package_info(cpu, outf);
	_isst_fact_display_information(cpu, outf, level, fact_bucket, fact_avx,
				       fact_info, 4);
	format_and_print(outf, 1, NULL, NULL);
}