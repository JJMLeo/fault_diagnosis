#ifndef __c6_GTF_EnginePath_TwoSpool_h__
#define __c6_GTF_EnginePath_TwoSpool_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_sBa2ou9sFCIEvqqnq4mGCgH
#define struct_sBa2ou9sFCIEvqqnq4mGCgH

struct sBa2ou9sFCIEvqqnq4mGCgH
{
  real_T breaks[15];
  real_T coefs[840];
};

#endif                                 /*struct_sBa2ou9sFCIEvqqnq4mGCgH*/

#ifndef typedef_c6_sBa2ou9sFCIEvqqnq4mGCgH
#define typedef_c6_sBa2ou9sFCIEvqqnq4mGCgH

typedef struct sBa2ou9sFCIEvqqnq4mGCgH c6_sBa2ou9sFCIEvqqnq4mGCgH;

#endif                                 /*typedef_c6_sBa2ou9sFCIEvqqnq4mGCgH*/

#ifndef struct_stVqs9TyzBMV0s0DmfB5u9G
#define struct_stVqs9TyzBMV0s0DmfB5u9G

struct stVqs9TyzBMV0s0DmfB5u9G
{
  real_T breaks[15];
  real_T coefs[56];
};

#endif                                 /*struct_stVqs9TyzBMV0s0DmfB5u9G*/

#ifndef typedef_c6_stVqs9TyzBMV0s0DmfB5u9G
#define typedef_c6_stVqs9TyzBMV0s0DmfB5u9G

typedef struct stVqs9TyzBMV0s0DmfB5u9G c6_stVqs9TyzBMV0s0DmfB5u9G;

#endif                                 /*typedef_c6_stVqs9TyzBMV0s0DmfB5u9G*/

#ifndef typedef_SFc6_GTF_EnginePath_TwoSpoolInstanceStruct
#define typedef_SFc6_GTF_EnginePath_TwoSpoolInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c6_sfEvent;
  boolean_T c6_isStable;
  boolean_T c6_doneDoubleBufferReInit;
  uint8_T c6_is_active_c6_GTF_EnginePath_TwoSpool;
  real_T *c6_Pt3;
  real_T *c6_Hu;
  real_T *c6_Tt3;
  real_T *c6_Wf;
  real_T *c6_Tt4;
  real_T *c6_W3;
  real_T *c6_h4;
  real_T *c6_Sfcn4;
} SFc6_GTF_EnginePath_TwoSpoolInstanceStruct;

#endif                                 /*typedef_SFc6_GTF_EnginePath_TwoSpoolInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c6_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[]);
extern void c6_GTF_EnginePath_TwoSpool_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
