#ifndef IC_EXTRA_SYMS_H
#define IC_EXTRA_SYMS_H

/*
 * Per-build fake-cred objects that the old 66-entry anchor tables never
 * carried.  They are data symbols (not code anchors), so they cannot be
 * derived from a table; they are extracted from the image of each build we
 * have locally, which makes those builds work from the built-in table alone
 * (no external ic-syms.txt, i.e. the same result as "解析偏移").
 *
 * Keyed by the anchor table's name.  Missing builds simply fall back to the
 * external table.
 */
struct ic_extra_syms {
    const char *table;
    unsigned long long root_user;
    unsigned long long init_ucounts;
    unsigned long long init_groups;
};

static const struct ic_extra_syms ic_extra_syms_tab[] = {
    /* 6.1.145-android14-11-maybe-dirty, iQOO 12 16.2.11 (download_kernel.Image) */
    { "iqoo12-16.2.11", 0xffffffc00a121108ULL, 0xffffffc00a1229b8ULL,
      0xffffffc00a122428ULL },
    /* 6.1.145-android14-11-maybe-dirty, PD2307/PD2329 16.2.21.1
     * (iqoo12-16211-kernel.Image; tp=0xffffffc00a3cc1c0 matches the table) */
    { "ic_iqoo12_16211_links", 0xffffffc00a1f11c8ULL, 0xffffffc00a1f2a78ULL,
      0xffffffc00a1f24e8ULL },
    /* PD2307 16.2.20.3 / 16.2.20.7 share ic_iqoo12_links; extracted from
     * pd2307-162207-boot.img (tp=0xffffffc00a3cb180 and
     * selinux=0xffffffc00a558f40 both match the table). */
    { "ic_iqoo12_links", 0xffffffc00a1f11c8ULL, 0xffffffc00a1f2a78ULL,
      0xffffffc00a1f24e8ULL },
    /* PD2516/V2516 (Y500 Pro) 16.1.11.0, kernel_y500pro_16110.img
     * (tp=0xffffffc00a2d17e0 / selinux=0xffffffc00a45d8c8 match). */
    { "ic_y500pro_16110_links", 0xffffffc00a101088ULL, 0xffffffc00a102938ULL,
      0xffffffc00a1023a8ULL },
    /* PD2324 (X100 series) 16.2.12.0, pd2324_kernel.Image
     * (tp=0xffffffc00a2f3600 matches). */
    { "ic_pd2324_links", 0xffffffc00a121108ULL, 0xffffffc00a1229b8ULL,
      0xffffffc00a122428ULL },

    /* PD2352_A_16.2.17.0.W10 full OTA (20260821140727…); image banner
     * 6.1.145-android14-11-maybe-dirty.  The three objects are exactly at
     * the fixed deltas from init_user_ns (verified against the image). */
    { "ic_pd2352_162170_links", 0xffffffc00a1f11c8ULL, 0xffffffc00a1f2a78ULL,
      0xffffffc00a1f24e8ULL },

    /* PD2425_A_16.1.17.10 boot.img (banner 6.1.145-android14-11-maybe-dirty,
     * boot fingerprint vivo/PD2425/PD2425 … compiler260917174806). */
    { "ic_pd2425_1611710_links", 0xffffffc00a1f11c8ULL, 0xffffffc00a1f2a78ULL,
      0xffffffc00a1f24e8ULL },

    /* vivo T4 (PD2456IF / V2502) 16.1.17.5.W30, table's own kernel
     * 6.1.145-android14-11-g74d1702dab4d-ab14669069.  Extracted from the
     * kallsyms of a sibling Image (6.1.145-android14-11-g9b69cc399ae1-
     * ab14819715) whose .data layout is identical to this build:
     * runqueues, __tracepoint_sys_exit, selinux_state, init_user_ns,
     * init_cred, module_notify_list and panic_on_warn all match the
     * device's ic-syms.txt at the same addresses.  init_groups ends
     * exactly at init_cred (sizeof(struct group_info) == 8), init_ucounts
     * is 0x560 above init_cred.  On this build the ns-relative guesses
     * (ns+0x298 / ns+0x1b48 / ns+0x15b8) are all wrong and ns+0x15b8
     * aliases init_cred itself. */
    { "ic_pd2456_161175_links", 0xffffffc00a020740ULL, 0xffffffc00a021fc8ULL,
      0xffffffc00a021a60ULL },
};

#endif /* IC_EXTRA_SYMS_H */
