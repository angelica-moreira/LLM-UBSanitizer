#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {TYPE_1__* proto; } ;
struct TYPE_5__ {int /*<<< orphan*/  (* write_regr ) (TYPE_2__*,int,int,int) ;} ;
typedef  TYPE_2__ PIA ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (TYPE_2__*,int,int,int) ; 

void pi_write_regr(PIA * pi, int cont, int regr, int val)
{
	pi->proto->write_regr(pi, cont, regr, val);
}