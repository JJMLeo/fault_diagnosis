#ifndef __c9_TSE_Path_h__
#define __c9_TSE_Path_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc9_TSE_PathInstanceStruct
#define typedef_SFc9_TSE_PathInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  boolean_T c9_isStable;
  boolean_T c9_doneDoubleBufferReInit;
  uint8_T c9_is_active_c9_TSE_Path;
  real_T *c9_PowerC;
  real_T *c9_Wa3;
  real_T *c9_Wa2;
  real_T *c9_Deflate;
  real_T *c9_h25;
  real_T *c9_h3;
  real_T *c9_h2;
  real_T *c9_T3s;
} SFc9_TSE_PathInstanceStruct;

#endif                                 /*typedef_SFc9_TSE_PathInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c9_TSE_Path_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c9_TSE_Path_get_check_sum(mxArray *plhs[]);
extern void c9_TSE_Path_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
