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
struct mvpp2_prs_entry {int* tcam; } ;

/* Variables and functions */
 int MVPP2_PRS_PORT_MASK ; 
 size_t MVPP2_PRS_TCAM_PORT_WORD ; 

unsigned int mvpp2_prs_tcam_port_map_get(struct mvpp2_prs_entry *pe)
{
	return (~pe->tcam[MVPP2_PRS_TCAM_PORT_WORD] >> 24) & MVPP2_PRS_PORT_MASK;
}