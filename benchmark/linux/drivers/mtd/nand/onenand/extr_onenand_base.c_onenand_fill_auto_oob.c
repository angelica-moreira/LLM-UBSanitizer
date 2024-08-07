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
typedef  int /*<<< orphan*/  u_char ;
struct mtd_info {int dummy; } ;

/* Variables and functions */
 int mtd_ooblayout_set_databytes (struct mtd_info*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *,int,int) ; 

__attribute__((used)) static int onenand_fill_auto_oob(struct mtd_info *mtd, u_char *oob_buf,
				  const u_char *buf, int column, int thislen)
{
	return mtd_ooblayout_set_databytes(mtd, buf, oob_buf, column, thislen);
}