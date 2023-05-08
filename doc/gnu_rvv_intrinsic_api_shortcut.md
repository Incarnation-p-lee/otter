# GNU RVV Intrinsic API Shortcut

## Integer Arithmetic

### [N] `VSLL`

#### Sample Code

```c
vuint32m1_t shortcut_for_riscv_vsll_case_1(vuint32m1_t v1, size_t vl) {
  return __riscv_vsll_vx_u32m1(v1, 0, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vl1re32.v v24, 0(a1)
vsetvli zero, a2, e32,m1,ta,ma
vsll.vi v24, v24, 0           # <== vmv.v.v v24, v24
vs1r.v  v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

* [x] Kind of corner case and we will defer this optimization after synced with the community,  `VSRL` likewise.

### [Y] `VMSEQ`

#### Sample Code

```c
vbool32_t shortcut_for_riscv_vmseq_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vmseq_vv_i32m1_b32(v1, v1, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vsetvli   zero,a2,e32,m1,ta,ma
vl1re32.v v24, 0(a1)
vmseq.vv  v24,v24,v24              # <== vmset.m v24
vsetvli   a5, zero, e8, mf4, ta, ma
vsm.v     v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

* [x] Completed the Patch.

### [Y] `VMSNE`

#### Sample Code

```c
vbool32_t shortcut_for_riscv_vmsne_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vmsne_vv_i32m1_b32(v1, v1, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vsetvli   zero, a2, e32, m1, ta, ma
vl1re32.v v24,0(a1)
vmsne.vv  v24, v24, v24            # <== vmclr.m v24
vsetvli   a5, zero, e8, mf4, ta, ma
vsm.v     v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

* [x] Completed the Patch.

### [Y] `VMSLTU`

#### Sample Code

```c
vbool32_t shortcut_for_riscv_vmsltu_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vmsltu_vv_u32m1_b32(v1, v1, vl);
}

vbool32_t shortcut_for_riscv_vmsltu_case_1(vuint32m1_t v1, size_t vl) {
  return __riscv_vmsltu_vx_u32m1_b32(v1, 0, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vsetvli   zero, a2, e32, m1, ta, ma
vl1re32.v v24, 0(a1)
vmsltu.vv v24, v24, v24            # <== vmclr.m v24
vsetvli   a5, zero, e8, mf4, ta, ma
vsm.v     v24, 0(a0)
ret
-----------------------------------
vsetvli   zero, a2, e32, m1, ta, ma
vl1re32.v v24, 0(a1)
vmsltu.vi v24, v24, 0              # <== vmclr.m v24
vsetvli   a5, zero, e8, mf4, ta, ma
vsm.v     v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

* [x] Completed the Patch for VMSLTU(v, v)

### [Y] `VMSLT`

#### Sample Code

```c
vbool32_t shortcut_for_riscv_vmslt_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vmslt_vv_i32m1_b32(v1, v1, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vsetvli   zero, a2, e32, m1, ta, ma
vl1re32.v v24, 0(a1)
vmslt.vv  v24, v24, v24            # <== vmclr.m v24
vsetvli   a5, zero, e8, mf4, ta, ma
vsm.v     v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

* [x] Completed the Patch.

### [Y] `VMSLEU`

#### Sample Code

```c
vbool32_t shortcut_for_riscv_vmsleu_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vmsleu_vv_u32m1_b32(v1, v1, vl);
}

vbool32_t shortcut_for_riscv_vmsleu_case_1(vuint32m1_t v1, size_t vl) {
  return __riscv_vmsleu_vx_u32m1_b32(v1, 0, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vsetvli   zero, a2, e32, m1, ta, ma
vl1re32.v v24, 0(a1)
vmsleu.vv v24, v24, v24            # <== vmset.m v24
vsetvli   a5, zero, e8, mf4, ta, ma
vsm.v     v24, 0(a0)
ret
-----------------------------------
vsetvli   zero,a2,e32,m1,ta,ma
vl1re32.v v24, 0(a1)
vmsleu.vi v24, v24, 0              # <== vmset.m v24
vsetvli   a5, zero, e8, mf4, ta, ma
vsm.v     v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

* [x] Completed the Patch for VMSLEU(v, v).

### [Y] `VMSLE`

#### Sample Code

```c
vbool32_t shortcut_for_riscv_vmsle_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vmsle_vv_i32m1_b32(v1, v1, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vsetvli    zero, a2, e32, m1, ta, ma
vl1re32.v  v24, 0(a1)
vmsle.vv   v24, v24, v24            # <== vclr.m v24
vsetvli    a5, zero, e8, mf4, ta, ma
vsm.v      v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

* [x] Completed the Patch.

### `VMSGTU`

#### Sample Code

```c
vbool32_t shortcut_for_riscv_vmsgtu_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vmsgtu_vv_u32m1_b32(v1, v1, vl);
}

vbool32_t shortcut_for_riscv_vmsgtu_case_1(vuint32m1_t v1, size_t vl) {
  return __riscv_vmsgtu_vx_u32m1_b32(v1, 0, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vsetvli   zero, a2, e32, m1, ta, ma
vl1re32.v v24, 0(a1)
vmsgtu.vv v24, v24, v24            # <== vmclr.m v24
vsetvli   a5, zero, e8, mf4, ta, ma
vsm.v     v24, 0(a0)
ret
-----------------------------------
vsetvli   zero, a2, e32, m1, ta, ma
vl1re32.v v24, 0(a1)
vmsgtu.vi v24, v24, 0              # <== vmclr.m v24
vsetvli   a5, zero, e8, mf4, ta, ma
vsm.v     v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

* [x] Completed the Patch for VMSGTU(v, v)

### [Y] `VMSGT`

#### Sample Code

```c
vbool32_t shortcut_for_riscv_vmsgt_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vmsgt_vv_i32m1_b32(v1, v1, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vsetvli   zero, a2, e32, m1, ta, ma
vl1re32.v v24, 0(a1)
vmsgt.vv  v24, v24, v24            # <== vmclr.m v24
vsetvli   a5, zero, e8, mf4, ta, ma
vsm.v     v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

* [x] Completed the Patch.

### [N] `VMAXU`

#### Sample Code

```c
vuint32m1_t shortcut_for_riscv_vmaxu_case_1(vuint32m1_t v1, size_t vl) {
  return __riscv_vmaxu_vx_u32m1(v1, 0, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vl1re32.v v24, 0(a1)
vsetvli   zero, a2, e32, m1, ta, ma
vmaxu.vx  v24, v24, zero           # <== vmv.vv v24, v24
vs1r.v    v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

It looks like there is no obvious benefits when for this optimization. `vmaxu v24, v24, zero` => `vmv.vv v24, v24` doesn't save any resources like vector register. However, we can add some test cases here.

### [?] `VMULH`

#### Sample Code

```c
vint32m1_t shortcut_for_riscv_vmulh_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vmulh_vx_i32m1(v1, 0, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vl1re32.v v24, 0(a1)
vsetvli   zero, a2, e32, m1, ta, ma
vmulh.vx  v24, v24, zero           # <== vmv.vi v24, 0
vs1r.v    v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

### [?] `VMULHU`

#### Sample Code

```c
vuint32m1_t shortcut_for_riscv_vmulhu_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vmulhu_vx_u32m1(v1, 0, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vl1re32.v v24,0(a1)
vsetvli   zero, a2, e32, m1, ta, ma
vmulhu.vx v24, v24, zero           # <== vmv.vi v23, 0
vs1r.v    v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

### [?] `VMULHSU`

#### Sample Code

```c
vint32m1_t shortcut_for_riscv_vmulhsu_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vmulhsu_vx_i32m1(v1, 0, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vl1re32.v  v24, 0(a1)
vsetvli    zero, a2, e32, m1, ta, ma
vmulhsu.vx v24, v24, zero           # <== vmv.vi v24, 0
vs1r.v     v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

### [N] `VDIVU`

#### Sample Code

```c
vuint32m1_t shortcut_for_riscv_vdivu_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vdivu_vv_u32m1(v1, v1, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vl1re32.v  v24, 0(a1)
vsetvli    zero, a2, e32, m1, ta, ma
vdivu.vv   v24, v24, v24            # <== vmv.vi v24, 1
vs1r.v     v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

* [x] Cannot perform this optimization due to there may be 0 in v24.

### [N] `VDIV`

#### Sample Code

```c
vint32m1_t shortcut_for_riscv_vdiv_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vdiv_vv_i32m1(v1, v1, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vl1re32.v  v24, 0(a1)
vsetvli    zero, a2, e32, m1, ta, ma
vdiv.vv    v24, v24, v24            # <== vmv.vi v24, 1
vs1r.v     v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

* [x] Cannot perform this optimization due to there may be 0 in v24.

### [N] `VREMU`

#### Sample Code

```c
vuint32m1_t shortcut_for_riscv_vremu_case_0(vuint32m1_t v1, size_t vl) {
  return __riscv_vremu_vv_u32m1(v1, v1, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vl1re32.v  v24, 0(a1)
vsetvli    zero, a2, e32, m1, ta, ma
vremu.vv   v24, v24, v24            # <== vmv.vi v24, 0
vs1r.v     v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

* [x] Cannot perform this optimization due to there may be 0 in v24.

### [N] `VREM`

#### Sample Code

```c
vint32m1_t shortcut_for_riscv_vrem_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vrem_vv_i32m1(v1, v1, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vl1re32.v  v24, 0(a1)
vsetvli    zero, a2, e32, m1, ta, ma
vrem.vv    v24, v24, v24            # <== vmv.vi v24, 0
vs1r.v     v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

* [x] Cannot perform this optimization due to there may be 0 in v24.

### [?] `VMERGE`

#### Sample Code

```c
vint32m1_t shortcut_for_riscv_vmerge_case_0(vint32m1_t v1, vbool32_t mask, size_t vl) {
  return __riscv_vmerge_vvm_i32m1(v1, v1, mask, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vsetvli    a5, zero, e8, mf4, ta, ma
vl1re32.v  v24,0(a1)
vlm.v      v0, 0(a2)
vsetvli    zero, a3, e32, m1, ta, ma
vmerge.vvm v24, v24, v24, v0        # <== vmv.vv v24, v24
vs1r.v     v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

### [?] `VSSUBU`

#### Sample Code

```c
vuint32m1_t shortcut_for_riscv_vssubu_case_1(vuint32m1_t v1, size_t vl) {
  return __riscv_vssubu_vv_u32m1(v1, v1, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vl1re32.v  v24, 0(a1)
vsetvli    zero, a2, e32, m1, ta, ma
vssubu.vv  v24, v24, v24            # <== vmv.vi v24, 0
vs1r.v     v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

### [?] `VSSUB`

#### Sample Code

```c
vint32m1_t shortcut_for_riscv_vssub_case_1(vint32m1_t v1, size_t vl) {
  return __riscv_vssub_vv_i32m1(v1, v1, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vl1re32.v  v24, 0(a1)
vsetvli    zero, a2, e32, m1, ta, ma
vssub.vv   v24, v24, v24            # <== vmv.vi v24, 0
vs1r.v     v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

### [?] `VAADDU`

#### Sample Code

```c
vuint32m1_t shortcut_for_riscv_vaaddu_case_1(vuint32m1_t v1, size_t vl) {
  return __riscv_vaaddu_vv_u32m1(v1, v1, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vl1re32.v  v24, 0(a1)
vsetvli    zero, a2, e32, m1, ta, ma
vaaddu.vv  v24, v24, v24            # <== vmv.vv v24, v24 
vs1r.v     v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

### [?] `VAADD`

#### Sample Code

```c
vint32m1_t shortcut_for_riscv_vaadd_case_1(vint32m1_t v1, size_t vl) {
  return __riscv_vaadd_vv_i32m1(v1, v1, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vl1re32.v  v24,0(a1)
vsetvli    zero, a2, e32, m1, ta, ma
vaadd.vv   v24, v24, v24            # <== vmv.vv v24, v24
vs1r.v     v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

### [?] `VASUBU`

#### Sample Code

```c
vuint32m1_t shortcut_for_riscv_vasubu_case_1(vuint32m1_t v1, size_t vl) {
  return __riscv_vasubu_vv_u32m1(v1, v1, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vl1re32.v  v24, 0(a1)
vsetvli    zero, a2, e32, m1, ta, ma
vasubu.vv  v24, v24, v24            # <== vmv.vi v24, 0
vs1r.v     v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

### [?] `VASUB`

#### Sample Code

```c
vint32m1_t shortcut_for_riscv_vasub_case_1(vint32m1_t v1, size_t vl) {
  return __riscv_vasub_vv_i32m1(v1, v1, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vl1re32.v  v24, 0(a1)
vsetvli    zero, a2, e32, m1, ta, ma
vasub.vv   v24, v24, v24            # <== vmv.vi v24, 0
vs1r.v     v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

### [?] `VSMUL`

#### Sample Code

```c
vint32m1_t shortcut_for_riscv_vsmul_case_0(vint32m1_t v1, size_t vl) {
  return __riscv_vsmul_vx_i32m1(v1, 0, vl);
}
```

#### Current Code Generation and Possible Optimization

```assembly
vl1re32.v v24,0(a1)
vsetvli   zero, a2, e32, m1, ta, ma
vsmul.vx  v24, v24, zero           # <== vmv.vi v24, 0
vs1r.v    v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

#### Conclusion

## Fixed Point Arithmetic

## Float Point

## Reduction

## Mask

## Permutation

