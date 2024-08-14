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
struct shared_info {int /*<<< orphan*/  child_sync; } ;
typedef  scalar_t__ pid_t ;

/* Variables and functions */
 int IPC_CREAT ; 
 int /*<<< orphan*/  IPC_PRIVATE ; 
 int /*<<< orphan*/  IPC_RMID ; 
 int TEST_FAIL ; 
 int child (struct shared_info*) ; 
 int /*<<< orphan*/  destroy_child_sync (int /*<<< orphan*/ *) ; 
 scalar_t__ fork () ; 
 int /*<<< orphan*/  free (char*) ; 
 int init_child_sync (int /*<<< orphan*/ *) ; 
 int parent (struct shared_info*,scalar_t__) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int setup_core_pattern (char**,int*) ; 
 struct shared_info* shmat (int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  shmctl (int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  shmdt (struct shared_info*) ; 
 int shmget (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  write_core_pattern (char*) ; 

__attribute__((used)) static int core_pkey(void)
{
	char *core_pattern;
	bool changed_core_pattern;
	struct shared_info *info;
	int shm_id;
	int ret;
	pid_t pid;

	ret = setup_core_pattern(&core_pattern, &changed_core_pattern);
	if (ret)
		return ret;

	shm_id = shmget(IPC_PRIVATE, sizeof(*info), 0777 | IPC_CREAT);
	info = shmat(shm_id, NULL, 0);

	ret = init_child_sync(&info->child_sync);
	if (ret)
		return ret;

	pid = fork();
	if (pid < 0) {
		perror("fork() failed");
		ret = TEST_FAIL;
	} else if (pid == 0)
		ret = child(info);
	else
		ret = parent(info, pid);

	shmdt(info);

	if (pid) {
		destroy_child_sync(&info->child_sync);
		shmctl(shm_id, IPC_RMID, NULL);

		if (changed_core_pattern)
			write_core_pattern(core_pattern);
	}

	free(core_pattern);

	return ret;
}