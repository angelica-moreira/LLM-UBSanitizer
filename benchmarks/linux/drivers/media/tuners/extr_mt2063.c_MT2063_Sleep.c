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
struct dvb_frontend {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  msleep (int) ; 

__attribute__((used)) static int MT2063_Sleep(struct dvb_frontend *fe)
{
	/*
	 *  ToDo:  Add code here to implement a OS blocking
	 */
	msleep(100);

	return 0;
}