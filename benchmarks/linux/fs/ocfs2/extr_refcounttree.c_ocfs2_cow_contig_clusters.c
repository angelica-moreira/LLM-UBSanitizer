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
struct super_block {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MAX_CONTIG_BYTES ; 
 unsigned int ocfs2_clusters_for_bytes (struct super_block*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline unsigned int ocfs2_cow_contig_clusters(struct super_block *sb)
{
	return ocfs2_clusters_for_bytes(sb, MAX_CONTIG_BYTES);
}