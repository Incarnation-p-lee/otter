#include "riscv_vector.h"
#include <math.h>

// riscv64-unknown-elf-gcc -march=rv64gcv -mabi=lp64d
// doc/rvv_intrinsic_shortcut.c -c -S -O2 -o -

/* vadd */
vint32m1_t shortcut_for_riscv_vadd_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vadd_vv_i32m1(v1, v1, vl);
}

vint32m1_t shortcut_for_riscv_vadd_case_1(vint32m1_t v1, size_t vl) {
  return __riscv_vadd_vx_i32m1(v1, 0, vl);
}

vint32m1_t shortcut_for_riscv_vadd_case_2(vint32m1_t v1, int32_t reg,
                                          size_t vl) {
  return __riscv_vadd_vx_i32m1(v1, reg, vl);
}

/* vsub */
vint32m1_t shortcut_for_riscv_vsub_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vsub_vv_i32m1(v1, v1, vl);
}

vint32m1_t shortcut_for_riscv_vsub_case_1(vint32m1_t v1, int32_t reg,
                                          size_t vl) {
  return __riscv_vsub_vx_i32m1(v1, reg, vl);
}

/* vrsub */
vint32m1_t shortcut_for_riscv_vrsub_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vrsub_vx_i32m1(v1, 0, vl);
}

/* vwaddu */
vuint64m2_t shortcut_for_riscv_vwaddu_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vwaddu_vv_u64m2(v1, v1, vl);
}

vuint64m2_t shortcut_for_riscv_vwaddu_case_1(vuint32m1_t v1, size_t vl) {
  return __riscv_vwaddu_vx_u64m2(v1, 0, vl);
}

vuint64m1_t shortcut_for_riscv_vwaddu_case_2(vuint64m1_t v1, size_t vl) {
  return __riscv_vwaddu_wx_u64m1(v1, 0, vl);
}

/* vwsubu */
vuint64m2_t shortcut_for_riscv_vwsubu_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vwsubu_vv_u64m2(v1, v1, vl);
}

vuint64m2_t shortcut_for_riscv_vwsubu_case_1(vuint32m1_t v1, size_t vl) {
  return __riscv_vwsubu_vx_u64m2(v1, 0, vl);
}

vuint64m1_t shortcut_for_riscv_vwsubu_case_2(vuint64m1_t v1, size_t vl) {
  return __riscv_vwsubu_wx_u64m1(v1, 0, vl);
}

/* vwadd */
vint64m2_t shortcut_for_riscv_vwadd_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vwadd_vv_i64m2(v1, v1, vl);
}

vint64m2_t shortcut_for_riscv_vwadd_case_1(vint32m1_t v1, size_t vl) {
  return __riscv_vwadd_vx_i64m2(v1, 0, vl);
}

vint64m1_t shortcut_for_riscv_vwadd_case_2(vint64m1_t v1, size_t vl) {
  return __riscv_vwadd_wx_i64m1(v1, 0, vl);
}

/* vwsub */
vint64m2_t shortcut_for_riscv_vwsub_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vwsub_vv_i64m2(v1, v1, vl);
}

vint64m2_t shortcut_for_riscv_vwsub_case_1(vint32m1_t v1, size_t vl) {
  return __riscv_vwsub_vx_i64m2(v1, 0, vl);
}

vint64m1_t shortcut_for_riscv_vwsub_case_2(vint64m1_t v1, size_t vl) {
  return __riscv_vwsub_wx_i64m1(v1, 0, vl);
}

/* vadc */
vint32m1_t shortcut_for_riscv_vadc_case_0(vint32m1_t v1, vbool32_t carry,
                                          size_t vl) {
  return __riscv_vadc_vvm_i32m1(v1, v1, carry, vl);
}

vint32m1_t shortcut_for_riscv_vadc_case_1(vint32m1_t v1, vbool32_t carry,
                                          size_t vl) {
  return __riscv_vadc_vxm_i32m1(v1, 0, carry, vl);
}

/* vmadc */
vbool32_t shortcut_for_riscv_vmadc_case_0(vint32m1_t v1, vbool32_t carry,
                                          size_t vl) {
  return __riscv_vmadc_vvm_i32m1_b32(v1, v1, carry, vl);
}

vbool32_t shortcut_for_riscv_vmadc_case_1(vint32m1_t v1, vbool32_t carry,
                                          size_t vl) {
  return __riscv_vmadc_vxm_i32m1_b32(v1, 0, carry, vl);
}

vbool32_t shortcut_for_riscv_vmadc_case_2(vint32m1_t v1, size_t vl) {
  return __riscv_vmadc_vv_i32m1_b32(v1, v1, vl);
}

vbool32_t shortcut_for_riscv_vmadc_case_3(vint32m1_t v1, size_t vl) {
  return __riscv_vmadc_vx_i32m1_b32(v1, 0, vl);
}

/* vsbc */
vint32m1_t shortcut_for_riscv_vsbc_case_0(vint32m1_t v1, vbool32_t carry,
                                          size_t vl) {
  return __riscv_vsbc_vvm_i32m1(v1, v1, carry, vl);
}

vint32m1_t shortcut_for_riscv_vsbc_case_1(vint32m1_t v1, vbool32_t carry,
                                          size_t vl) {
  return __riscv_vsbc_vxm_i32m1(v1, 0, carry, vl);
}

/* vmsbc */
vbool32_t shortcut_for_riscv_vmsbc_case_0(vint32m1_t v1, vbool32_t carry,
                                          size_t vl) {
  return __riscv_vmsbc_vvm_i32m1_b32(v1, v1, carry, vl);
}

vbool32_t shortcut_for_riscv_vmsbc_case_1(vint32m1_t v1, vbool32_t carry,
                                          size_t vl) {
  return __riscv_vmsbc_vxm_i32m1_b32(v1, 0, carry, vl);
}

vbool32_t shortcut_for_riscv_vmsbc_case_2(vint32m1_t v1, size_t vl) {
  return __riscv_vmsbc_vv_i32m1_b32(v1, v1, vl);
}

vbool32_t shortcut_for_riscv_vmsbc_case_3(vint32m1_t v1, size_t vl) {
  return __riscv_vmsbc_vx_i32m1_b32(v1, 0, vl);
}

/* vand */
vint32m1_t shortcut_for_riscv_vand_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vand_vv_i32m1(v1, v1, vl);
}

vint32m1_t shortcut_for_riscv_vand_case_1(vint32m1_t v1, size_t vl) {
  return __riscv_vand_vx_i32m1(v1, 0, vl);
}

vint32m1_t shortcut_for_riscv_vand_case_2(vint32m1_t v1, size_t vl) {
  return __riscv_vand_vx_i32m1(v1, 1, vl);
}

/* vor */
vint32m1_t shortcut_for_riscv_vor_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vor_vv_i32m1(v1, v1, vl);
}

vint32m1_t shortcut_for_riscv_vor_case_1(vint32m1_t v1, size_t vl) {
  return __riscv_vor_vx_i32m1(v1, 0, vl);
}

vint32m1_t shortcut_for_riscv_vor_case_2(vint32m1_t v1, size_t vl) {
  return __riscv_vor_vx_i32m1(v1, 1, vl);
}

/* vxor */
vint32m1_t shortcut_for_riscv_vxor_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vxor_vv_i32m1(v1, v1, vl);
}

vint32m1_t shortcut_for_riscv_vxor_case_1(vint32m1_t v1, size_t vl) {
  return __riscv_vxor_vx_i32m1(v1, 0, vl);
}

vint32m1_t shortcut_for_riscv_vxor_case_2(vint32m1_t v1, size_t vl) {
  return __riscv_vxor_vx_i32m1(v1, 1, vl);
}

/* vsll */
vuint32m1_t shortcut_for_riscv_vsll_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vsll_vv_u32m1(v1, v1, vl);
}

vuint32m1_t shortcut_for_riscv_vsll_case_1(vuint32m1_t v1, size_t vl) {
  return __riscv_vsll_vx_u32m1(v1, 0, vl);
}

vuint32m1_t shortcut_for_riscv_vsll_case_2(vuint32m1_t v1, size_t vl) {
  return __riscv_vsll_vx_u32m1(v1, 31, vl);
}

vuint32m1_t shortcut_for_riscv_vsll_case_3(vuint32m1_t v1, size_t vl) {
  return __riscv_vsll_vx_u32m1(v1, 32, vl);
}

/* vsrl */
vuint32m1_t shortcut_for_riscv_vsrl_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vsrl_vv_u32m1(v1, v1, vl);
}

vuint32m1_t shortcut_for_riscv_vsrl_case_1(vuint32m1_t v1, size_t vl) {
  return __riscv_vsrl_vx_u32m1(v1, 0, vl);
}

vuint32m1_t shortcut_for_riscv_vsrl_case_2(vuint32m1_t v1, size_t vl) {
  return __riscv_vsrl_vx_u32m1(v1, 31, vl);
}

vuint32m1_t shortcut_for_riscv_vsrl_case_3(vuint32m1_t v1, size_t vl) {
  return __riscv_vsrl_vx_u32m1(v1, 32, vl);
}

vuint32m1_t shortcut_for_riscv_vsrl_case_4(vuint32m1_t v1, size_t vl) {
  return __riscv_vsrl_vx_u32m1(v1, 64, vl);
}

/* vsra */
vint32m1_t shortcut_for_riscv_vsra_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vsra_vx_i32m1(v1, 0, vl);
}

vint32m1_t shortcut_for_riscv_vsra_case_1(vint32m1_t v1, size_t vl) {
  return __riscv_vsra_vx_i32m1(v1, 31, vl);
}

vint32m1_t shortcut_for_riscv_vsra_case_2(vint32m1_t v1, size_t vl) {
  return __riscv_vsra_vx_i32m1(v1, 32, vl);
}

vint32m1_t shortcut_for_riscv_vsra_case_3(vint32m1_t v1, size_t vl) {
  return __riscv_vsra_vx_i32m1(v1, 64, vl);
}

/* vnsrl */
vuint32m1_t shortcut_for_riscv_vnsrl_case_0(vuint64m2_t v1, size_t vl) {
  return __riscv_vnsrl_wx_u32m1(v1, 0, vl);
}

vuint32m1_t shortcut_for_riscv_vnsrl_case_1(vuint64m2_t v1, size_t vl) {
  return __riscv_vnsrl_wx_u32m1(v1, 31, vl);
}

vuint32m1_t shortcut_for_riscv_vnsrl_case_2(vuint64m2_t v1, size_t vl) {
  return __riscv_vnsrl_wx_u32m1(v1, 32, vl);
}

vuint32m1_t shortcut_for_riscv_vnsrl_case_3(vuint64m2_t v1, size_t vl) {
  return __riscv_vnsrl_wx_u32m1(v1, 64, vl);
}

/* vnsra */
vint32m1_t shortcut_for_riscv_vnsra_case_0(vint64m2_t v1, size_t vl) {
  return __riscv_vnsra_wx_i32m1(v1, 0, vl);
}

vint32m1_t shortcut_for_riscv_vnsra_case_1(vint64m2_t v1, size_t vl) {
  return __riscv_vnsra_wx_i32m1(v1, 31, vl);
}

vint32m1_t shortcut_for_riscv_vnsra_case_2(vint64m2_t v1, size_t vl) {
  return __riscv_vnsra_wx_i32m1(v1, 32, vl);
}

vint32m1_t shortcut_for_riscv_vnsra_case_3(vint64m2_t v1, size_t vl) {
  return __riscv_vnsra_wx_i32m1(v1, 64, vl);
}

/* vmseq */
vbool32_t shortcut_for_riscv_vmseq_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vmseq_vv_i32m1_b32(v1, v1, vl);
}

vbool32_t shortcut_for_riscv_vmseq_case_1(vint32m1_t v1, size_t vl) {
  return __riscv_vmseq_vx_i32m1_b32(v1, 0, vl);
}

/* vmsne */
vbool32_t shortcut_for_riscv_vmsne_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vmsne_vv_i32m1_b32(v1, v1, vl);
}

vbool32_t shortcut_for_riscv_vmsne_case_1(vint32m1_t v1, size_t vl) {
  return __riscv_vmsne_vx_i32m1_b32(v1, 0, vl);
}

/* vmsltu */
vbool32_t shortcut_for_riscv_vmsltu_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vmsltu_vv_u32m1_b32(v1, v1, vl);
}

vbool32_t shortcut_for_riscv_vmsltu_case_1(vuint32m1_t v1, size_t vl) {
  return __riscv_vmsltu_vx_u32m1_b32(v1, 0, vl);
}

/* vmslt */
vbool32_t shortcut_for_riscv_vmslt_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vmslt_vv_i32m1_b32(v1, v1, vl);
}

vbool32_t shortcut_for_riscv_vmslt_case_1(vint32m1_t v1, size_t vl) {
  return __riscv_vmslt_vx_i32m1_b32(v1, 0, vl);
}

/* vmsleu */
vbool32_t shortcut_for_riscv_vmsleu_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vmsleu_vv_u32m1_b32(v1, v1, vl);
}

vbool32_t shortcut_for_riscv_vmsleu_case_1(vuint32m1_t v1, size_t vl) {
  return __riscv_vmsleu_vx_u32m1_b32(v1, 0, vl);
}

/* vmsle */
vbool32_t shortcut_for_riscv_vmsle_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vmsle_vv_i32m1_b32(v1, v1, vl);
}

vbool32_t shortcut_for_riscv_vmsle_case_1(vint32m1_t v1, size_t vl) {
  return __riscv_vmsle_vx_i32m1_b32(v1, 0, vl);
}

/* vmsgtu */
vbool32_t shortcut_for_riscv_vmsgtu_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vmsgtu_vv_u32m1_b32(v1, v1, vl);
}

vbool32_t shortcut_for_riscv_vmsgtu_case_1(vuint32m1_t v1, size_t vl) {
  return __riscv_vmsgtu_vx_u32m1_b32(v1, 0, vl);
}

/* vmsgt */
vbool32_t shortcut_for_riscv_vmsgt_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vmsgt_vv_i32m1_b32(v1, v1, vl);
}

vbool32_t shortcut_for_riscv_vmsgt_case_1(vint32m1_t v1, size_t vl) {
  return __riscv_vmsgt_vx_i32m1_b32(v1, 0, vl);
}

/* vminu */
vuint32m1_t shortcut_for_riscv_vminu_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vminu_vv_u32m1(v1, v1, vl);
}

vuint32m1_t shortcut_for_riscv_vminu_case_1(vuint32m1_t v1, size_t vl) {
  return __riscv_vminu_vx_u32m1(v1, 0, vl);
}

/* vmin */
vint32m1_t shortcut_for_riscv_vmin_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vmin_vv_i32m1(v1, v1, vl);
}

vint32m1_t shortcut_for_riscv_vmin_case_1(vint32m1_t v1, size_t vl) {
  return __riscv_vmin_vx_i32m1(v1, 0, vl);
}

/* vmaxu */
vuint32m1_t shortcut_for_riscv_vmaxu_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vmaxu_vv_u32m1(v1, v1, vl);
}

vuint32m1_t shortcut_for_riscv_vmaxu_case_1(vuint32m1_t v1, size_t vl) {
  return __riscv_vmaxu_vx_u32m1(v1, 0, vl);
}

/* vmax */
vint32m1_t shortcut_for_riscv_vmax_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vmax_vv_i32m1(v1, v1, vl);
}

vint32m1_t shortcut_for_riscv_vmax_case_1(vint32m1_t v1, size_t vl) {
  return __riscv_vmax_vx_i32m1(v1, 0, vl);
}

/* vmul */
vint32m1_t shortcut_for_riscv_vmul_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vmul_vx_i32m1(v1, 0, vl);
}

/* vmulh */
vint32m1_t shortcut_for_riscv_vmulh_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vmulh_vx_i32m1(v1, 0, vl);
}

/* vmulhu */
vuint32m1_t shortcut_for_riscv_vmulhu_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vmulhu_vx_u32m1(v1, 0, vl);
}

/* vmulhsu */
vint32m1_t shortcut_for_riscv_vmulhsu_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vmulhsu_vx_i32m1(v1, 0, vl);
}

/* vdivu */
vuint32m1_t shortcut_for_riscv_vdivu_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vdivu_vv_u32m1(v1, v1, vl);
}

/* vdiv */
vint32m1_t shortcut_for_riscv_vdiv_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vdiv_vv_i32m1(v1, v1, vl);
}

/* vremu */
vuint32m1_t shortcut_for_riscv_vremu_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vremu_vv_u32m1(v1, v1, vl);
}

/* vrem */
vint32m1_t shortcut_for_riscv_vrem_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vrem_vv_i32m1(v1, v1, vl);
}

/* vwmul */
vint64m2_t shortcut_for_riscv_vwmul_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vwmul_vx_i64m2(v1, 0, vl);
}

/* vwmulu */
vuint64m2_t shortcut_for_riscv_vwmulu_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vwmulu_vx_u64m2(v1, 0, vl);
}

/* vwmulsu */
vint64m2_t shortcut_for_riscv_vwmulsu_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vwmulsu_vx_i64m2(v1, 0, vl);
}

/* vmacc */
vint32m1_t shortcut_for_riscv_vmacc_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vmacc_vx_i32m1(v1, 0, v1, vl);
}

/* vnmsac */
vint32m1_t shortcut_for_riscv_vnmsac_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vnmsac_vx_i32m1(v1, 0, v1, vl);
}

/* vmadd */
vint32m1_t shortcut_for_riscv_vmadd_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vmadd_vx_i32m1(v1, 0, v1, vl);
}

/* vnmsub */
vint32m1_t shortcut_for_riscv_vnmsub_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vnmsub_vx_i32m1(v1, 0, v1, vl);
}

/* vwmaccu */
vuint32m1_t shortcut_for_riscv_vwmaccu_case_0(vuint32m1_t v1, vuint16mf2_t v2,
                                              size_t vl) {
  return __riscv_vwmaccu_vx_u32m1(v1, 0, v2, vl);
}

/* vwmacc */
vint32m1_t shortcut_for_riscv_vwmacc_case_0(vint32m1_t v1, vint16mf2_t v2,
                                            size_t vl) {
  return __riscv_vwmacc_vx_i32m1(v1, 0, v2, vl);
}

/* vwmaccsu */
vint32m1_t shortcut_for_riscv_vwmaccsu_case_0(vint32m1_t v1, vuint16mf2_t v2,
                                              size_t vl) {
  return __riscv_vwmaccsu_vx_i32m1(v1, 0, v2, vl);
}

/* vwmaccus */
vint32m1_t shortcut_for_riscv_vwmaccus_case_0(vint32m1_t v1, vint16mf2_t v2,
                                              size_t vl) {
  return __riscv_vwmaccus_vx_i32m1(v1, 0, v2, vl);
}

/* vmerge */
vint32m1_t shortcut_for_riscv_vmerge_case_0(vint32m1_t v1, vbool32_t mask,
                                            size_t vl) {
  return __riscv_vmerge_vvm_i32m1(v1, v1, mask, vl);
}

/* vmv */
vint32m1_t shortcut_for_riscv_vmv_case_0(size_t vl) {
  return __riscv_vmv_v_x_i32m1(0, vl);
}

/* vsaddu */
vuint32m1_t shortcut_for_riscv_vsaddu_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vsaddu_vx_u32m1(v1, 0, vl);
}

/* vsadd */
vint32m1_t shortcut_for_riscv_vsadd_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vsadd_vx_i32m1(v1, 0, vl);
}

/* vssubu */
vuint32m1_t shortcut_for_riscv_vssubu_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vssubu_vx_u32m1(v1, 0, vl);
}

vuint32m1_t shortcut_for_riscv_vssubu_case_1(vuint32m1_t v1, size_t vl) {
  return __riscv_vssubu_vv_u32m1(v1, v1, vl);
}

/* vssub */
vint32m1_t shortcut_for_riscv_vssub_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vssub_vx_i32m1(v1, 0, vl);
}

vint32m1_t shortcut_for_riscv_vssub_case_1(vint32m1_t v1, size_t vl) {
  return __riscv_vssub_vv_i32m1(v1, v1, vl);
}

/* vaaddu */
vuint32m1_t shortcut_for_riscv_vaaddu_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vaaddu_vx_u32m1(v1, 0, vl);
}

vuint32m1_t shortcut_for_riscv_vaaddu_case_1(vuint32m1_t v1, size_t vl) {
  return __riscv_vaaddu_vv_u32m1(v1, v1, vl);
}

/* vaadd */
vint32m1_t shortcut_for_riscv_vaadd_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vaadd_vx_i32m1(v1, 0, vl);
}

vint32m1_t shortcut_for_riscv_vaadd_case_1(vint32m1_t v1, size_t vl) {
  return __riscv_vaadd_vv_i32m1(v1, v1, vl);
}

/* vasubu */
vuint32m1_t shortcut_for_riscv_vasubu_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vasubu_vx_u32m1(v1, 0, vl);
}

vuint32m1_t shortcut_for_riscv_vasubu_case_1(vuint32m1_t v1, size_t vl) {
  return __riscv_vasubu_vv_u32m1(v1, v1, vl);
}

/* vasub */
vint32m1_t shortcut_for_riscv_vasub_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vasub_vx_i32m1(v1, 0, vl);
}

vint32m1_t shortcut_for_riscv_vasub_case_1(vint32m1_t v1, size_t vl) {
  return __riscv_vasub_vv_i32m1(v1, v1, vl);
}

/* vsmul */
vint32m1_t shortcut_for_riscv_vsmul_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vsmul_vx_i32m1(v1, 0, vl);
}

/* vssrl */
vuint32m1_t shortcut_for_riscv_vssrl_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vssrl_vv_u32m1(v1, v1, vl);
}

vuint32m1_t shortcut_for_riscv_vssrl_case_1(vuint32m1_t v1, size_t vl) {
  return __riscv_vssrl_vx_u32m1(v1, 0, vl);
}

/* vssra */
vint32m1_t shortcut_for_riscv_vssra_case_1(vint32m1_t v1, size_t vl) {
  return __riscv_vssra_vx_i32m1(v1, 0, vl);
}

/* vnclipu */
vuint32m1_t shortcut_for_riscv_vnclipu_case_0(vuint64m2_t v1, size_t vl) {
  return __riscv_vnclipu_wx_u32m1(v1, 0, vl);
}

/* vnclip */
vint32m1_t shortcut_for_riscv_vnclip_case_0(vint64m2_t v1, size_t vl) {
  return __riscv_vnclip_wx_i32m1(v1, 0, vl);
}

/* vfadd */
vfloat32m1_t shortcut_for_riscv_vfadd_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfadd_vf_f32m1(v1, 0.0, vl);
}

vfloat32m1_t shortcut_for_riscv_vfadd_case_1(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfadd_vf_f32m1(v1, -0.0, vl);
}

/* vfsub */
vfloat32m1_t shortcut_for_riscv_vfsub_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfsub_vv_f32m1(v1, v1, vl);
}

vfloat32m1_t shortcut_for_riscv_vfsub_case_1(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfsub_vf_f32m1(v1, 0.0, vl);
}

vfloat32m1_t shortcut_for_riscv_vfsub_case_2(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfsub_vf_f32m1(v1, -0.0, vl);
}

/* vfrsub */
vfloat32m1_t shortcut_for_riscv_vfrsub_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfrsub_vf_f32m1(v1, 0.0, vl);
}

vfloat32m1_t shortcut_for_riscv_vfrsub_case_1(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfrsub_vf_f32m1(v1, 0.0, vl);
}

/* vfwadd */
vfloat64m2_t shortcut_for_riscv_vfwadd_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfwadd_vf_f64m2(v1, 0.0, vl);
}

vfloat64m2_t shortcut_for_riscv_vfwadd_case_1(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfwadd_vf_f64m2(v1, -0.0, vl);
}

vfloat64m2_t shortcut_for_riscv_vfwadd_case_2(vfloat64m2_t v1, size_t vl) {
  return __riscv_vfwadd_wf_f64m2(v1, -0.0, vl);
}

vfloat64m2_t shortcut_for_riscv_vfwadd_case_3(vfloat64m2_t v1, size_t vl) {
  return __riscv_vfwadd_wf_f64m2(v1, 0.0, vl);
}

/* vfwsub */
vfloat64m2_t shortcut_for_riscv_vfwsub_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfwsub_vf_f64m2(v1, 0.0, vl);
}

vfloat64m2_t shortcut_for_riscv_vfwsub_case_1(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfwsub_vf_f64m2(v1, -0.0, vl);
}

vfloat64m2_t shortcut_for_riscv_vfwsub_case_2(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfwsub_vv_f64m2(v1, v1, vl);
}

vfloat64m2_t shortcut_for_riscv_vfwsub_case_3(vfloat64m2_t v1, size_t vl) {
  return __riscv_vfwsub_wf_f64m2(v1, 0.0, vl);
}

vfloat64m2_t shortcut_for_riscv_vfwsub_case_4(vfloat64m2_t v1, size_t vl) {
  return __riscv_vfwsub_wf_f64m2(v1, -0.0, vl);
}

/* vfmul */
vfloat32m1_t shortcut_for_riscv_vfmul_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfmul_vf_f32m1(v1, 0.0, vl);
}

vfloat32m1_t shortcut_for_riscv_vfmul_case_1(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfmul_vf_f32m1(v1, -0.0, vl);
}

/* vfdiv */
vfloat32m1_t shortcut_for_riscv_vfdiv_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfdiv_vf_f32m1(v1, 0.0, vl);
}

vfloat32m1_t shortcut_for_riscv_vfdiv_case_1(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfdiv_vf_f32m1(v1, -0.0, vl);
}

/* vfrdiv */
vfloat32m1_t shortcut_for_riscv_vfrdiv_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfrdiv_vf_f32m1(v1, 0.0, vl);
}

vfloat32m1_t shortcut_for_riscv_vfrdiv_case_1(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfrdiv_vf_f32m1(v1, -0.0, vl);
}

/* vfwmul */
vfloat64m2_t shortcut_for_riscv_vfwmul_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfwmul_vf_f64m2(v1, 0.0, vl);
}

vfloat64m2_t shortcut_for_riscv_vfwmul_case_1(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfwmul_vf_f64m2(v1, -0.0, vl);
}

/* vfmacc */
vfloat32m1_t shortcut_for_riscv_vfmacc_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfmacc_vf_f32m1(v1, 0.0, v1, vl);
}

vfloat32m1_t shortcut_for_riscv_vfmacc_case_1(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfmacc_vf_f32m1(v1, -0.0, v1, vl);
}

/* vfnmacc */
vfloat32m1_t shortcut_for_riscv_vfnmacc_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfnmacc_vf_f32m1(v1, 0.0, v1, vl);
}

vfloat32m1_t shortcut_for_riscv_vfnmacc_case_1(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfnmacc_vf_f32m1(v1, -0.0, v1, vl);
}

/* vfmsac */
vfloat32m1_t shortcut_for_riscv_vfmsac_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfmsac_vf_f32m1(v1, 0.0, v1, vl);
}

vfloat32m1_t shortcut_for_riscv_vfmsac_case_1(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfmsac_vf_f32m1(v1, -0.0, v1, vl);
}

/* vfnmsac */
vfloat32m1_t shortcut_for_riscv_vfnmsac_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfnmsac_vf_f32m1(v1, 0.0, v1, vl);
}

vfloat32m1_t shortcut_for_riscv_vfnmsac_case_1(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfnmsac_vf_f32m1(v1, -0.0, v1, vl);
}

/* vfmadd */
vfloat32m1_t shortcut_for_riscv_vfmadd_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfmadd_vf_f32m1(v1, 0.0, v1, vl);
}

vfloat32m1_t shortcut_for_riscv_vfmadd_case_1(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfmadd_vf_f32m1(v1, -0.0, v1, vl);
}

/* vfnmadd */
vfloat32m1_t shortcut_for_riscv_vfnmadd_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfnmadd_vf_f32m1(v1, 0.0, v1, vl);
}

vfloat32m1_t shortcut_for_riscv_vfnmadd_case_1(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfnmadd_vf_f32m1(v1, -0.0, v1, vl);
}

/* vfmsub */
vfloat32m1_t shortcut_for_riscv_vfmsub_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfmsub_vf_f32m1(v1, 0.0, v1, vl);
}

vfloat32m1_t shortcut_for_riscv_vfmsub_case_1(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfmsub_vf_f32m1(v1, -0.0, v1, vl);
}

/* vfnmsub */
vfloat32m1_t shortcut_for_riscv_vfnmsub_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfnmsub_vf_f32m1(v1, 0.0, v1, vl);
}

vfloat32m1_t shortcut_for_riscv_vfnmsub_case_1(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfnmsub_vf_f32m1(v1, -0.0, v1, vl);
}

/* vfwmacc */
vfloat64m2_t shortcut_for_riscv_vfwmacc_case_0(vfloat64m2_t v1, vfloat32m1_t v2,
                                               size_t vl) {
  return __riscv_vfwmacc_vf_f64m2(v1, 0.0, v2, vl);
}

vfloat64m2_t shortcut_for_riscv_vfwmacc_case_1(vfloat64m2_t v1, vfloat32m1_t v2,
                                               size_t vl) {
  return __riscv_vfwmacc_vf_f64m2(v1, -0.0, v2, vl);
}

/* vfwnmacc */
vfloat64m2_t shortcut_for_riscv_vfwnmacc_case_0(vfloat64m2_t v1,
                                                vfloat32m1_t v2, size_t vl) {
  return __riscv_vfwnmacc_vf_f64m2(v1, 0.0, v2, vl);
}

vfloat64m2_t shortcut_for_riscv_vfwnmacc_case_1(vfloat64m2_t v1,
                                                vfloat32m1_t v2, size_t vl) {
  return __riscv_vfwnmacc_vf_f64m2(v1, -0.0, v2, vl);
}

/* vfwmsac */
vfloat64m2_t shortcut_for_riscv_vfwmsac_case_0(vfloat64m2_t v1, vfloat32m1_t v2,
                                               size_t vl) {
  return __riscv_vfwmsac_vf_f64m2(v1, 0.0, v2, vl);
}

vfloat64m2_t shortcut_for_riscv_vfwmsac_case_1(vfloat64m2_t v1, vfloat32m1_t v2,
                                               size_t vl) {
  return __riscv_vfwmsac_vf_f64m2(v1, -0.0, v2, vl);
}

/* vfwnmsac */
vfloat64m2_t shortcut_for_riscv_vfwnmsac_case_0(vfloat64m2_t v1,
                                                vfloat32m1_t v2, size_t vl) {
  return __riscv_vfwnmsac_vf_f64m2(v1, 0.0, v2, vl);
}

vfloat64m2_t shortcut_for_riscv_vfwnmsac_case_1(vfloat64m2_t v1,
                                                vfloat32m1_t v2, size_t vl) {
  return __riscv_vfwnmsac_vf_f64m2(v1, -0.0, v2, vl);
}

/* vfmin */
vfloat32m1_t shortcut_for_riscv_vfmin_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfmin_vv_f32m1(v1, v1, vl);
}

vfloat32m1_t shortcut_for_riscv_vfmin_case_1(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfmin_vf_f32m1(v1, INFINITY, vl);
}

/* vfmax */
vfloat32m1_t shortcut_for_riscv_vfmax_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfmax_vv_f32m1(v1, v1, vl);
}

vfloat32m1_t shortcut_for_riscv_vfmax_case_1(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfmax_vf_f32m1(v1, -INFINITY, vl);
}

/* vfsgnj */
vfloat32m1_t shortcut_for_riscv_vfsgnj_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfsgnj_vv_f32m1(v1, v1, vl);
}

/* vfsgnjn */
vfloat32m1_t shortcut_for_riscv_vfsgnjn_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfsgnjn_vv_f32m1(v1, v1, vl);
}

/* vfsgnjx */
vfloat32m1_t shortcut_for_riscv_vfsgnjx_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vfsgnjx_vv_f32m1(v1, v1, vl);
}

/* vmfeq */
vbool32_t shortcut_for_riscv_vmfeq_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vmfeq_vv_f32m1_b32(v1, v1, vl);
}

/* vmfne */
vbool32_t shortcut_for_riscv_vmfne_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vmfne_vv_f32m1_b32(v1, v1, vl);
}

/* vmflt */
vbool32_t shortcut_for_riscv_vmflt_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vmflt_vv_f32m1_b32(v1, v1, vl);
}

/* vmfle */
vbool32_t shortcut_for_riscv_vmfle_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vmfle_vv_f32m1_b32(v1, v1, vl);
}

/* vmfgt */
vbool32_t shortcut_for_riscv_vmfgt_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vmfgt_vv_f32m1_b32(v1, v1, vl);
}

/* vmfge */
vbool32_t shortcut_for_riscv_vmfge_case_0(vfloat32m1_t v1, size_t vl) {
  return __riscv_vmfge_vv_f32m1_b32(v1, v1, vl);
}

/* vfmv */
vfloat32m1_t shortcut_for_riscv_vfmv_case_0(size_t vl) {
  return __riscv_vfmv_v_f_f32m1(0.0, vl);
}

vfloat32m1_t shortcut_for_riscv_vfmv_case_1(size_t vl) {
  return __riscv_vfmv_v_f_f32m1(-0.0, vl);
}

/* vmand */
vbool32_t shortcut_for_riscv_vmand_case_0(vbool32_t v1, size_t vl) {
  return __riscv_vmand_mm_b32(v1, v1, vl);
}

/* vmnand */
vbool32_t shortcut_for_riscv_vmnand_case_0(vbool32_t v1, size_t vl) {
  return __riscv_vmnand_mm_b32(v1, v1, vl);
}

/* vmandn */
vbool32_t shortcut_for_riscv_vmandn_case_0(vbool32_t v1, size_t vl) {
  return __riscv_vmandn_mm_b32(v1, v1, vl);
}

/* vmxor */
vbool32_t shortcut_for_riscv_vmxor_case_0(vbool32_t v1, size_t vl) {
  return __riscv_vmxor_mm_b32(v1, v1, vl);
}

/* vmor */
vbool32_t shortcut_for_riscv_vmor_case_0(vbool32_t v1, size_t vl) {
  return __riscv_vmor_mm_b32(v1, v1, vl);
}

/* vmnor */
vbool32_t shortcut_for_riscv_vmnor_case_0(vbool32_t v1, size_t vl) {
  return __riscv_vmnor_mm_b32(v1, v1, vl);
}

/* vmorn */
vbool32_t shortcut_for_riscv_vmorn_case_0(vbool32_t v1, size_t vl) {
  return __riscv_vmorn_mm_b32(v1, v1, vl);
}

/* vmxnor */
vbool32_t shortcut_for_riscv_vmxnor_case_0(vbool32_t v1, size_t vl) {
  return __riscv_vmxnor_mm_b32(v1, v1, vl);
}

/* vmv(permuatation) */
vint32m1_t shortcut_for_riscv_vmv_case_1(size_t vl) {
  return __riscv_vmv_s_x_i32m1(0, vl);
}

/* vslideup */
vint32m1_t shortcut_for_riscv_vslideup_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vslideup_vx_i32m1(v1, v1, 0, vl);
}

/* vslidedown */
vint32m1_t shortcut_for_riscv_vslidedown_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vslidedown_vx_i32m1(v1, 0, vl);
}

/* vrgather */
vint32m1_t shortcut_for_riscv_vrgather_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vrgather_vx_i32m1(v1, 0, vl);
}
