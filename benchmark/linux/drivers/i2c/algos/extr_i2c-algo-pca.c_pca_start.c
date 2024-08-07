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
struct i2c_algo_pca_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEB2 (char*) ; 
 int I2C_PCA_CON_SI ; 
 int I2C_PCA_CON_STA ; 
 int I2C_PCA_CON_STO ; 
 int pca_get_con (struct i2c_algo_pca_data*) ; 
 int /*<<< orphan*/  pca_set_con (struct i2c_algo_pca_data*,int) ; 
 int pca_wait (struct i2c_algo_pca_data*) ; 

__attribute__((used)) static int pca_start(struct i2c_algo_pca_data *adap)
{
	int sta = pca_get_con(adap);
	DEB2("=== START\n");
	sta |= I2C_PCA_CON_STA;
	sta &= ~(I2C_PCA_CON_STO|I2C_PCA_CON_SI);
	pca_set_con(adap, sta);
	return pca_wait(adap);
}