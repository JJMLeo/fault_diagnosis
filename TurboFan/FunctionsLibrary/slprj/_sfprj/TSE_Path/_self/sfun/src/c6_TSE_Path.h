#ifndef __c6_TSE_Path_h__
#define __c6_TSE_Path_h__

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

#ifndef typedef_SFc6_TSE_PathInstanceStruct
#define typedef_SFc6_TSE_PathInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c6_sfEvent;
  boolean_T c6_isStable;
  boolean_T c6_doneDoubleBufferReInit;
  uint8_T c6_is_active_c6_TSE_Path;
  real_T *c6_P3s;
  real_T *c6_Hu;
  real_T *c6_T3s;
  real_T *c6_Wf;
  real_T *c6_T4s;
  real_T *c6_Wa3;
  real_T *c6_h4;
  real_T *c6_Sfcn4;
} SFc6_TSE_PathInstanceStruct;

#endif                                 /*typedef_SFc6_TSE_PathInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_TSE_Path_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_TSE_Path_get_check_sum(mxArray *plhs[]);
extern void c6_TSE_Path_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
