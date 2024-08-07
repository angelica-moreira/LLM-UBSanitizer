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
typedef  int u32 ;
struct uniphier_spi_priv {scalar_t__ base; } ;
struct spi_device {int /*<<< orphan*/  master; } ;

/* Variables and functions */
 int FIELD_PREP (int,int) ; 
 scalar_t__ SSI_RXWDS ; 
 int SSI_RXWDS_DTLEN_MASK ; 
 scalar_t__ SSI_TXWDS ; 
 int SSI_TXWDS_DTLEN_MASK ; 
 int SSI_TXWDS_WDLEN_MASK ; 
 int readl (scalar_t__) ; 
 struct uniphier_spi_priv* spi_master_get_devdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static void uniphier_spi_set_transfer_size(struct spi_device *spi, int size)
{
	struct uniphier_spi_priv *priv = spi_master_get_devdata(spi->master);
	u32 val;

	val = readl(priv->base + SSI_TXWDS);
	val &= ~(SSI_TXWDS_WDLEN_MASK | SSI_TXWDS_DTLEN_MASK);
	val |= FIELD_PREP(SSI_TXWDS_WDLEN_MASK, size);
	val |= FIELD_PREP(SSI_TXWDS_DTLEN_MASK, size);
	writel(val, priv->base + SSI_TXWDS);

	val = readl(priv->base + SSI_RXWDS);
	val &= ~SSI_RXWDS_DTLEN_MASK;
	val |= FIELD_PREP(SSI_RXWDS_DTLEN_MASK, size);
	writel(val, priv->base + SSI_RXWDS);
}