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
typedef  int /*<<< orphan*/  u8 ;
struct mtd_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  mtd_ooblayout_free ; 
 int mtd_ooblayout_get_bytes (struct mtd_info*,int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int,int,int /*<<< orphan*/ ) ; 

int mtd_ooblayout_get_databytes(struct mtd_info *mtd, u8 *databuf,
				const u8 *oobbuf, int start, int nbytes)
{
	return mtd_ooblayout_get_bytes(mtd, databuf, oobbuf, start, nbytes,
				       mtd_ooblayout_free);
}