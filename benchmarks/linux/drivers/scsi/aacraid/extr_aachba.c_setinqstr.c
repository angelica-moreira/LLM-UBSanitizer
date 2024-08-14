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
struct scsi_inq {char* vid; char* pid; char* prl; } ;
struct aac_supplement_adapter_info {scalar_t__* adapter_type_text; } ;
struct aac_driver_ident {char* vname; char* model; } ;
struct aac_dev {int /*<<< orphan*/  cardtype; struct aac_supplement_adapter_info supplement_adapter_info; } ;

/* Variables and functions */
 int ARRAY_SIZE (char**) ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 struct aac_driver_ident* aac_get_driver_ident (int /*<<< orphan*/ ) ; 
 char** container_types ; 
 int /*<<< orphan*/  inqstrcpy (char*,char*) ; 
 int /*<<< orphan*/  kfree (char*) ; 
 char* kmemdup (scalar_t__*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ memcmp (char*,char*,int) ; 
 int /*<<< orphan*/  memset (struct scsi_inq*,char,int) ; 
 int strlen (char*) ; 

__attribute__((used)) static void setinqstr(struct aac_dev *dev, void *data, int tindex)
{
	struct scsi_inq *str;
	struct aac_supplement_adapter_info *sup_adap_info;

	sup_adap_info = &dev->supplement_adapter_info;
	str = (struct scsi_inq *)(data); /* cast data to scsi inq block */
	memset(str, ' ', sizeof(*str));

	if (sup_adap_info->adapter_type_text[0]) {
		int c;
		char *cp;
		char *cname = kmemdup(sup_adap_info->adapter_type_text,
				sizeof(sup_adap_info->adapter_type_text),
								GFP_ATOMIC);
		if (!cname)
			return;

		cp = cname;
		if ((cp[0] == 'A') && (cp[1] == 'O') && (cp[2] == 'C'))
			inqstrcpy("SMC", str->vid);
		else {
			c = sizeof(str->vid);
			while (*cp && *cp != ' ' && --c)
				++cp;
			c = *cp;
			*cp = '\0';
			inqstrcpy(cname, str->vid);
			*cp = c;
			while (*cp && *cp != ' ')
				++cp;
		}
		while (*cp == ' ')
			++cp;
		/* last six chars reserved for vol type */
		if (strlen(cp) > sizeof(str->pid))
			cp[sizeof(str->pid)] = '\0';
		inqstrcpy (cp, str->pid);

		kfree(cname);
	} else {
		struct aac_driver_ident *mp = aac_get_driver_ident(dev->cardtype);

		inqstrcpy (mp->vname, str->vid);
		/* last six chars reserved for vol type */
		inqstrcpy (mp->model, str->pid);
	}

	if (tindex < ARRAY_SIZE(container_types)){
		char *findit = str->pid;

		for ( ; *findit != ' '; findit++); /* walk till we find a space */
		/* RAID is superfluous in the context of a RAID device */
		if (memcmp(findit-4, "RAID", 4) == 0)
			*(findit -= 4) = ' ';
		if (((findit - str->pid) + strlen(container_types[tindex]))
		 < (sizeof(str->pid) + sizeof(str->prl)))
			inqstrcpy (container_types[tindex], findit + 1);
	}
	inqstrcpy ("V1.0", str->prl);
}