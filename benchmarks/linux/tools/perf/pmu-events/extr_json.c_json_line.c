#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  start; } ;
typedef  TYPE_1__ jsmntok_t ;

/* Variables and functions */
 int countchar (char*,char,int /*<<< orphan*/ ) ; 

int json_line(char *map, jsmntok_t *t)
{
	return countchar(map, '\n', t->start) + 1;
}