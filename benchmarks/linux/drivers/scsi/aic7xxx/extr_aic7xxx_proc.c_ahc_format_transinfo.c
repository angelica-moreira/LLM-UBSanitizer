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
typedef  int u_int ;
struct seq_file {int dummy; } ;
struct ahc_transinfo {scalar_t__ offset; int width; int ppr_options; int /*<<< orphan*/  period; } ;

/* Variables and functions */
 int MSG_EXT_PPR_DT_REQ ; 
 int ahc_calc_syncsrate (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,int,...) ; 
 int /*<<< orphan*/  seq_putc (struct seq_file*,char) ; 
 int /*<<< orphan*/  seq_puts (struct seq_file*,char*) ; 

__attribute__((used)) static void
ahc_format_transinfo(struct seq_file *m, struct ahc_transinfo *tinfo)
{
	u_int speed;
	u_int freq;
	u_int mb;

        speed = 3300;
        freq = 0;
	if (tinfo->offset != 0) {
		freq = ahc_calc_syncsrate(tinfo->period);
		speed = freq;
	}
	speed *= (0x01 << tinfo->width);
        mb = speed / 1000;
        if (mb > 0)
		seq_printf(m, "%d.%03dMB/s transfers", mb, speed % 1000);
        else
		seq_printf(m, "%dKB/s transfers", speed);

	if (freq != 0) {
		seq_printf(m, " (%d.%03dMHz%s, offset %d",
			 freq / 1000, freq % 1000,
			 (tinfo->ppr_options & MSG_EXT_PPR_DT_REQ) != 0
			 ? " DT" : "", tinfo->offset);
	}

	if (tinfo->width > 0) {
		if (freq != 0) {
			seq_puts(m, ", ");
		} else {
			seq_puts(m, " (");
		}
		seq_printf(m, "%dbit)", 8 * (0x01 << tinfo->width));
	} else if (freq != 0) {
		seq_putc(m, ')');
	}
	seq_putc(m, '\n');
}