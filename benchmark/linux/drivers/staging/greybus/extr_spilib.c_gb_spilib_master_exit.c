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
struct spi_master {int dummy; } ;
struct gb_connection {int dummy; } ;

/* Variables and functions */
 struct spi_master* gb_connection_get_data (struct gb_connection*) ; 
 int /*<<< orphan*/  spi_unregister_master (struct spi_master*) ; 

void gb_spilib_master_exit(struct gb_connection *connection)
{
	struct spi_master *master = gb_connection_get_data(connection);

	spi_unregister_master(master);
}