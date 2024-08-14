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

/* Variables and functions */
 int SLOT_HEIGHT ; 
 int SLOT_MULT ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  svgfile ; 
 double time2pixels (int /*<<< orphan*/ ) ; 

void svg_interrupt(u64 start, int row, const char *backtrace)
{
	if (!svgfile)
		return;

	fprintf(svgfile, "<g>\n");

	fprintf(svgfile, "<title>Wakeup from interrupt</title>\n");

	if (backtrace)
		fprintf(svgfile, "<desc>%s</desc>\n", backtrace);

	fprintf(svgfile, "<circle  cx=\"%.8f\" cy=\"%.2f\" r = \"0.01\"  style=\"fill:rgb(255,128,128)\"/>\n",
			time2pixels(start), row * SLOT_MULT);
	fprintf(svgfile, "<circle  cx=\"%.8f\" cy=\"%.2f\" r = \"0.01\"  style=\"fill:rgb(255,128,128)\"/>\n",
			time2pixels(start), row * SLOT_MULT + SLOT_HEIGHT);

	fprintf(svgfile, "</g>\n");
}