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
typedef  int U64 ;
typedef  int U32 ;

/* Variables and functions */
 int prime6bytes ; 

__attribute__((used)) static size_t ZSTD_hash6(U64 u, U32 h) { return (size_t)(((u << (64 - 48)) * prime6bytes) >> (64 - h)); }