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
typedef  int /*<<< orphan*/  aq_to_posix ;

/* Variables and functions */
 int E2BIG ; 
 int EACCES ; 
 int EAGAIN ; 
 int EBUSY ; 
 int EEXIST ; 
 int EFAULT ; 
 int EFBIG ; 
 int EINTR ; 
 int EINVAL ; 
 int EIO ; 
 int ENOENT ; 
 int ENOMEM ; 
 int ENOSPC ; 
 int ENOSYS ; 
 int ENOTTY ; 
 int ENXIO ; 
 int EPERM ; 
 int EPIPE ; 
 int ERANGE ; 
 int EROFS ; 
 int ESPIPE ; 
 int ESRCH ; 
 int IAVF_ERR_ADMIN_QUEUE_TIMEOUT ; 

__attribute__((used)) static inline int iavf_aq_rc_to_posix(int aq_ret, int aq_rc)
{
	int aq_to_posix[] = {
		0,           /* IAVF_AQ_RC_OK */
		-EPERM,      /* IAVF_AQ_RC_EPERM */
		-ENOENT,     /* IAVF_AQ_RC_ENOENT */
		-ESRCH,      /* IAVF_AQ_RC_ESRCH */
		-EINTR,      /* IAVF_AQ_RC_EINTR */
		-EIO,        /* IAVF_AQ_RC_EIO */
		-ENXIO,      /* IAVF_AQ_RC_ENXIO */
		-E2BIG,      /* IAVF_AQ_RC_E2BIG */
		-EAGAIN,     /* IAVF_AQ_RC_EAGAIN */
		-ENOMEM,     /* IAVF_AQ_RC_ENOMEM */
		-EACCES,     /* IAVF_AQ_RC_EACCES */
		-EFAULT,     /* IAVF_AQ_RC_EFAULT */
		-EBUSY,      /* IAVF_AQ_RC_EBUSY */
		-EEXIST,     /* IAVF_AQ_RC_EEXIST */
		-EINVAL,     /* IAVF_AQ_RC_EINVAL */
		-ENOTTY,     /* IAVF_AQ_RC_ENOTTY */
		-ENOSPC,     /* IAVF_AQ_RC_ENOSPC */
		-ENOSYS,     /* IAVF_AQ_RC_ENOSYS */
		-ERANGE,     /* IAVF_AQ_RC_ERANGE */
		-EPIPE,      /* IAVF_AQ_RC_EFLUSHED */
		-ESPIPE,     /* IAVF_AQ_RC_BAD_ADDR */
		-EROFS,      /* IAVF_AQ_RC_EMODE */
		-EFBIG,      /* IAVF_AQ_RC_EFBIG */
	};

	/* aq_rc is invalid if AQ timed out */
	if (aq_ret == IAVF_ERR_ADMIN_QUEUE_TIMEOUT)
		return -EAGAIN;

	if (!((u32)aq_rc < (sizeof(aq_to_posix) / sizeof((aq_to_posix)[0]))))
		return -ERANGE;

	return aq_to_posix[aq_rc];
}