#ifndef ZCU_CS_H
#define ZCU_CS_H

#include "common.h"

#define CS_BASE 0xFE800000

#define ROM 0x0
#define TSGEN 0x100000
#define FUNNEL0 0x110000
#define FUNNEL1 0x120000
#define FUNNEL2 0x130000
#define TMC1 0x140000
#define TMC2 0x150000
#define REPLIC 0x160000
#define TMC3 0x170000
#define TPIU 0x180000
#define CTI0 0x190000
#define CTI1 0x1A0000
#define CTI2 0x1B0000
#define STM 0x1C0000
#define FTM 0x1D0000

#define R5_ROM 0x3E0000
#define R5_0_DEBUG 0x3F0000
#define R5_1_DEBUG 0x3F2000
#define R5_0_CTI 0x3F8000
#define R5_1_CTI 0x3F9000
#define R5_0_ETM 0x3FC000
#define R5_1_ETM 0x3FD000


#define R5_0_ATCM 0xFFE00000
#define R5_0_BTCM 0xFFE20000

#define A53_ROM 0x400000
#define A53_0_DEBUG 0x410000
#define A53_0_CTI 0x420000
#define A53_0_PMU 0x430000
#define A53_0_ETM 0x440000
#define A53_1_DEBUG 0x510000
#define A53_1_CTI 0x520000
#define A53_1_PMU 0x530000
#define A53_1_ETM 0x540000
#define A53_2_DEBUG 0x610000
#define A53_2_CTI 0x620000
#define A53_2_PMU 0x630000
#define A53_2_ETM 0x640000
#define A53_3_DEBUG 0x710000
#define A53_3_CTI 0x720000
#define A53_3_PMU 0x730000
#define A53_3_ETM 0x740000



// #define CHECK(r,p) ( (r & 0x1 << (p) ) >> (p) )
// #define SET(r,p) ( r |= 0x1 << (p) )
// #define CLEAR(r,p) ( r &= ~(0x1 << (p) ) )

enum component {
    Rom,
    Tsgen,
    Funnel0,
    Funnel1,
    Funnel2,
    Tmc1,
    Tmc2,
    Tmc3,
    Replic,
    Tpiu,
    Cti0,
    Cti1,
    Cti2,
    Stm,
    Ftm,
    R5_rom,
    R5_0_debug,
    R5_1_debug,
    R5_0_cti,
    R5_1_cti,
    R5_0_etm,
    R5_1_etm,
    A53_rom,
    A53_0_debug,
    A53_0_cti,
    A53_0_pmu,
    A53_0_etm,
    A53_1_debug,
    A53_1_cti,
    A53_1_pmu,
    A53_1_etm,
    A53_2_debug,
    A53_2_cti,
    A53_2_pmu,
    A53_2_etm,
    A53_3_debug,
    A53_3_cti,
    A53_3_pmu,
    A53_3_etm,
    };

volatile void* cs_register(enum component);

#endif
