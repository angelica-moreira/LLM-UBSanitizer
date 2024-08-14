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
struct scatterlist {int dummy; } ;
struct protection_domain {int dummy; } ;
struct dma_ops_domain {int dummy; } ;
struct device {int dummy; } ;
typedef  enum dma_data_direction { ____Placeholder_dma_data_direction } dma_data_direction ;

/* Variables and functions */
 scalar_t__ IS_ERR (struct protection_domain*) ; 
 unsigned long PAGE_MASK ; 
 int PAGE_SHIFT ; 
 int /*<<< orphan*/  __unmap_single (struct dma_ops_domain*,unsigned long,int,int) ; 
 struct protection_domain* get_domain (struct device*) ; 
 unsigned long sg_dma_address (struct scatterlist*) ; 
 int sg_num_pages (struct device*,struct scatterlist*,int) ; 
 struct dma_ops_domain* to_dma_ops_domain (struct protection_domain*) ; 

__attribute__((used)) static void unmap_sg(struct device *dev, struct scatterlist *sglist,
		     int nelems, enum dma_data_direction dir,
		     unsigned long attrs)
{
	struct protection_domain *domain;
	struct dma_ops_domain *dma_dom;
	unsigned long startaddr;
	int npages;

	domain = get_domain(dev);
	if (IS_ERR(domain))
		return;

	startaddr = sg_dma_address(sglist) & PAGE_MASK;
	dma_dom   = to_dma_ops_domain(domain);
	npages    = sg_num_pages(dev, sglist, nelems);

	__unmap_single(dma_dom, startaddr, npages << PAGE_SHIFT, dir);
}