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
struct vmw_piter {struct page* (* page ) (struct vmw_piter*) ;} ;
struct page {int dummy; } ;

/* Variables and functions */
 struct page* stub1 (struct vmw_piter*) ; 

__attribute__((used)) static inline struct page *vmw_piter_page(struct vmw_piter *viter)
{
	return viter->page(viter);
}