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
typedef  int /*<<< orphan*/  u64 ;
struct switchtec_ntb {int /*<<< orphan*/  db_valid_mask; } ;
struct ntb_dev {int dummy; } ;

/* Variables and functions */
 struct switchtec_ntb* ntb_sndev (struct ntb_dev*) ; 

__attribute__((used)) static u64 switchtec_ntb_db_vector_mask(struct ntb_dev *ntb, int db_vector)
{
	struct switchtec_ntb *sndev = ntb_sndev(ntb);

	if (db_vector < 0 || db_vector > 1)
		return 0;

	return sndev->db_valid_mask;
}