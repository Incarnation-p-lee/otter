[TOC]

# GNU RVV Intrinsic API Shortcut

## Integer Arithmetic

### `VSLL`

#### Sample Code

```c
vuint32m1_t shortcut_for_riscv_vsll_case_1(vuint32m1_t v1, size_t vl) {
  return __riscv_vsll_vx_u32m1(v1, 0, vl);
}
```

#### Current Code Generation

```assembly
vl1re32.v v24, 0(a1)
vsetvli zero, a2, e32,m1,ta,ma
vsll.vi v24, v24, 0
vs1r.v  v24, 0(a0)
ret
```

#### Possible Optimization

```assembly
vl1re32.v v24, 0(a1)
vsetvli zero, a2, e32,m1,ta,ma
vmv.v.v v24, v24    # <== vsll.vi v24, v24, 0
vs1r.v  v24, 0(a0)
ret
```

#### Patch

* [Placeholder]().

## Fixed Point Arithmetic

## Float Point

## Reduction

## Mask

## Permutation

