tor((__v4sf)__a, (__v4sf)__b, 6, 7, 2, 3);
}

/// Constructs a 128-bit floating-point vector of [4 x float]. The lower
///    64 bits are set to the lower 64 bits of the first parameter. The upper
///    64 bits are set to the lower 64 bits of the second parameter.
///
/// \headerfile <x86intrin.h>
///
/// This intrinsic corresponds to the <c> VUNPCKLPD / UNPCKLPD </c> instruction.
///
/// \param __a
///    A 128-bit floating-point vector of [4 x float]. The lower 64 bits are
///    written to the lower 64 bits of the result.
/// \param __b
///    A 128-bit floating-point vector of [4 x float]. The lower 64 bits are
///    written to the upper 64 bits of the result.
/// \returns A 128-bit floating-point vector of [4 x float].
static __inline__ __m128 __DEFAULT_FN_ATTRS
_mm_movelh_ps(__m128 __a, __m128 __b)
{
  return __builtin_shufflevector((__v4sf)__a, (__v4sf)__b, 0, 1, 4, 5);
}

/// Converts a 64-bit vector of [4 x i16] into a 128-bit vector of [4 x
///    float].
///
/// \headerfile <x86intrin.h>
///
/// This intrinsic corresponds to the <c> CVTPI2PS + COMPOSITE </c> instruction.
///
/// \param __a
///    A 64-bit vector of [4 x i16]. The elements of the destination are copied
///    from the corresponding elements in this operand.
/// \returns A 128-bit vector