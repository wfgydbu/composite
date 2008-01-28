#include "include/measurement.h"
#include <linux/kernel.h>

#ifdef MEASUREMENTS

/*
 * TODO list of events to measure:
 * - deallocation of cspd during ipc
 * - deallocation of cspd during mpd operation
 * - merges
 * - splits
 * - moves
 * - split with optimization
 * - mpd deallocations due to subordination
 */

unsigned long long cos_measurements[COS_MEAS_MAX_SIZE];
char *cos_meas_descriptions[COS_MEAS_MAX_SIZE+1] = 
{
	"cooperative thread switch",
	"preemptive thread switch",
	"interrupt preemption",
	"component SDT invocations",
	"bootstrapping upcalls",
	"incriment pending brands",
	"branded upcalls",
	"interrupted user-level",
	"interrupted kern-level",
	"interrupted cos thread",
	"interrupted other thread",
	"composite page fault",
	"linux page fault",
	"unknown fault",
	"mpd alloc",
	"mpd subordinate",
	"mpd split mpd reuse",
	"mpd free",
	"mpd refcnt increase",
	"mpd refcnt decrease",
	"mpd ipc refcnt increase",
	"mpd ipc refcnt decrease",
	"page table allocation",
	"page table free",
	""
};

void cos_meas_init(void)
{
	int i;

	for (i = 0; i < COS_MEAS_MAX_SIZE ; i++) {
		cos_measurements[i] = 0;
	}

	return;
}

void cos_meas_report(void)
{
	int i;

	printk("cos: Measurements:\n");
	for (i = 0 ; i < COS_MEAS_MAX_SIZE ; i++) {
		printk("cos: %30s : %lld\n", 
		       cos_meas_descriptions[i], cos_measurements[i]);
	}

	return;
	
}

#endif
