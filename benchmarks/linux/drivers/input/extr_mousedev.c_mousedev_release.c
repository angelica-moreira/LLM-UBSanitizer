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
struct mousedev_client {struct mousedev* mousedev; } ;
struct mousedev {int /*<<< orphan*/  (* close_device ) (struct mousedev*) ;} ;
struct inode {int dummy; } ;
struct file {struct mousedev_client* private_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct mousedev_client*) ; 
 int /*<<< orphan*/  mousedev_detach_client (struct mousedev*,struct mousedev_client*) ; 
 int /*<<< orphan*/  stub1 (struct mousedev*) ; 

__attribute__((used)) static int mousedev_release(struct inode *inode, struct file *file)
{
	struct mousedev_client *client = file->private_data;
	struct mousedev *mousedev = client->mousedev;

	mousedev_detach_client(mousedev, client);
	kfree(client);

	mousedev->close_device(mousedev);

	return 0;
}