#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {struct TYPE_4__* next; struct TYPE_4__* tail; } ;
typedef  TYPE_1__ IARTN_Q ;

/* Variables and functions */

__attribute__((used)) static IARTN_Q * ia_deque_rtn_q (IARTN_Q *que) {
   IARTN_Q *tmpdata;
   if (que->next == NULL)
      return NULL;
   tmpdata = que->next;
   if ( que->next == que->tail)  
      que->next = que->tail = NULL;
   else 
      que->next = que->next->next;
   return tmpdata;
}