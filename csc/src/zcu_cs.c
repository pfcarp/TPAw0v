#include "zcu_cs.h"
#include "cs_soc.h"
#include "cs_etm.h"
#include "cs_pmu.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>


volatile void* cs_register(enum component comp)
{
	volatile void* ptr = NULL;
    int fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd < 0) {
        perror("Cannot open /dev/mem\n");
        exit(1);
    }

    switch(comp) {
        case Funnel0:
            ptr = mmap(NULL, sizeof(Funnel_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + FUNNEL0);
            break;
        case Funnel1:
            ptr = mmap(NULL, sizeof(Funnel_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + FUNNEL1);
            break;
        case Funnel2:
            ptr = mmap(NULL, sizeof(Funnel_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + FUNNEL2);
            break;
        case Tmc1:
            ptr = mmap(NULL, sizeof(TMC_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + TMC1);
            break;
        case Tmc2:
            ptr = mmap(NULL, sizeof(TMC_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + TMC2);
            break;
        case Tmc3:
            ptr = mmap(NULL, sizeof(TMC_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + TMC3);
            break;
        case Replic:
            ptr = mmap(NULL, sizeof(Replicator_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + REPLIC);
            break;
        case Tpiu:
            printf("IMPORTANT NOTICE!\n");
            printf("If you are trying to use TPIU, then on ZCU102/Kria, you need to connect jumper J88\n");
            printf("Reference https://support.xilinx.com/s/article/66669?language=en_US\n");
            ptr = mmap(NULL, sizeof(TPIU_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + TPIU);
            break;
        case Cti0:
            ptr = mmap(NULL, sizeof(CTI_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + CTI0);
            break;
        case Cti1:
            ptr = mmap(NULL, sizeof(CTI_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + CTI1);
            break;
        case Cti2:
            ptr = mmap(NULL, sizeof(CTI_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + CTI2);
            break;
        case A53_0_etm:
            ptr = mmap(NULL, sizeof(ETM_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + A53_0_ETM);
            break;
        case A53_0_pmu:
            ptr = mmap(NULL, sizeof(PMU_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + A53_0_PMU);
            break;
        case A53_0_cti:
            ptr = mmap(NULL, sizeof(CTI_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + A53_0_CTI);
            break;
        case A53_0_debug:
            ptr = mmap(NULL, sizeof(CTI_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + A53_0_DEBUG);
            break;
        case A53_1_etm:
            ptr = mmap(NULL, sizeof(ETM_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + A53_1_ETM);
            break;
        case A53_1_pmu:
            ptr = mmap(NULL, sizeof(PMU_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + A53_1_PMU);
            break;
        case A53_1_cti:
            ptr = mmap(NULL, sizeof(CTI_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + A53_1_CTI);
            break;
        case A53_1_debug:
            ptr = mmap(NULL, sizeof(CTI_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + A53_1_DEBUG);
            break;
        case A53_2_etm:
            ptr = mmap(NULL, sizeof(ETM_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + A53_2_ETM);
            break;
        case A53_2_pmu:
            ptr = mmap(NULL, sizeof(PMU_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + A53_2_PMU);
            break;
        case A53_2_cti:
            ptr = mmap(NULL, sizeof(CTI_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + A53_2_CTI);
            break;
        case A53_2_debug:
            ptr = mmap(NULL, sizeof(CTI_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + A53_2_DEBUG);
            break;
        case A53_3_etm:
            ptr = mmap(NULL, sizeof(ETM_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + A53_3_ETM);
            break;
        case A53_3_pmu:
            ptr = mmap(NULL, sizeof(PMU_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + A53_3_PMU);
            break;
        case A53_3_cti:
            ptr = mmap(NULL, sizeof(CTI_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + A53_3_CTI);
            break;
        case A53_3_debug:
            ptr = mmap(NULL, sizeof(CTI_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + A53_3_DEBUG);
            break;
        case R5_0_cti:
            ptr = mmap(NULL, sizeof(CTI_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + R5_0_CTI);
            break;
        case R5_1_cti:
            ptr = mmap(NULL, sizeof(CTI_interface), PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + R5_1_CTI);
            break;
        default:
            fprintf(stderr, "Unimplemented component %d\n", comp);
            exit(1);
            break;
    }

	if (ptr == MAP_FAILED)
		fprintf(stderr,"mmap to component %d failed!\n", comp);
	close(fd);

#ifdef DEBUG
#endif

    return ptr;
}
