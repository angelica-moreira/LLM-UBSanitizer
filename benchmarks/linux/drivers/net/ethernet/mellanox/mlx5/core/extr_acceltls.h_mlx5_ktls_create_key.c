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
typedef  int /*<<< orphan*/  u32 ;
struct tls_crypto_info {int dummy; } ;
struct mlx5_core_dev {int dummy; } ;

/* Variables and functions */
 int ENOTSUPP ; 

__attribute__((used)) static inline int
mlx5_ktls_create_key(struct mlx5_core_dev *mdev,
		     struct tls_crypto_info *crypto_info,
		     u32 *p_key_id) { return -ENOTSUPP; }